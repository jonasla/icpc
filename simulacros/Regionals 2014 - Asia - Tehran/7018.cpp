#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long tint;
typedef pair<int,int> ii;

void impr(vector<int> &vec){
	cout << "[" ;
	forn(i,vec.size()){
		if(i) cout << ",";
		cout << vec[i];
	}
	cout << "]\n";
}

void imprII(vector<ii> &vec){
	cout<< "[" ;
	forn(i,vec.size()){
		if(i) cout << ",";
		cout << "(" << vec[i].fi << "," << vec[i].se << ")";
	}
	cout << "]\n";
}

vector<int> bfs(int s, vector<vector<int> > &graf, vector<bool> &visit){
	vector<int> res;
	res.pb(s);
	queue<int> Q; Q.push(s);
	visit[s] = true;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		for(auto &v : graf[u]){
			if(!visit[v]){
				visit[v] = true;
				Q.push(v);
				res.pb(v);
			}
		}
	}
	return res;
}

int main()
{
	int N,M, K;
	while(cin >> N >> M >> K && N != 0){
		vector<vector<int> > graf(N, vector<int>());
		vector<vector<int> > dragonesPorNodo(N, vector<int>());
		
		forn(i,M){
			int u, v; cin >> u >> v;
			u--; v--;
			graf[u].pb(v);
			graf[v].pb(u);
		}
		
		vector<int> dragonesStart(K);
		vector<int> dragonesRegen(K);
		forn(i,K){
			int ci, si, ni; cin >> ci >> si >> ni;
			ci--;
			dragonesPorNodo[ci].pb(i);
			dragonesStart[i] = si;
			dragonesRegen[i] = ni;
		}
		///
		tint TOTAL = 0;
		vector<bool> visit(N, false);
		forn(i,N){
			if(!visit[i]){ 
				vector<int> comp = bfs(i, graf, visit);
				
				vector<ii> ordenDragon;
				for(auto &n : comp){
					for(auto &d : dragonesPorNodo[n]){
						ordenDragon.pb(mp(dragonesRegen[d], dragonesStart[d]));
					}
 				}
 				
 				sort(ordenDragon.begin(), ordenDragon.end());
 				reverse(ordenDragon.begin(), ordenDragon.end());
 				
 				//imprII(ordenDragon);
 				
 				///
				if(ordenDragon.size() == 1){
					int D0 = ordenDragon[0].fi;
					int S0 = ordenDragon[0].se;
					if(D0 >= S0){
						TOTAL += S0;
					}else{
						TOTAL += D0+1;
					}
				}else if(ordenDragon.size() > 1){		// >= 2
					int sumaStart = ordenDragon[0].se;
					int idx = 1;
					
					while(idx < (int)ordenDragon.size() && sumaStart <= ordenDragon[idx].fi){
						sumaStart += ordenDragon[idx].se;
						idx++;
					}
					if(idx == (int)ordenDragon.size()){		// llegue final
						TOTAL += min(sumaStart, ordenDragon[0].fi+1);
					}else{
						TOTAL += min(sumaStart, ordenDragon[idx-1].fi+1);
					}
				}
			}
		}
		
		cout << TOTAL << endl;
	}
	return 0;
}
