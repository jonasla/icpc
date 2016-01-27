#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

#define forsn(i,s,n) for (int i = (s); i <(int) (n); i++)
#define forn(i,n) for (int i = 0; i <(int) (n); i++)

#define pb push_back

typedef long long tint;
typedef unsigned long long utint;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 500000000;

void dfs(int s, vector<vi> &arbol, vi &equipo, vector<vi> &dist, vector<vi> &dp, vector<bool> &visit){
	visit[s] = true;
	vi hijos;
	for(auto &ady : arbol[s]){
		if(!visit[ady]){
			hijos.pb(ady);
			dfs(ady, arbol, equipo, dist, dp, visit);
		}
	}
	/// si tengo equipo fijo
	if(equipo[s] != -1){
		int eq = equipo[s];
		int reseq = 0;
		
		for(auto &h : hijos){		// para cada hijo
			int minh = INF;
			if(equipo[h] != -1){		// si tiene equipo fijo, ya esta
				minh = dist[eq][equipo[h]] + dp[h][equipo[h]];
			}else{						// sino, nos quedamos con el minimo entre los equipos
				forn(e,dp[h].size()){
					minh = min(minh, dist[eq][e] + dp[h][e]);
				}
			}
			reseq += minh;
		}
		
		dp[s][eq] = reseq;
	}
	/// si no
	else{
		
		forn(es,dp[s].size()){		// para cada equipo de s
			int reseq = 0;
					
			for(auto &h : hijos){		// para cada hijo
				int minh = INF;
				if(equipo[h] != -1){		// si tiene equipo fijo, ya esta
					minh = dist[es][equipo[h]] + dp[h][equipo[h]];
				}else{						// sino, nos quedamos con el minimo entre los equipos
					forn(eh,dp[h].size()){
						minh = min(minh, dist[es][eh] + dp[h][eh]);
					}
				}
				reseq += minh;
			}
			dp[s][es] = reseq;
		}
		
	}
}

int main(){

	int N, E;
	//while(scanf("%d %d", &N, &E) && N > 0){
	while(cin >> N >> E && N > 0){
		/// disturbios 
		vector<vi> dist(E, vi(E));
		forn(i,E) 
		forn(j,E) cin >> dist[i][j];
		//forn(j,E) scanf("%d", &dist[i][j]); 
		/// equipos 
		vi equipo(N, -1);
		forn(i,E){
			int cant; cin >> cant;
			//int cant; scanf("%d", &cant);
			forn(j,cant){
				int c; cin >> c;
				//int c; scanf("%d", &c);
				c--;
				equipo[c] = i;
			}
		}
		/// arbol
		vector<vi> arbol(N, vi());
		forn(i,N-1){
			int u, v; cin >> u >> v;
			//int u, v; scanf("%d %d", &u, &v);
			u--; v--;
			arbol[u].pb(v);
			arbol[v].pb(u);
		}
		///
		vector<vi> dp(N, vi(E, INF));
		vector<bool> visit(N, false);
		
		dfs(0, arbol, equipo, dist, dp, visit);
		int RES = INF;
		for(auto &r : dp[0]){
			RES = min(RES, r);
		}
		cout << RES << endl;
		//printf("%d\n", RES);
	}
	return 0;
}
