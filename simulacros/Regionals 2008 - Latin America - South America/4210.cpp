#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <set>


#define forn(i,n) for(int i=0;i<(int)(n); i++)

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

bool operator == (Arista a1, Arista a2)
{
	return make_tuple(a1.peso,a1.v1,a1.v2) == make_tuple(a2.peso,a2.v1,a2.v2);
}

vector<tint> dijkstra (vector<vector<tint> > &ladj, vector<vector<tint> > &w, tint s)
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

vector<vector<Arista> > dijkstraCaminos (vector<vector<tint> > &ladj, vector<vector<tint> > &w, tint s)
{
	tint n = ladj.size();
	vector<tint> d (n,1000000000); // Aca va una cota que funque para el problema en vez de 1000000000
	vector<vector<Arista> > camino (n);
	priority_queue<Arista> v;
	d[s] = 0;
	for(auto vecino : ladj[s])
		v.push(Arista(s,vecino,w[s][vecino]));
	while (!v.empty())
	{

		if (d[v.top().v2] == 1000000000 or (d[v.top().v1] + v.top().peso <= d[v.top().v2]))
		{
			Arista e = v.top();
			v.pop();
			d[e.v2] = d[e.v1] + e.peso;
			vector<Arista> aux = camino[e.v1];
			aux.push_back(e);
			camino[e.v2] = aux;
			for(auto vecino : ladj[e.v2])
				v.push(Arista(e.v2,vecino,w[e.v2][vecino]));
		}
		else
			v.pop();
	}
	return camino;
}

vector<tint> dijkstraProhibido (vector<vector<tint> > &ladj, vector<vector<tint> > &w, tint s, set<Arista> prohibido)
{
	tint n = ladj.size();
	vector<tint> d (n,1000000000); // Aca va una cota que funque para el problema en vez de 1000000000
	priority_queue<Arista> v;
	d[s] = 0;
	for(auto vecino : ladj[s])
	if ( prohibido.find(Arista(s,vecino,w[s][vecino])) == prohibido.end())
	{
		//cout << s << "->" << vecino << endl;
		v.push(Arista(s,vecino,w[s][vecino]));
	}
	while (!v.empty())
	{

		if (d[v.top().v2] == 1000000000 or (d[v.top().v1] + v.top().peso <= d[v.top().v2]))
		{
			Arista e = v.top();
			//cout << e.v1 << " <=> " << d[e.v1] << endl;
			v.pop();
			d[e.v2] = d[e.v1] + e.peso;
			for(auto vecino : ladj[e.v2])
			{
				if (prohibido.find(Arista(e.v2,vecino,w[e.v2][vecino])) == prohibido.end())
				{
					v.push(Arista(e.v2,vecino,w[e.v2][vecino]));
				//	cout << e.v2 << "->" << vecino <<  endl;
				}
			}
		}
		else
			v.pop();
	}
	return d;
}


int main()
{
	tint n,m;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		tint s,t;
		cin >> s >> t;
		vector<vector<tint> > ladj (n);
		vector<vector<tint> > ltadj (n);
		vector<vector<tint> > w (n,vector<tint> (n,0));
		vector<vector<tint> > wt (n,vector<tint> (n,0));
		forn(i,m)
		{
			tint u,v,p;
			cin >> u >> v >> p;
			ladj[u].push_back(v);
			ltadj[v].push_back(u);
			w[u][v] = p;
			wt[v][u] = p;
		}
		vector<tint> d = dijkstra(ladj,w,s);
		vector<tint> dt = dijkstra(ltadj,wt,t);
		vector<vector<Arista> > c = dijkstraCaminos(ladj,w,s);
		vector<vector<Arista> > ct = dijkstraCaminos(ltadj,wt,t);
		set<Arista> prohibido;
		tint minPath = d[t];
		forn(i,n)
		if (d[i] + dt[i] == minPath)
		{
			for(auto arista : c[i])
				prohibido.insert(arista);
			for(auto arista : ct[i])
			{
				swap(arista.v1,arista.v2);
				prohibido.insert(arista);
			}
		}
		//for (auto e : prohibido)
		//	cout << e.v1 << "->" << e.v2 << endl;
		//cout << " ------ " << endl;
		vector<tint> ans = dijkstraProhibido(ladj,w,s,prohibido);
		//cout << "minPath = " << minPath << endl;
		if (ans[t] == 1000000000)
			cout << -1 << endl;
		else
			cout << ans[t] << endl;
	}
	return 0;
}
