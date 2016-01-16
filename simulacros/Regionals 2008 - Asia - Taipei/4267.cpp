#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll dfs(int R, vector<vector<int > > &hijos, vector<ll> &pesos, vector<ll> &pesosSub){
	ll res = 0;
	for(auto &h : hijos[R]){
		res += dfs(h, hijos, pesos, pesosSub);
	}
	pesosSub[R] = res + pesos[R];
	return res + pesos[R];
}

int main(){

	int T;
	cin >> T;
	for(int i=0; i<T; i++){
		int N;
		int R;
		cin >> N >> R;
		
		vector<ll> pesos(N, 0);
		vector<ll> pesosSub(N, 0);
		
		vector<vector<int> > hijos(N, vector<int>());
		for(int n=0; n<N; n++){
			cin >> pesos[n];
			int ci; cin >> ci;
			for(int h=0; h<ci; h++){
				int hi; cin >> hi;
				hijos[n].push_back(hi);
			}
		}
		
		
		ll rta = dfs(R, hijos, pesos, pesosSub);
		//cout << rta << endl;
		
		vector<int> camino;
		ll pesoCamino = 0;
		camino.push_back(R);
		pesoCamino += pesos[R];
		while(hijos[R].size() > 0){
			ll maxPeso = 0;
			int maxH = -1;
			for(auto &h : hijos[R]){
				if(pesosSub[h] > maxPeso){
					maxPeso = pesosSub[h];
					maxH = h;
				}else if(pesosSub[h] == maxPeso && h > maxH){
					maxPeso = pesosSub[h];
					maxH = h;
				}
			}
			R = maxH;
			camino.push_back(R);
			pesoCamino += pesos[R];
		}
		
		cout << pesoCamino << endl;

		for(int c=0; c<(int)camino.size(); c++){
			if(c > 0 && c % 10 == 0) cout << endl;
			
			if(c == (int)camino.size()-1) cout << camino[c];
			
			if(c < (int)camino.size()-1) {
				if(c % 10 == 9) cout << camino[c];
				else cout << camino[c]<< " ";
			}
			
		}
		cout << endl;
	}

	return 0;
}
