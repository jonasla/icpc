#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>

typedef long long tint;

#define forn(i,n) for(tint i=0;i<(tint)(n);i++)
#define forsn(i,s,n) for(tint i=s;i<(tint)(n);i++)

using namespace std;

// Hay que tener definidas de antemano:
// capacidades: Una matriz que en el lugar (i,j) guarda la capacidad que une al nodo i con j.
// ladj: Para cada nodo tiene la lista de vecinos.
// flow: Se debe dar un flujo inicial de 0
// flowPath: Guarda en el lugar (i,j) la cantidad de flujo que efectivamente pasa por la arista que une i con j. Inicialmente debe ser una matriz de ceros.


void maxFlow (vector<vector<tint> > &capacidades, vector<vector<tint> > &ladj, tint qNodos, tint source, tint terminal, vector<vector<tint> > &flowPath, tint &flow)
{
	tint capacityFound = -1;
	while (capacityFound != 0)
	{
		vector<tint> path (qNodos,-1);
		// Aca empieza el bfs
		path[source] = -2;
		capacityFound = 0;
		vector<tint> pathCapacity (qNodos,999999999999);
		deque<tint> visit = {source};
		while (!visit.empty())
		{
			tint actual = visit.front();
			visit.pop_front();
			for (auto vecino : ladj[actual])
				if (capacidades[actual][vecino] > flowPath[actual][vecino] && path[vecino] == -1 )
				{
					path[vecino] = actual;
					pathCapacity[vecino] = min(pathCapacity[actual],capacidades[actual][vecino] - flowPath[actual][vecino]);
					if (vecino != terminal)
						visit.push_back(vecino);
					else
					{
						capacityFound = pathCapacity[vecino];
						break;
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
			ladj[v].push_back(u);
			v = u;
		}
	}
}
