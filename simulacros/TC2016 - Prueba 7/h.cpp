#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define forsn(i,s,n) for(int i=(int)s; i<(int)n; i++)
#define pb push_back

typedef long long tint;
typedef vector<tint> vi;

const tint NMOD = 1000000000;

int TIME  = 0;

void dfs(int u, vector<vi> &graf, vi &visit, bool &ciclo, vi &topo, vi& low){
	visit[u] = 1;
	low[u] = TIME++;
	for(auto &v : graf[u]){

		if(visit[v] == 0){
			dfs(v, graf, visit, ciclo, topo, low);
			if(low[v] <= low[u]) 
				if(visit[v] == 1){ 
					ciclo = true;
				}
			low[u] = min(low[u], low[v]);
		}
	}
	visit[u] = 2;
	topo.pb(u);
}


int main(){
	tint N, M; 
	scanf("%Ld %Ld", &N, &M);
	vector<vi> graf(N, vi());
	vector<vi> grafInv(N, vi());
	forn(i,M){
		tint u, v; 
		scanf("%Ld %Ld", &u, &v);
		graf[u-1].pb(v-1);
		grafInv[v-1].pb(u-1);
	}
	if(N==1){
		printf("0\n");
	}else{
		// ciclo?
		vi visit(N, 0);
		vi topo;
		vi low(N,-1);
		bool ciclo = false;
		low[0] = 0;
		dfs(0, graf, visit, ciclo, topo, low);
		
		if(ciclo && visit[1] != 0){
			printf("inf\n");
		}else if(visit[1] == 0){
			printf("0\n");
		}else{	// dp
			bool flag = false;
			vi dp(N, 0);
			reverse(topo.begin(), topo.end());
			
			dp[0] = 1;
			forsn(i,1,topo.size()){
				int u = topo[i];
				for(auto &v : grafInv[u]){
					if (dp[u] + dp[v] >= NMOD)
						flag = true;
					dp[u] = (dp[u] + dp[v]) % NMOD;;
				}
			}

			if(flag){
				printf("%09Ld\n", dp[1]);
			}else{
				printf("%Ld\n", dp[1]);
			}
		}
	}
	
	return 0;
}
