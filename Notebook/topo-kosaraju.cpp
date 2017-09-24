#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)

void dfsTopo(vector<vi> &g, tint s, vi &vis, vi &ord, vi &comp) {
	vis[s] = true;
	for(auto ad : g[s]) if (!vis[ad]) dfsTopo(g, ad, vis, ord, comp);
	ord.push_back(s);
	comp.push_back(s);
}
vi topoSort(vector<vi> &g) {// Devuelve el orden topologico
  int N = g.size();
  vi vis, ord, aux;
	vis.assign(N, 0);
	forn(i,N) if (!vis[i]) dfsTopo(g, i, vis, ord, aux);
	reverse(ord.begin(), ord.end());
  return ord;
}
// Devuelve las componentes en orden topologico
vector<vi> kosaraju(vector<vi> &graf) { 
	vi ord = topoSort(graf);
  // Invertimos el grafo
  tint N = graf.size();
  vector<vi> grafInv(N, vi());
  forn(i,N) for(auto j : graf[i]) grafInv[j].push_back(i);
  
  vi vis(N, false), aux;
  vector<vi> comps;
	for (auto o : ord)
  if (!vis[o]) {
    vi comp; dfsTopo(grafInv, o, vis, aux, comp);
    comps.push_back(comp);
  }
	return comps;
}

int main() {
  int N = 6;
  vector<vi> graf(N, vi());
  graf[0].push_back(1);
  graf[1].push_back(2);
  graf[2].push_back(0);
  
  graf[2].push_back(3);
  
  graf[3].push_back(4);
  graf[4].push_back(3);
  
  graf[4].push_back(5);

  vector<vi> comps = kosaraju(graf);
  for(auto &c : comps) {
    for(auto &e : c) cout << e << " ";
    cout << endl;
  }
  return 0;
}
