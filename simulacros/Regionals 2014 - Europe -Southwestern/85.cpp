#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

#define forn(i,n) for(int (i)=0; i<(int)(n); (i)++)
#define forsn(i,s,n) for(int (i)=(s); i<(int)(n); (i)++)

#define mp make_pair
#define pb push_back

#define INF 1000000000

typedef pair<int, int> ii;
typedef pair<int, ii> edge;
typedef pair<edge, int> edgeid;

typedef vector<int> vi;

// llamar con vector dist con INF
// y vector padre con -1

void dijk(vector<vi > &graf, int s, vi &dist, vi &padre, vector<edge> &aristas){
	dist[s] = 0;
	padre[s] = -1;
	priority_queue<edgeid> Q;
	for(auto &ady : graf[s]){
		Q.push( mp( aristas[ady], ady ) );
	}
	while(!Q.empty()){
		edgeid top = Q.top();
		Q.pop();
		int u = top.first.second.first;
		int v = top.first.second.second;
		int w = top.first.first;
		int id = top.second;
		
		if(dist[v] == INF || dist[u] - w <= dist[v] ){
			dist[v] = dist[u] - w;
			padre[v] = id;
			for(auto &ady : graf[v]){
				Q.push( mp( aristas[ady], ady ) );
			}
		}
	}
}

int main(){

	int N, M; 
	while(cin >> N >> M && N != 0){
		vector<vi> graf(N, vi());
		vector<edge> aristas;
		
		forn(i,M){
			int u, v, w; cin >> u >> v >> w;
			
			aristas.pb( mp( -w , mp( u , v ) ) );
			graf[u].pb( aristas.size() );
			
			aristas.pb( mp( -w , mp( v , u ) ) );
			graf[v].pb( aristas.size() );
		}
		
		vi distAB = vi(N, INF);
		vi padreAB = vi(N, -1);
		dijk(graf, 0, distAB, padreAB, aristas);
		
		vi distBA = vi(N, INF);
		vi padreBA = vi(N, -1);
		dijk(graf, N-1, distBA, padreBA, aristas);
		
		int MINDIST = distAB[N-1];		

		forsn(i,1,N){
			if(distAB[i] + distBA[i] == MINDIST){
				int v = i;
				while(v != 0){
					v = padreAB[v];
				}
				v = i;
				while(v != N-1){
					v = padreBA[v];
				}
			}
		}
	
	}
	return 0;
}
