#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define sqr(x) (x)*(x)
#define pb push_back

typedef long long tint;
typedef vector<int> vi;

int main(){
	int N, M; cin >> N >> M;
	vector<vi> graf(N, vi());
	vector<vi> grafInv(N, vi());
	//~ vi grado(N, 0);
	forn(i,M){
		int u, v; cin >> u >> v;
		u--; v--;
		graf[u].pb(v);
		grafInv[v].pb(u);
		//~ grado[v]++;
	}
	
	vi orden(N); forn(i,N) {cin >> orden[i]; orden[i]--; }
	vi visit(N, 0);
	vi tocados(N, 0);
	int CANT=0;
	
	for(auto o : orden){
		visit[o] = 1;
		//~ for(auto v : graf[o]) tocados[v]++;
		bool listo = true;
		for(auto y : grafInv[o]) listo &= (visit[y]==2);
		
		if(listo){
			queue<int> Q;
			Q.push(o);
			while(!Q.empty()){
				int v = Q.front(); Q.pop();
				if(visit[v]==2) continue;
				
				CANT++;
				visit[v] = 2;
				for(auto u : graf[v]){
					bool listou = true;
					for(auto y : grafInv[u]) listou &= (visit[y]==2);
					
					if(listou && visit[u]==1){
						Q.push(u);
					}
				}
			}
		}
		cout << CANT << endl;
	}
	return 0;
}
