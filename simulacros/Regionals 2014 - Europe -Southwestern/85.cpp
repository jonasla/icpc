#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define forn(i,n) for(int (i)=0; i<(int)(n); (i)++)
#define forsn(i,s,n) for(int (i)=(s); i<(int)(n); (i)++)
#define mp make_pair
#define pb push_back
const int INF = 1000000000;

struct arista {
	int peso, v1, v2, id, cant;
	arista(int p, int u, int v, int i, int c) : peso(p), v1(u), v2(v), id(i), cant(c) { }
};

bool operator < (arista a1, arista a2)
{
	return mp(a1.peso, mp(a1.v1,a1.v2)) > mp(a2.peso,mp(a2.v1,a2.v2));
}

typedef vector<int> vi;
typedef pair<int,int> ii;

void dijk(vector<vi> &graf, int s, vi &dist, vi &padre, vector<arista> &aristas){
	dist[s] = 0;
	padre[s] = -1;
	priority_queue<arista> Q;
	for(auto &ady : graf[s]){
		Q.push( aristas[ady] );
	}
	while(!Q.empty()){
		arista top = Q.top();
		Q.pop();
		int u = top.v1;
		int v = top.v2;
		int w = top.peso;
		int id = top.id;
		
		if(dist[v] == INF || dist[u] + w <= dist[v] ){
			dist[v] = dist[u] + w;
			padre[v] = id;
			for(auto &ady : graf[v]){
				Q.push( aristas[ady] );
			}
		}
	}
}

void printArista(arista &ar){
	cout << ar.v1 << " -> " << ar.v2 << " " << ar.peso << " (" << ar.cant << ") " << ar.id << endl;
}

int main(){
	int N, M; 
	while(cin >> N >> M && N != 0){
		/// O(M log M)
		map<ii, ii> pesos;
		map<ii, int> cants;
		
		forn(i,M){
			int u, v, w; cin >> u >> v >> w;
			if(u == v) continue;
			ii par = mp(min(u,v),max(u,v));
			auto it = pesos.find(par);
			
			if(it == pesos.end()){
				pesos[par] = mp(w,1);
				//pesos[mp(v,u)] = mp(w,1);
			}else{
				if(w < (*it).second.first){
					pesos[par] = mp(w,1);
					//pesos[mp(v,u)] = mp(w,1);
				}else if(w == (*it).second.first){
					int cant = (*it).second.second;
					pesos[par] = mp(w,cant+1);
					//pesos[mp(v,u)] = mp(w,cant+1);
				}
			}
		}
		// con esto logramos que haya solo una arista a lo sumo entre 
		// un par de vertices (la de menor peso). si hay varias con peso 
		// minimo, guardamos la cantidad. 
		
		/// O(M)
		vector<vi> graf(N, vi());
		vector<arista> aristas;
		
		for(auto &it : pesos){
			int u, v, w, id, cant;
			u = it.first.first;
			v = it.first.second;
			w = it.second.first;
			cant = it.second.second;
			
			id = aristas.size();
			arista ar1 = arista(w, u, v, id, cant);
			graf[u].pb(id);
			aristas.pb(ar1);
			
			id = aristas.size();
			arista ar2 = arista(w, v, u, id, cant);
			graf[v].pb(id);
			aristas.pb(ar2);
		}
				
		/// O(dijkstra*2) + O(N)
		vi distAB = vi(N, INF);
		vi padreAB = vi(N, -1);
		dijk(graf, 0, distAB, padreAB, aristas);
		
		vi distBA = vi(N, INF);
		vi padreBA = vi(N, -1);
		dijk(graf, N-1, distBA, padreBA, aristas);
		
		vector<bool> usoArista(aristas.size(), false);
		int MINDIST = distAB[N-1];
		forn(i,N){
			if(distAB[i] + distBA[i] == MINDIST){
				int v;
				
				v = i;
				//while(padreAB[v] != -1){
				if(padreAB[v] != -1){
					usoArista[padreAB[v]] = true;
					//v = aristas[padreAB[v]].v1;
				}
				
				v = i;
				//while(padreBA[v] != -1){
				if(padreBA[v] != -1){
					usoArista[padreBA[v]] = true;
					//v = aristas[padreBA[v]].v1;
				}
			}
		}
		
		/// O(M log M)
		map<ii, ii> usoAristaBi;
		forn(i,usoArista.size()){
			if(usoArista[i]){
				int u, v, w, cant;
				u = aristas[i].v1;
				v = aristas[i].v2;
				w = aristas[i].peso;
				cant = aristas[i].cant;
				
				usoAristaBi[mp(u,v)] = mp(w,cant);
				usoAristaBi[mp(v,u)] = mp(w,cant);
			}
		}
		/// O(M)
		int RES = 0;
		for(auto &ar : usoAristaBi){
			RES += ar.second.first*ar.second.second;
		}
		cout << RES << endl;
	}
	return 0;
}
