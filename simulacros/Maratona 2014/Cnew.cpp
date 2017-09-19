#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint) (n); i++)

const tint INFINITO = 100000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	tint n,m,q;
	while (cin >> n >> m >> q)
	{
		vector<pair<tint,tint> > p(n);
		forn(i,n)
		{
			tint e;
			cin >> e;
			p[i] = {e,i};
		}
		vector<vector<tint> > ladj(n);
		forn(i,m)
		{
			tint x,y;
			cin >> x >> y;
			ladj[y-1].push_back(x-1);
		}
		
		forn(query,q)
		{
			char tipo;
			cin >> tipo;
			if (tipo == 'T')
			{
				tint x,y;
				cin >> x >> y;
				x--;
				y--;
				tint u = x, v = y;
				forn(i,n)
				{
					if (p[i].second == x)
						u = i;
					else if (p[i].second == y)
						v = i;
				}
						
				swap(p[u],p[v]);
				
			}
			else
			{
				
				tint e = INFINITO;
				vector <tint> vecinos, nuevosVecinos, visitado(n,0);
				tint x;
				cin >> x;
				x--;
				forn(i,n)
					if (p[i].second == x)
					{
						vecinos.push_back(i);
						visitado[i] = 1;
					}
				while (!vecinos.empty())
				{
					tint actual = vecinos.back();
					vecinos.pop_back();
					//~ cout << actual << " : ";
					for (auto y : ladj[actual])
					{
						//~ cout << y << ", " << p[y] << " | "; 
						if (!visitado[y])
						{
							nuevosVecinos.push_back(y);
							visitado[y] = 1;
							e = min(e,p[y].first);
						}
					}
					//~ cout << endl;
					if (vecinos.empty())
					{
						vecinos = nuevosVecinos;
						nuevosVecinos = {};
					}
				}
				
				if (e == INFINITO)
					cout << "*\n";
				else
					cout << e << "\n";
			}
		}
		
	}
}
