#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define forsn(i,s,n) for (int i = (s); i <(int) (n); i++)
#define forn(i,n) for (int i = 0; i <(int) (n); i++)
#define dforn(i,n) for (int i = (int)(n)-1; i >=0; i--)

typedef map<int, set<int> > mapita;

#define MAXN 16384
struct rmq {
	int MAX;
	int vec[4*MAXN];
	
	int* init(int n) {
		MAX = 1 << (32-__builtin_clz(n));
		fill(vec, vec+2*MAX, 0); // 0 = elemento neutro
		return vec+MAX;
	}
	
	void updall() { dforn(i, MAX) vec[i] = max(vec[2*i] , vec[2*i+1]); } // max = operacion
	
	void pset(int i, int vl) {
		vec[i+=MAX] = vl;
		while(i) { i /= 2; vec[i] = max(vec[2*i] , vec[2*i+1]); } // max = operacion
	}
	
	int pget(int i, int j) { return _pget(i+MAX, j+MAX); }

	int _pget(int i, int j) {
		int res = 0;
		// 0 = elemento neutro
		if (j-i <= 0) return res;
		if (i %2) res = max(res , vec[i++]); // max = operacin
		res = max(res , _pget(i/2, j/2)); // max = operacin
		if (j %2) res = max(res , vec[--j]); // + = operacin
		return res;
	}
};

int main(){

	int N, R; cin >> N >> R;
	
	mapita arbolines;
	
	//vector<int> arbs(N);
	vector<int> arbsIdx(N);
	
	rmq* RMQ = new rmq();
	int* arbs = RMQ->init(N);
	
	forn(i,N){
		// armar base
		int arbi; cin >> arbi;
		mapita::iterator arbit = arbolines.find(arbi);
		
		arbsIdx[i] = arbi;
		
		if(arbit == arbolines.end()){	// not found
			set<int> s; s.insert(i+1);
			arbolines.insert(make_pair(arbi, s));
			arbs[i] = 0;
		}else{	// found
			// look for previous index
			int arbult = *arbit->second.rbegin();
			arbit->second.insert(i+1);
			arbs[i] = arbult;
		}
	}
	
	// RMQ update all !
	RMQ->updall();
	
	/*
	forn(i,N){
		cout << arbs[i] << " ";
	}cout << endl;
	*/
	
	// queries
	forn(i,R){
		char q; cin >> q;
		if(q == 'C'){		// change tree
			int k, sNueva; 
			cin >> k >> sNueva;
			
			int sVieja = arbsIdx[k-1];
			arbsIdx[k-1] = sNueva;
			int repetVieja = arbs[k-1];
			
			/// con la especie vieja
			mapita::iterator itMap = arbolines.find(sVieja);
			
			// busco primero de la especia vieja que venga despues 
			// de la posicion que acaba de ser cambiada			
			set<int>::iterator itSet = itMap->second.upper_bound(k);
			if(itSet != itMap->second.end()){
				//arbs[*itSet-1] = repetVieja;
				RMQ->pset(*itSet-1, repetVieja);
			}
			
			// borro la posicion del arbol caido del set de sVieja
			itMap->second.erase(k);
			
			/// con la especia nueva
			mapita::iterator itMapN = arbolines.find(sNueva);
			
			if(itMapN != arbolines.end()){		// nueva especie existente
				// agrego la posicion del arbol nuevo al set de sNueva
				itMapN->second.insert(k);
				
				// busco primero de la especie nueva que venga despues
				// de la posicion que acaba de ser cambiada
				set<int>::iterator itSetN = itMapN->second.upper_bound(k);
				if(itSetN != itMapN->second.end()){
					//arbs[*itSetN-1] = k;
					RMQ->pset(*itSetN-1, k);
				}
				
				// busco primero de la especia nueva que venga antes 
				// de la posicion que acaba de ser cambiada
				set<int>::iterator itSetNant = itMapN->second.lower_bound(k);
				if(itSetNant != itMapN->second.begin()){
					itSetNant--;
					//arbs[k-1] = *itSetNant;
					RMQ->pset(k-1, *itSetNant);
				}else{
					//arbs[k-1] = 0;
					RMQ->pset(k-1, 0);
				}
			}else{		// nueva especie no existente
				set<int> s; s.insert(k);
				arbolines.insert(make_pair(sNueva, s));
				//arbs[k-1] = 0;
				RMQ->pset(k-1, 0);
			}
			
		}else if(q == 'E'){	// train
			int k; cin >> k;
			
			int maxRmq = RMQ->pget(0, k);
			
			cout << k - maxRmq << endl;
			
		}
		/*
		forn(j,N){
			cout << arbsIdx[j] << " ";
		}cout << endl;
		
		forn(j,N){
			cout << arbs[j] << " ";
		}cout << endl;
		*/
	}
	
	return 0;
}
