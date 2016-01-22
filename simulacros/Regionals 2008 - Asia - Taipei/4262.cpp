#include <vector>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define pb push_back

void dfs(int s, vector<vi> &g, vb &vis, vi &ord){
	vis[s] = true;
	for(auto &ady : g[s]){
		if(!vis[ady]) dfs(ady, g, vis, ord);
	}
	ord.pb(s);
}

int main(){

	int T;
	cin >> T;
	forn(casito,T){
		int N, M;
		cin >> N >> M;
		
		vector<vi> graf(N, vi());
		vector<vi> grafInv(N, vi());
		vb visit(N, false);
		vb visitInv(N, false);
		
		forn(i,M){
			int u, v; cin >> u >> v; u--; v--;
			graf[u].pb(v);
			grafInv[v].pb(u);
		}
		int a; cin >> a;
		//
		vi orden;
		forn(i,N){
			if(!visit[i]){
				dfs(i, graf, visit, orden);
			}
		}
		//
		reverse(orden.begin(), orden.end());
		int CC = 0;
		for(auto &nod : orden){
			if(!visitInv[nod]){
				vi ord;
				CC++;
				dfs(nod, grafInv, visitInv, ord);
			}
		}
		cout << CC << endl;
	}

	return 0;
}
