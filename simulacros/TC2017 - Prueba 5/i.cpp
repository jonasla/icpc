#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long tint;
typedef pair<tint, tint> ii;
typedef vector<ii> vii;
typedef vector<tint> vi;
typedef set<tint> si;

#define forsn(i,s,n) for(int i=(tint)s; i<(tint)n; i++) 
#define forn(i,n) forsn(i,0,n) 

const tint INFINITO = 1e15;


void dijkstra (tint comienzo, vector<vector<pair<tint,tint> > > &ladj, vector<tint> &distance, vector<set<tint> > &parent)
{
	priority_queue <pair<tint,tint> > q; // {-peso,indice}
	tint n = distance.size();
	forn(i,n)
		distance[i] = (i != comienzo)*INFINITO;
	vector<tint> procesado (n,0);
	q.push({0,comienzo});
	while (!q.empty())
	{
		tint actual = q.top().second;
		q.pop();
		
		//~ cout << "sacoo " << actual << endl;
		if (!procesado[actual])
		{
			procesado[actual] = 1;
			for (auto vecino : ladj[actual])
			{
				//~ cout << "vecinoo " << vecino.first << endl;
				if (distance[actual] - vecino.first < distance[vecino.second])
				{
					distance[vecino.second] = distance[actual] - vecino.first;
					q.push({-distance[vecino.second], vecino.second});
					parent[vecino.second] = {actual};
				}
				else if (distance[actual] - vecino.first == distance[vecino.second])
					parent[vecino.second].insert(actual);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint N, M;
	while(cin >> N >> M && N != 0) {
		tint S, E; 
		cin >> S >> E;
		
		vector<vii> graf(N, vii());
		vector<vi> matGraf(N, vi(N, INFINITO));
		forn(i,M) {
			tint u, v, w; cin >> u >> v >> w;
			graf[u].push_back({-w, v});
			matGraf[u][v] = w;
		}
		//~ continue;
		//
		vi dist(N, 0);
		vector<si> parent(N, si());
		dijkstra(S, graf, dist, parent);

		//~ forn(i,N) {
			//~ cout << "parent " <<  i << endl;
			//~ for (auto p : parent[i]) cout << p << endl;
			//~ cout << endl;
		//~ }

		//~ continue;
		//
		vi visit(N, 0);
		queue<tint> Q;
		Q.push(E);
		while(!Q.empty()) {
			tint act = Q.front();
			Q.pop();
			//~ cout << "mirando " << act << endl;
			if (visit[act]) continue;
			visit[act] = true;
			forn(i,N) {
				if (matGraf[i][act] < INFINITO) {
					//~ cout << "con " << i << endl;
					if (parent[act].find(i) != parent[act].end()) {
						Q.push(i);
						//~ cout << "agrego ars " << i << " " << act << " " << matGraf[i][act] << endl;
						matGraf[i][act] = INFINITO;
					}
				}
			}
		}
		
		vector<vii> nuevoGraf(N, vii());
		forn(i,N) {
			forn(j,N) {
				if (matGraf[i][j] < INFINITO) {
					//~ if (parent[j].find(i) == parent[j].end()) {
						//~ cout << "agrego ars " << i << " " << j << " " << matGraf[i][j] << endl;
					nuevoGraf[i].push_back({-matGraf[i][j], j});
				}
			}
		}
		//
		dist = vi(N, 0);
		parent = vector<si>(N, si());
		dijkstra(S, nuevoGraf, dist, parent);
		
		if (dist[E] == INFINITO) cout << -1;
		else cout << dist[E];
		cout << "\n";
	}
	return 0;
}
