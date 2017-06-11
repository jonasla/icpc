#include <iostream>
#include <vector>

using namespace std;

#define forn(i,n) for(tint i=0; i<(int)n; i++)

typedef long long tint;
typedef vector<tint> vi;
typedef pair<tint, tint> ii;
typedef vector<ii> vii;

const tint INF = 100000000000000000;



void dfsDist(vector<vii> &arbol, tint i, vi &dist, tint d) {
  dist[i] = d;
  for(auto ady : arbol[i]) {
    tint v = ady.first;
    tint l = ady.second;
    if (dist[v] == INF)
      dfsDist(arbol, v, dist, d+l);
  }
}


//////////////////////


// Nodo del segment tree
struct Nodo
{
	tint id;
  tint level;
	Nodo (tint i, tint l)
	{
    id = i;
		level = l;
	}
};


// Operacion del segment tree : tiene que ser ASOCIATIVA
Nodo op (Nodo n1, Nodo n2)
{
	if (n1.level < n2.level) {
    return n1;
  } else {
    return n2;
  }
}

vector<Nodo> buildSegTree (vector<Nodo> &v )
{
	// Completa el tamanho
	tint k = 4, n = v.size();
	while (k < 2*n)
		k *= 2;
	// Rellena las hojas
	vector<Nodo> seg (k, Nodo(-1, INF));
	forn(i,n)
		seg[k/2+i] = v[i];
	// Completa los padres
	while (k > 0)
	{
		seg[(k-1)/2] = op(seg[k-1],seg[k-2]);
		k -= 2;
	}
		
	return seg; 
}

// i es el indice de [0,n) en el arreglo original
// Nodo es lo que queremos poner ahora como hoja
void update(tint i, Nodo nodo,vector<Nodo> &seg)
{
	tint k = seg.size()/2 + i;
	seg[k] = nodo;
	while (k > 0)
	{
		seg[k >> 1] = op(seg[k],seg[k^1]);
		k /= 2;
	}
}

Nodo queryAux(tint k, tint l, tint r, tint i, tint j, vector<Nodo> &seg)
{
	if (i <= l && r <= j)
		return seg[k];
	if (r <= i or l >= j)
		return Nodo(-1,INF); // Aca va el NEUTRO de la funcion "op"
	Nodo a = queryAux(2*k,l,(l+r)/2,i,j,seg);
	Nodo b = queryAux(2*k+1,(l+r)/2,r,i,j,seg);
	return op(a,b);
	
}

// i,j son los indices del arreglo del que se hace la query
// la query se hace en [i,j)
Nodo query(tint i, tint j, vector<Nodo> &seg)
{
	return queryAux(1,0,seg.size()/2,i,j,seg);
}

//////////////////////

void dfsRMQ(vector<vii> &arbol, tint i, vector<Nodo> &nodos, tint l, vi &apariciones) {
  nodos.push_back(Nodo(i,l));
  apariciones[i] = min(apariciones[i], (tint)(nodos.size()-1));
  for(auto ady : arbol[i]) {
    tint v = ady.first;
    
    if (apariciones[v] == INF) {
      dfsRMQ(arbol, v, nodos, l+1, apariciones);
      nodos.push_back(Nodo(i,l));
    }
  }
}

int main() {
  tint N; 
  while(cin >> N && N > 0) {
    vector<vii> arbol(N, vii());
    forn(i,N-1) {
      tint a, l;
      cin >> a >> l;
      arbol[i+1].push_back({a,l});
      arbol[a].push_back({i+1,l});
    }
    
    vi dist(N, INF);
    dfsDist(arbol, 0, dist, 0);
    vector<Nodo> nodos;
    vi apariciones(N, INF);
    dfsRMQ(arbol, 0, nodos, 0, apariciones);
    vector<Nodo> seg = buildSegTree(nodos);

    int Q; cin >> Q;
    forn(i,Q) {
      tint u, v; cin >> u >> v;
      tint uu = apariciones[u];
      tint vv = apariciones[v];
      
      Nodo q = query(min(uu,vv), max(uu,vv)+1, seg);
      tint rta = dist[u] + dist[v] - 2*dist[q.id];
      if (i) cout << " ";
      cout << rta;
    }
    cout << endl;

  }
  return 0;
}
