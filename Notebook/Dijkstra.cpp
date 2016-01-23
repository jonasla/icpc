#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

typedef long long tint;

using namespace std;

struct Arista
{
	tint v1,v2,peso;
	Arista(tint vv1, tint vv2, tint pp)
	{
		v1 = vv1;
		v2 = vv2;
		peso = pp;
	}
};

bool operator < (Arista a1, Arista a2)
{
	return make_tuple(a1.peso,a1.v1,a1.v2) > make_tuple(a2.peso,a2.v1,a2.v2);
}


vector<tint> dijkstra (vector<vector<tint> > &ladj, vector<vector<tint> > &w, tint s) // Devuelve un vector d, tal que d[v] es la minima distancia de "s" a "v"
{
	tint n = ladj.size();
	vector<tint> d (n,1000000000); // Aca va una cota que funque para el problema en vez de 1000000000
	priority_queue<Arista> v;
	d[s] = 0;
	for(auto vecino : ladj[s])
		v.push(Arista(s,vecino,w[s][vecino]));
	while (!v.empty())
	{
		if (d[v.top().v2] == 1000000000 or d[v.top().v1] + v.top().peso <= d[v.top().v2])
		{
			Arista e = v.top();
			v.pop();
			d[e.v2] = d[e.v1] + e.peso;
			for(auto vecino : ladj[e.v2])
				v.push(Arista(e.v2,vecino,w[e.v2][vecino]));
		}
		else
			v.pop();
	}
	return d;
}
