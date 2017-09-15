#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (tint)(s); i < (tint)(n); i++)


const tint INFINITO = 1000;

int main()
{
	tint n,m,q;
	while (cin >> n >> m >> q)
	{
		vector<tint> edad (n);
		vector<tint> p (n);
		forn(i,n)
		{
			cin >> edad[i];
			p[i] = i;
		}
		vector<vector<tint> > ladj (n);
		vector<tint> soyRaiz (n,1);
		forn(i,m)
		{
			tint x,y;
			cin >> x >> y;
			ladj[x-1].push_back(y-1);
			soyRaiz[y-1] = 0;
		}
		vector<tint> raices;
		forn(i,n)
			if (soyRaiz[i] == 1)
				raices.push_back(i);
		bool actualizado = false; //  TENGO QUE CORRER LA QUERY
		vector<tint> best (n,INFINITO);
		forn(query,q)
		{
			char tipo;
			cin >> tipo;
			if (tipo == 'T')
			{
				tint u,v;
				cin >> u >> v;
				u--;
				v--;
				//~ swap(ladj[p[u]],ladj[p[v]]);
				swap(p[u],p[v]);
				actualizado = false;
				
			}
			else
			{
				tint x;
				cin >> x;
				x--;
				if (!actualizado)
				{
					forn(i,n)
						best[i] = INFINITO;
					vector<tint> vecinos;
					vector<tint> nuevosVecinos;
					vector<tint> visitado(n,0);
					for (auto r : raices)
					{
						vecinos.push_back(p[r]);
						visitado[p[r]] = 1;
					}
					while (!vecinos.empty())
					{
						tint actual = vecinos.back();
						vecinos.pop_back();
						for (auto z : ladj[p[actual]])
						{
							if (!visitado[p[z]])
							{
								visitado[p[z]] = 1;
								nuevosVecinos.push_back(p[z]);
							}
							best[p[z]] = min(best[p[z]],min(best[actual],edad[actual]));
						}
						if (vecinos.empty())
						{
							vecinos = nuevosVecinos;
							nuevosVecinos = {};
						}
					}
					actualizado = true;
				}
				if (best[x] == INFINITO)
					cout << "*\n";
				else
					cout << best[x] << "\n";
			}
		}
	}
	return 0;
}
