#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define forn(i,n) for(int i=0;i<n;i++)

typedef long long tint;
typedef vector<int> vi;

void dfs(int i, vector<vi> &graf, vector<bool> &visit, vi &nods){
	visit[i] = true;
	nods.pb(i);
	for(auto adj : graf[i]){
		if(!visit[adj]){
			dfs(adj, graf, visit, nods);
		}
	}
}

tint cantArs(vi &nods, vector<vi> &graf){
	tint res = 0;
	for(auto v : nods){
		res += graf[v].size();
	}
	return res/2;
}

int main(){
	tint N, M, R, E;
	cin >> N >> M >> R >> E;
	vector<vi> graf(N, vi());
	forn(i,M){
		int u, v;
		cin >> u >> v;
		graf[u-1].pb(v-1);
		graf[v-1].pb(u-1);
	}
	
	vector<bool> visit(N, false);
	tint res = 0;
	forn(i,N){
		if(!visit[i]) { 
			vi nods;
			dfs(i, graf, visit, nods);
			tint completo = nods.size()*(nods.size()-1)/2;
			tint falta = completo - cantArs(nods, graf);
			tint rutas = falta*R;
			tint estadios = (tint)(nods.size()) * E;
			res += min(rutas, estadios);
		}
	}
	cout << res << endl;
}
