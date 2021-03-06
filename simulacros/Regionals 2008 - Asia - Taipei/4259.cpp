#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <deque>

typedef long long tint;
#define forn(i,n) for(tint i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(tint i=s;i<(int)(n);i++)


using namespace std;

struct Arista
{
	tint peso,v;
	Arista (tint vv, tint pp)
	{
		v = vv;
		peso = pp;
	}
}; 

// Hacer que devuelva el flow y no pasarlo como paremetro, tampoco inicializar flowPath
tint maxFlow (vector<vector<tint> > const &capacidades, vector<vector<Arista> > ladj, tint qNodos, tint source, tint terminal, tint maxPeso)
{
	tint flow = 0;
	vector<vector<tint> > flowPath (qNodos, vector<tint> (qNodos,0));
	tint capacityFound = -1;
	forn(i, ladj.size())
		for (auto &a : ladj[i])
			if (capacidades[i][a.v] != 0)
				ladj[a.v].push_back(Arista(i,0));
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
			{
				if (capacidades[actual][vecino.v] > flowPath[actual][vecino.v] && path[vecino.v] == -1 && vecino.peso <= maxPeso )
				{
					path[vecino.v] = actual;
					pathCapacity[vecino.v] = min(pathCapacity[actual],capacidades[actual][vecino.v] - flowPath[actual][vecino.v]);
					if (vecino.v != terminal)
						visit.push_back(vecino.v);
					else
					{
						capacityFound = pathCapacity[vecino.v];
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
	#ifdef ACMTUYO
	if (!freopen("59.in", "r", stdin))
		return 1;
	#endif
	tint n, test = 1;
	while (cin >> n && n != 0)
	{
		tint t,csup = 0;
		cin >> t;
		vector<vector<Arista> > ladj (2*n+2); // 0 es Kulolo, 2*n+1 es Gulolo, los impares los de entrada, los pares los de salida (hay que simular vertices con capacidades)
		vector<vector<tint> > capacidades(2*n+2,vector<tint> (2*n+2,0));
		forn(i,t)
		{
			tint p,q,d;
			cin >> p >> q >> d;
			ladj[2*min(p,q)].push_back(Arista(2*max(p,q)-1,d));
			capacidades[2*min(p,q)][2*max(p,q)-1] = 1;
			csup = max(csup, d);
		}
		forsn(i,1,n+1)
		{
			capacidades[2*i-1][2*i] = 1;
			ladj[2*i-1].push_back(Arista(2*i,0));
		}
		tint k;
		cin >> k;
		tint cinf = 0;
		
		if (maxFlow(capacidades,ladj,2*n+2,0,2*n+1,csup) < k)
			cout << "Case " << test << ": " << "no solution" << endl;
		else
		{
			while (csup - cinf > 1)
			{
				tint maxPeso = (cinf + csup)/2;
				if (maxFlow(capacidades,ladj,2*n+2,0,2*n+1,maxPeso) < k)
					cinf = maxPeso;
				else
					csup = maxPeso;
			}
			cout << "Case " << test << ": " << csup << endl;
		}
		test++;
		
		
	}
}
