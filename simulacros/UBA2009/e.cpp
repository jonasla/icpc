#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<double, pair<int, int> > ari;
typedef vector<ari> vari;
typedef long long tint; 

#define pi 3.141592
#define pb push_back

struct circ{
	tint x, y, r;
};

typedef vector<circ> vcirc;

void printAri(ari& a){
	cout << "[" << a.first << " (" << a.second.first << "," << a.second.second << ")] ";
}

double euclid(circ c1, circ c2){
	return sqrt( (double)((c1.x - c2.x)*(c1.x - c2.x)) + (double)((c1.y - c2.y)*(c1.y - c2.y)) );
}

double distElas(circ c1, circ c2){
	double d = euclid(c1, c2);
	
	double r1 = (double)(c1.r);
	double r2 = (double)(c2.r);
	
	double I = sqrt(d*d - (r2 - r1)*(r2 - r1));
	
	double a2 = 2*(acos( (r1 - r2) / d ));
	double a1 = 2*(acos( (r2 - r1) / d ));
	
	return (2*I + a1*r1 + a2*r2);
}

int padres[3500], prof[3500];

void unionFind(int N){
	for(int i=0; i<N; i++){
		padres[i] = i;
		prof[i] = 0;
	}	
}

int find(int x){
	if(padres[x] == x) return x;
	
	padres[x] = find(padres[x]);
	return padres[x];
}

void join(int x, int y){
	int px = find(x);
	int py = find(y);
	
	if(prof[px] < prof[py]){
		padres[px] = py;
	}else{
		padres[py] = px;
		
		if(prof[px] == prof[py])
			prof[px]++;
	}
}

int main(){
	
	int N; cin >> N;
	while(N != -1){
		vcirc circs;
		
		for(int i=0; i<N; i++){
			int x, y, r; cin >> x >> y >> r;
			circ c; c.x = x; c.y = y; c.r = r;
			
			circs.pb(c);
		}
		//
		vari aristas;
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				double d = distElas(circs[i], circs[j]);
				
				aristas.pb(make_pair(d, make_pair(i, j)));
			}
		}
		
		/// chequeo
		//cout << aristas.size() << endl;
		
		sort(aristas.begin(), aristas.end());
		/*
		for(auto& ars : aristas){
			printAri(ars);
		}cout << endl;
		*/
		//return 0;
		
		//kruskal
		int cantArs = 0;
		double peso = 0;
		
		unionFind(N);
		
		for(auto& ars : aristas){
			if(find(ars.second.first) != find(ars.second.second)){
				//cout << "Meto arista "; printAri(ars); cout << endl;
				peso += ars.first;
				cantArs++;
				
				if(cantArs == N-1){
					//cout << "Llegue arbol!\n"; 
					break; 
				}
				join(ars.second.first, ars.second.second);
			}else{
				//cout << "NO Meto arista "; printAri(ars); cout << endl;
			}
		}
		printf("%.3f\n", peso);
		
		//
		cin >> N;
	}
	
	return 0;
}
