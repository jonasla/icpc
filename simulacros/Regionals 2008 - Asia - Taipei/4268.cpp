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

struct Par
{
	tint fila,columna;
	Par (tint ff, tint cc)
	{
		fila = ff;
		columna = cc;
	}
};

void bfs (vector<vector<tint> > &capacidades, vector<vector<tint> > &ladj, tint &m, tint &n, tint &source, tint &terminal,vector<vector<tint> > &flowPath, tint &capacityFound, vector<tint> &path)
{
	path[source] = -2;
	capacityFound = 0;
	vector<tint> pathCapacity (n+m+2,999999999999);
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
	
}

void maxFlow (vector<vector<tint> > &capacidades, vector<vector<tint> > &ladj, tint m, tint n, tint source, tint terminal,vector<vector<tint> > &flowPath, tint &flow)
{
	tint capacityFound = -1;
	while (capacityFound != 0)
	{
		vector<tint> path (n+m+2,-1);
		bfs(capacidades,ladj,m,n,source,terminal,flowPath,capacityFound,path);
		
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

int main()
{
	tint tt;
	cin >> tt;
	forn(test,tt)
	{
		tint m,n; // m filas, n columnas
		cin >> m >> n;
		vector<vector<double> > matrizDouble (m,vector<double> (n));
		vector<vector<vector<tint> > > matrizEntera (2, (vector<vector<tint> > (m, vector<tint> (n)))); // En la posicion 0, nos guardamos la original, en la posicion 1 la que sale de tomar techo a todo.
		forn(i,m)
		forn(j,n)
			cin >> matrizDouble[i][j];
		
		vector<vector<tint> > sumaFilas (2,vector<tint> (m,0));
		vector<vector<tint> > sumaColumnas (2,vector<tint> (n,0));
		vector<vector<tint> > capacidades (m+n+2, vector<tint> (n+m+2,0));
		vector<vector<tint> > ladj (m+n+2);
		forn(i,m)
		forn(j,n)
		{
			
			matrizEntera[0][i][j] = tint (matrizDouble[i][j]*100.0 + 0.5); // Como nos dicen que los numeros tienen 2 cifras, los pensamos como enteros (1.34 -> 134, etc)
			
			if (matrizEntera[0][i][j] % 100 != 0) // Si no es entero el numero
			{
				matrizEntera[1][i][j] = ((matrizEntera[0][i][j]/100)+1)*100; // Notar que no es lo mismo que matrizEnteraOld[i][j] + 100, porque en la division hay truncamiento 
				capacidades[1+i][1+m+j] = 1;
				ladj[1+i].push_back(1+m+j);
			}
			else
			{
				matrizEntera[1][i][j] = matrizEntera[0][i][j];
				capacidades[1+i][1+m+j] = 0;
			}
			
			forn(k,2)
			{
				sumaFilas[k][i] += matrizEntera[k][i][j];
				sumaColumnas[k][j] += matrizEntera[k][i][j];
			}
		}
		bool sePuede = true;
		forn(i,m)
			sePuede &= (sumaFilas[0][i] % 100 == 0);
		forn(j,n)
			sePuede &= (sumaColumnas[0][j] % 100 == 0);
		if (!sePuede)
			cout << "no" << endl;
		else
		{
			forn(i,m)
			{
				ladj[0].push_back(1+i);
				capacidades[0][1+i] = (sumaFilas[1][i] - sumaFilas[0][i])/100;
			}
			forn(j,n)
			{
				ladj[1+m+j].push_back(n+m+1);
				capacidades[1+m+j][n+m+1] = (sumaColumnas[1][j] - sumaColumnas[0][j])/100;
			}
				
			tint flow = 0;
			vector<vector<tint> >  flowPath (n+m+2, vector<tint> (n+m+2,0));
			maxFlow(capacidades,ladj,m,n,0,n+m+1,flowPath,flow);
			vector<Par> casillasQueRestar;
			forn(i,m)
			forn(j,n)
			if (flowPath[1+i][1+m+j] == 1)
				casillasQueRestar.push_back(Par(i,j));
			
			//forn(i,n+m+2)
			//{
			//	forn(j,n+m+2)
			//	{
			//		if (j)
			//			cout << " ";
			//		cout << flowPath[i][j];
			//	}
			//	cout << endl;
			//}
			//cout << flow << endl;
			
			
			for (auto casilla : casillasQueRestar)
				matrizEntera[1][casilla.fila][casilla.columna] -= 100;
			forn(i,m)
			{
				forn(j,n)
				{
					if (j)
						cout << " ";
					cout << matrizEntera[1][i][j]/100;
				}
				cout << endl;
			}
		}
	}
	return 0;
}
