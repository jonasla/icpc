#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <tuple>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stdio.h>



#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl

typedef long long tint;
typedef unsigned long long utint;
typedef long double ldouble; 

using namespace std;



void imprimirVector (vector<tint> v)
{
	if (!v.empty())
	{ 
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}
	else
		cout << "[]" << endl;
}

tint toNumber (string s)
{
	tint Number;
	if ( ! (istringstream(s) >> Number) ) Number = 0; // el string vacio lo manda al cero
	return Number;
}

string toString (tint number)
{    
    ostringstream ostr;
    ostr << number;
    return  ostr.str();
}

//
// Idea: Armar el grafo que tiene a las confederaciones como vertice y a las ciudades como aristas no dirigidas que unen dos confederaciones 
//			no necesariamente distintas (puede haber loops, si una ciudad pertenece a solo una confederacion) 
//				Una vez que armamos este grafo la idea es encontrar un camino/ciclo euleariano.				
//

bool esConexo (vector<vector<int> > &ladj) // Es un BFS "de librito", pero al final devuelve si el grafo es conexo (salvo por nodos aislados)
{
	int c = ladj.size();
	vector<bool> visitado (c,false);
	deque<int> vecinos;
	forn(i,c)
		if (!ladj[i].empty())
			{visitado[i] = true; vecinos.push_back(i); break;} // Esto es para asegurarse de no arrancar en un nodo aislado
	while (!vecinos.empty())
	{
		int actual = vecinos.front();
		vecinos.pop_front();
		for (auto v : ladj[actual])
			if (!visitado[v])
				{visitado[v] = true;vecinos.push_back(v);}
	}
	bool tutti = true;
	forn(i,c)
		tutti &= (visitado[i] or (ladj[i].empty())); // considero "conexo" <=> para todo nodo vale que: fue visitado por el BFS o es un nodo aislado.
	return tutti;
}
 


int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	int n,c;
	while ((cin >> n >> c) && n != 0 && c != 0)
	{
		vector<pair<int,int> > ciudad (n,make_pair(-1,-1)); // Cada ciudad representa una arista
		forn(u,c)
		{
			int k;
			cin >> k;
			forn(j,k)
			{
				int v;
				cin >> v; 
				if (ciudad[v].second != -1) 
					ciudad[v].second = u;
				else
					ciudad[v] = make_pair(u,u); 
			}
		}
		
		vector<vector<int> > ladj (c); // Cada confedereacion representa un vertice
		for (auto e : ciudad) 
		{
			ladj[e.first].push_back(e.second);
			ladj[e.second].push_back(e.first);
		}
		int minCityImpar = 99999999, gradoImpar = 0; // La arista de menor indice que se conecta con un vertice de grado impar (donde comienza el camino euleriano), y la cantidad de nodos con grado impar
		forn(i,n) // Recorremos las aristas en orden
		{
			if (ladj[ciudad[i].first].size() % 2) // Si un extremo tiene grado impar 
				minCityImpar = i;
			if (ladj[ciudad[i].second].size() % 2) // Si el otro extremo tiene grado impar
				minCityImpar = i; 
			if (minCityImpar < n) // Si ya actualice el valor, como estoy recorriendo en orden, puedo cortar.
				break;
		}
		forn(i,c)
			gradoImpar += (ladj[i].size() % 2); 
		if (gradoImpar == 0) // Si todos los vertices tienen grado par, hay ciclo euleriano y podemos comenzar por la primer arista.
			minCityImpar = 0;
		if (esConexo(ladj) && (gradoImpar == 2 or gradoImpar == 0)) // Si puede tener camino/ciclo euleriano
			cout << minCityImpar << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}



