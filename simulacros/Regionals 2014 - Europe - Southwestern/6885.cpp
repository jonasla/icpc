#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define forn(i,n) for(int (i)=0; i<(int)(n); (i)++)
#define forsn(i,s,n) for(int (i)=(s); i<(int)(n); (i)++)
#define mp make_pair
#define pb push_back
const int INF = 1000000000;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void dijk(vector<vii> &graf, int s, vi &dist, vi &padre){
	set<ii> Q;	// (w, ady)
	dist[s] = 0;
	Q.insert(mp(0,s));
	while(!Q.empty()){
		int cur = Q.begin()->second;
		for(auto &ady : graf[cur]){
			int next = ady.first;
			int w = ady.second;
			if(dist[next] > dist[cur] + w){
				if(dist[next] != INF) Q.erase(mp(dist[next], next));
				dist[next] = dist[cur] + w;
				padre[next] = cur;
				Q.insert(mp(dist[next], next));
			}
		}
		Q.erase(mp(dist[cur],cur));
	}
}

int main(){
	ios_base::sync_with_stdio(0);

	int N, M; 
	while(cin >> N >> M && N != 0){
		
		/// O(M log M)
		// (u,v) -> (w,cantidad)
		// u < v
		map<ii, ii> aristas;
		forn(i,M){
			int u, v, w; cin >> u >> v >> w;
			if(u == v) continue;
			ii par = mp(min(u,v),max(u,v));
			auto it = aristas.find(par);
			
			if(it == aristas.end()){
				aristas[par] = mp(w,1);
			}else{
				if(w < (*it).second.first){
					aristas[par] = mp(w,1);
				}else if(w == (*it).second.first){
					int cant = (*it).second.second;
					aristas[par] = mp(w,cant+1);
				}
			}
		}
		// con esto logramos que haya solo una arista a lo sumo entre 
		// un par de vertices (la de menor peso). si hay varias con peso 
		// minimo, guardamos la cantidad. 
		
		/// O(M)
		vector<vii> graf(N, vii());
		for(auto &ar : aristas){
			int u, v, w;
			u = ar.first.first;
			v = ar.first.second;
			w = ar.second.first;
			
			graf[u].pb(mp(v,w));
			graf[v].pb(mp(u,w));
		}
		
		/// O(2*dijk)
		vi distAB(N, INF);
		vi padreAB(N, -1);
		dijk(graf, 0, distAB, padreAB);
		
		vi distBA(N, INF);
		vi padreBA(N, -1);
		dijk(graf, N-1, distBA, padreBA);
		
		/// O(N log M)
		set<ii> usoAristas;
		int MINDIST = distAB[N-1];
		forn(i,N){
			if(distAB[i] + distBA[i] == MINDIST){
				if(padreAB[i] != -1){
					int u = min(i,padreAB[i]);
					int v = max(i,padreAB[i]);
					usoAristas.insert(mp(u,v));
				}
				if(padreBA[i] != -1){
					int u = min(i,padreBA[i]);
					int v = max(i,padreBA[i]);
					usoAristas.insert(mp(u,v));
				}
			}
		}
		
		/// O(M log M)
		int RES = 0;
		for(auto &ar : usoAristas){
			auto arC = aristas.find(ar);
			RES += 2*(arC->second.first)*(arC->second.second);
		}
		cout << RES << endl;
	}
	
	return 0;
}
