#define forn(i,n) for(int i=0; i<(int)(n); i++)

#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

vector<int> bfs (vector<vector<int>> &lista, int nodoInicial)
{
	int n = lista.size(),t;
	queue<int> cola;
	vector<int> distancias (n,n);
	cola.push(nodoInicial);
	distancias[nodoInicial] = 0;
	while (!cola.empty())
	{
		t = cola.front();
		cola.pop();
		forn(i,lista[t].size())
		{
			if(distancias[lista[t][i]] == n)
			{
				distancias[lista[t][i]] = distancias[t]+1;
				cola.push(lista[t][i]);
			}
		}
	}
	return distancias;
}

int main()
{
	string s;
	cin >> s;
	int test = 1;
	while(s != "#")
	{
		int level = 0;
		int n = s.size();
		vector<int> arista;
		int qnodos = 0;
		forn(i,n)
			if (s[i] == 'd')
				qnodos++;
		qnodos++;
		arista.push_back(0);
		int maxlevel = 0;
		int nodoActual = 0;
		int nodoAnterior = 0;
		int ultimoNodoVisitado = 0;
		
		vector<vector<int> > ladj (qnodos);
		vector<vector<int> > llevel (qnodos);
		forn(i,n)
		{
			if (s[i] == 'd')
			{
				level++;
				maxlevel = max(maxlevel,level);
				nodoActual = ++ultimoNodoVisitado;
				arista.push_back(nodoActual);
				if (llevel[level].empty())
				{
					ladj[nodoActual].push_back(nodoAnterior);
					ladj[nodoAnterior].push_back(nodoActual);
				}
				llevel[level].push_back(nodoActual);
			}
			else
			{
				level--;
				nodoActual = nodoAnterior;
				nodoAnterior = arista[level-1];
				
			}
			int k = 0;
			while(!llevel[k].empty())
			{
				int p = llevel[k].size();
				if (p > 1)
				{
					forn(j,p-1)
					{
						ladj[llevel[k][j]].push_back(llevel[k][j+1]);
						ladj[llevel[k][j+1]].push_back(llevel[k][j]);
					}
				}
				k++;
			}
			
		}	
		vector<int> d = bfs(ladj,0);
		forn(i,qnodos)
		{
			forn(j,ladj[i].size())
				cout << ladj[i][j] << " ";
			cout << endl;
		}
		int distFinal = *max_element(d.begin(),d.end());
		cin >> s;
		cout << "Tree " << test << ": " << maxlevel << " => " << distFinal << endl;
		test++;
		
	}
	return 0;
}
