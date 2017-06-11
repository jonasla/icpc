#include <iostream>
#include <cassert>
#include <vector>
#include <deque>

using namespace std;

typedef long long tint;

#define forn(i,n) for(tint i=0;i<(tint)(n); i++)

void dfsVisita (deque<tint> &ordenDfs, vector<bool> &visitado, vector<vector<tint> > &listaVecinos, tint nodo, tint k, vector<tint> &scc)
{
	// ACA COMIENZA LA VISITA
	visitado[nodo] = true;
	for (auto vecino : listaVecinos[nodo])
		if (!visitado[vecino])
			dfsVisita(ordenDfs,visitado,listaVecinos,vecino,k,scc);
	// ACA FINALIZA LA VISITA
	scc[nodo] = k;
	ordenDfs.push_front(nodo); /* Notar que lo ponemos al principio para 
								* que quede directamente ordenado por 
								* orden decreciente de finalizacion */
}

deque<tint> dfs (vector<bool> &visitado, deque<tint> &orden, vector<vector<tint> > &listaVecinos, vector<tint> &scc)
{
	tint k = 0;
	deque<tint> ordenDfs;
	for(auto nodo : orden)
		if (!visitado[nodo])
			dfsVisita(ordenDfs,visitado,listaVecinos, nodo,k++,scc);
	return ordenDfs;
}

int main()
{
	#ifdef ACMTUYO
		assert(freopen("ej4.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	tint a,p;
	while (cin >> a >> p)
	{
		
		/* Leemos la entrada, y guardamos la lista de adyacencia del 
		 * grafo original y su transpuesto (vamos a usar Kosaraju) */
		vector<vector<tint> > listaVecinosOriginal (a);
		vector<vector<tint> > listaVecinosTranspuesto (a);
		
		forn(i,p)
		{
			tint u,v;
			cin >> u >> v; 
			// Las aulas vienen numeradas desde 1, de ahi el "-1"
			listaVecinosOriginal[u-1].push_back(v-1);
			listaVecinosTranspuesto[v-1].push_back(u-1);
		}
		// La funcion dfs, toma un orden en el que genera el dfs-forest
		deque<tint> ordenUsual (a);
		forn(i,a)
			ordenUsual[i] = i;
		vector<bool> visitado (a,false);
		vector<tint> scc (a); 
		deque<tint> ordenDfs = dfs(visitado, ordenUsual, listaVecinosOriginal,scc);
		forn(i,a)
			visitado[i] = false;
		ordenDfs = dfs(visitado,ordenDfs,listaVecinosTranspuesto,scc);
		
		// EN "scc[i]" esta guardada la componente fuertemente conexa del nodo i 
		
		
		// RESPONDEMOS LAS QUERIES
		
			/* Para cada query se quiere saber si las 2 aulas estan en
			 * una misma componente fuertemente conexa */
		tint q;
		cin >> q;
		forn(i,q)
		{
			tint a1,a2;
			cin >> a1 >> a2;
			// Otra vez, restamos uno por la numeracion
			if (scc[a1-1] == scc[a2-1])
				cout << "S\n";
			else
				cout << "N\n";
		}
	}
	return 0;
}




