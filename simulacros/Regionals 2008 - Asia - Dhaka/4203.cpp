#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define INF (10000000 + 100)

typedef unsigned long long ull;
typedef vector<ull> Vull;
typedef pair<ull, ull> Pull;

int p[INF];

void criba(){
	for(int i=4; i<INF; i+=2) p[i] = 2;
	
	for(int i=3; i*i<INF; i+=2)
		if(!p[i]) for(int j=i*i; j<INF; j+=2*i) p[j] = i;
}

void printVector(vector<Pull> &v){
	for(unsigned int i=0; i<v.size(); i++){
		if(i) cout << " ";
		cout << "(" << v[i].first << " , " << v[i].second << ")";
	}
	cout << endl;
}

Vull getPrimos(){
	Vull ret;
	for(int i=2; i<INF; i++){
		if(!p[i]) ret.push_back(i);
	}
	
	return ret;
}

ull potencia(ull a, ull b){
	ull ret = 1;
	while(b > 0){
		ret *= a;
		b--;
	}
	return ret;
}

//////

int main(){
	for(int i=0; i<INF; i++){
		p[i] = 0;
	}
	criba();
	Vull vecPrimos = getPrimos();
	
	//
	
	int CASO = 1;
	
	//
	ull N; cin >> N;
	while(N){		
		vector<Pull> factores;
		Vull exponentes(vecPrimos.size(), 0);
		
		ull Ncopia = N;
		for(unsigned int i=0; i<vecPrimos.size(); i++){
			//cout << "Estoy en primo: " << vecPrimos[i] << endl;
			while(Ncopia % vecPrimos[i] == 0){
				//cout << "Divido " << Ncopia << " por " << vecPrimos[i] << endl;
				Ncopia /= vecPrimos[i];
				exponentes[i]++;
			}
			if(vecPrimos[i]*vecPrimos[i] > Ncopia) break;
		}
		
		/// No hace falta esto
		//if(Ncopia == N) factores.push_back(make_pair(Ncopia, 1));
		
		//factores
		Ncopia = N;
		for(unsigned int i=0; i<vecPrimos.size(); i++){
			if(exponentes[i]){
				factores.push_back(make_pair(vecPrimos[i], exponentes[i]));
				Ncopia /= potencia(vecPrimos[i], exponentes[i]);
			}
			if(vecPrimos[i]*vecPrimos[i] > Ncopia) break;
		}
		if(Ncopia > 1) factores.push_back(make_pair(Ncopia, 1));
		//printVector(factores);

		// si no son todos los exponentes 1 O no hay factores (ie. es primo)
		bool posible = false;
		for(unsigned int i=0; i<factores.size(); i++){
			if(factores[i].second != 1){
				posible = true;
				break;
			}
		}
		
		cout << "Case " << CASO << ": ";
		if(!posible){
			 cout << "Impossible\n";
		}else{
			
			ull ret = 1;
			
			for(unsigned int i=0; i<factores.size(); i++){
				factores[i].second = (factores[i].second + 1) / 2;
				
				ret *= potencia(factores[i].first, factores[i].second);
			}
			
			//printVector(factores);
			
			//cout << "Res: " << (ret) << endl;
			cout << ((N / ret)-1)*8 << endl;
			
		}
		
		//
		CASO++;
		cin >> N;
	}
	
	return 0;
}
