#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>

typedef long long tint;

#define forn(i,n) for(tint i=0;i<(tint)(n);i++)
#define forsn(i,s,n) for(tint i=s;i<(tint)(n);i++)

using namespace std;

// Hay que tener definidas de antemano:
// capacidades: Una matriz que en el lugar (i,j) guarda la capacidad que une al nodo i con j.
// ladj: Para cada nodo tiene la lista de vecinos. Notar que al comenzar el codigo se agregan las aristas que faltan para la red residual
// flow: Se debe dar un flujo inicial de 0
// flowPath: Guarda en el lugar (i,j) la cantidad de flujo que efectivamente pasa por la arista que une i con j. Inicialmente debe ser una matriz de ceros.


tint maxFlow (vector<vector<tint> > &capacidades, vector<vector<tint> > &ladj, tint qNodos, tint source, tint terminal)
{
	tint flow = 0;
	vector<vector<tint> > flowPath (qNodos, vector<tint> (qNodos,0));
	tint capacityFound = -1;
	forn(i, ladj.size())
		for (auto &a : ladj[i])
			if (capacidades[i][a] != 0)
				ladj[a].push_back(i);
	while (capacityFound != 0)
	{
		vector<tint> path (qNodos,-1);
		// Aca empieza el bfs
		
		path[source] = -2;
		capacityFound = 0;
		vector<tint> pathCapacity (qNodos,999999999999); // Aca va una cota para el flujo del problema
		deque<tint> visit = {source};
		while (!visit.empty())
		{
			tint actual = visit.front();
			visit.pop_front();
			for (auto vecino : ladj[actual])
			{
				if (capacidades[actual][vecino] > flowPath[actual][vecino] && path[vecino] == -1 )
				{
					path[vecino] = actual;
					pathCapacity[vecino] = min(pathCapacity[actual],capacidades[actual][vecino] - flowPath[actual][vecino]);
					if (vecino != terminal)
						visit.push_back(vecino);
					else
					{
						capacityFound = pathCapacity[vecino];
						visit.clear();
						break;
					}
				}
			}
		}
		// Aca termina el bfs
		if (capacityFound == 0)
			break;
		flow += capacityFound;
		tint v = terminal;
		while (v != source)
		{
			tint u = path[v];
			flowPath[u][v] += capacityFound;
			flowPath[v][u] -= capacityFound;
			v = u;
		}
	}
	return flow;
}

int main()
{
	return 0;
}
