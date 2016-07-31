#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forsn(i,s,n) for(int i=s;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)(n-1);i>=0;i--)

#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void dfs(int i, vector<vi> &graf, vb &visit, stack<int> &S){
	visit[i] = true;
	for(auto adj : graf[i]){
		if(!visit[adj]) dfs(adj, graf, visit, S);
	}
	S.push(i);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int T; cin >> T;
	while(T--){
		int N, M; cin >> N >> M;
		vector<vi> graf(N, vi());
		vector<vi> grafInv(N, vi());
		forn(i,M){
			int u, v; cin >> u >> v; u--; v--;
			graf[u].pb(v);
			grafInv[v].pb(u);
		}
		
		// 1 dfs
		vb visit(N, false);
		stack<int> S;
		forn(i,N){
			if(!visit[i]) dfs(i, graf, visit, S);
		}
		//
		int CC = 0;
		vi comps(N, -1);
		
		// 2 dfs
		vb visitInv(N, false);
		while(!S.empty()){
			int i = S.top(); S.pop();
			if(!visitInv[i]){
				stack<int> Si;
				dfs(i, grafInv, visitInv, Si);
				while(!Si.empty()){
					int c = Si.top(); Si.pop();
					comps[c] = CC;
				}
				CC++;
			}
		}
		
		// sobre aristas
		vi gradSal(CC), gradEnt(CC);
		forn(i,N){
			for(auto j : graf[i]){
				if(comps[i] != comps[j]){
					gradSal[comps[i]]++;
					gradEnt[comps[j]]++;
				}
			}
		}
		
		// sin conectar
		int cantSal = 0;
		int cantEnt = 0;
		forn(i,gradSal.size()){
			if(gradSal[i] == 0) cantSal++;
		}
		forn(i,gradEnt.size()){
			if(gradEnt[i] == 0) cantEnt++;
		}
		
		// resultado
		if(CC == 1){
			cout << 0 << "\n";
		}else{
			int res = 0;
			res = max(cantSal, cantEnt);
			cout << res << "\n";
		}
	}
	return 0;
}
