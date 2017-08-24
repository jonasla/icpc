#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for(tint i = 0; i < (tint) (n); i++)

bool esClique (tint comienzo, vector<vector<tint> > &ladj, vector<bool> &visitado)
{
	tint verticesVisitados = 0, sumaGrados = 0;
	vector<tint> vecinos = {comienzo}, nuevosVecinos = {};
	visitado[comienzo] = true;
	while (!vecinos.empty())
	{
		tint v = vecinos.back();
		vecinos.pop_back();
		verticesVisitados++;
		sumaGrados += ladj[v].size();
		
		for (auto u : ladj[v])
			if (!visitado[u])
			{
				visitado[u] = true;
				nuevosVecinos.push_back(u);
			}
		if (vecinos.empty())
		{
			vecinos = nuevosVecinos;
			nuevosVecinos = {};
		}
	}
	//~ cout << sumaGrados << " " << verticesVisitados << endl;
	return (sumaGrados == (verticesVisitados * (verticesVisitados-1)));
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,m;
	while (cin >> n >> m)
	{
		vector<vector<tint> > ladj (n);
		forn(i,m)
		{
			tint a,b;
			cin >> a >> b;
			ladj[a-1].push_back(b-1);
			ladj[b-1].push_back(a-1);
		}
		vector<bool> visitado(n,false);
		bool todoPiola = true;
		forn(i,n)
			if (!visitado[i])
				todoPiola &= esClique(i,ladj,visitado);
		if (todoPiola)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
