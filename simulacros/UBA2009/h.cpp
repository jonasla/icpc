#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n);i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int) (n);i++)

#define MAXN 1000000005
//#define MAXN 100000
#define pb push_back

typedef unsigned long long utint;
typedef long long tint;
typedef unsigned int uint;
typedef vector<uint> vui;

typedef pair<utint, utint> pui;

bool p[MAXN];
uint arrPrimos[51000000];

// MAX UNSIGNED INT 4294967295 > 10^9

uint CANTPRIMOS;

utint mipow(utint n, int power){
	utint response=1;
	forn(i,power) response*=n;
	return response;
}

vui criba(){
	vui ret;
	ret.pb(2);
	//ret.pb(3);
	
	utint lastI;
	
	//for(utint i=4; i<MAXN; i+=2) p[i] = true;
	
	for(utint i=3; i*i<MAXN; i+=2){
		if(!p[i]){ 
			for(utint j=i*i; j<MAXN; j+=2*i) p[j] = true;
			
			ret.pb(i);
		}
		lastI = i;
	}
	
	for(utint h=lastI; h<MAXN; h+=2){
		if(!p[h]){
			ret.pb(h);
		}
	}
	
	return ret;
}

vui primos(){
	vui ret;
	
	for(int i=2; i<MAXN; i++){
		if(!p[i]) ret.pb(i);
	}
	
	return ret;
}

vector<pui> facts(utint num, vui& prims){
	//vui fs;
	//vui exps(prims.size(), 0);
	vector<pui> laFact;
	
	//for(auto& pr : prims){
	utint Ncopia = num;
	for(unsigned int i=0; i<prims.size(); i++){
		if(prims[i]*prims[i] > Ncopia) break;
		
		utint elExp = 0;
		
		while(Ncopia % prims[i] == 0){
			elExp++;
			Ncopia /= prims[i];
		}
		if(elExp > 0){
			laFact.pb(make_pair(prims[i], elExp));
		}
	}
	/*
	Ncopia = num;
	
	for(unsigned int i=0; i<prims.size(); i++){
		if(prims[i]*prims[i] > Ncopia) break;
		
		if(exps[i] >= 1){ 
			Ncopia /= mipow(prims[i], exps[i]);
			laFact.pb(make_pair(prims[i], exps[i]));
		}
	}
	*/
	if(Ncopia > 1) laFact.pb(make_pair(Ncopia, 1));
	
	return laFact;
}


int main(){
	uint MAXU = -1;
	cout << MAXU << endl;
	
	vui lesPrimos = criba();
	//vui prims = primos();
	
	//cout << lesPrimos.size() << " " << prims.size() << endl;
	cout << lesPrimos.size() << endl;
	
	//cout << "Listo!\n";
	
	/// no se toca ---A arriba
	utint num,cuad,raiz;
	cin >> num;
	
	utint FINPROG = -1;
	
	while(num != FINPROG){
		cuad = 1;
		raiz = 1;
		vector<pui> fs = facts(num, lesPrimos);
		int k = fs.size();
		//forn(i,k) cout << "(" << fs[i].first<<","<<fs[i].second<< ") "; 
		//cout << endl;
		
		forn(i,k){
			if(fs[i].second%2==0)
				cuad*=mipow(fs[i].first,fs[i].second/2);
			else{
				raiz*=fs[i].first;
				cuad*=mipow(fs[i].first,fs[i].second/2);
			}
		}
		cout << cuad << " " << raiz << endl;
		cin >> num;
	}
	return 0;
}


