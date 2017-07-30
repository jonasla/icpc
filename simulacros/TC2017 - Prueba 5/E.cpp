#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
#include <valarray>
#include <random>
#include <iomanip>


typedef long long tint;
typedef unsigned long long utint;
typedef long double ldouble; 


#define forn(i,n) for(tint i=0;i<(tint)(n); i++)
#define forsn(i,s,n) for(tint i=(s);i<(tint)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl



using namespace std;



void imprimirVector (vector<tint> v)
{
	if (!v.empty())
	{ 
		tint p = tint(v.size());
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
	if ( ! (istringstream(s) >> Number) )
		Number = 0; // el string vacio lo manda al cero
	return Number;
}

string toString (tint number)
{    
    ostringstream ostr;
    ostr << number;
    return  ostr.str();
}

const tint maxN = 16384;
const tint INFINITO = 1e15;


struct Arista
{
	tint start,end,capacity,flow;
	Arista (tint ss, tint ee, tint cc, tint ff)
	{
		start = ss;
		end = ee;
		capacity = cc;
		flow = ff;
	}
};

vector<Arista>  red; // Red residual
vector<tint> ladj [maxN]; // Lista de adyacencia (guarda vecinos como indices en red)

tint n, s, t; // #Nodos, source, sink
tint ultimoVecino [maxN]; // ultimo vecino visitado en dfs
tint nivel [maxN]; // Nivel del bfs

void agregarArista (tint ss, tint ee, tint c)
{
	ladj[ss].push_back( tint (red.size())); // guardamos el indice
	red.push_back(Arista(ss,ee,c,0));
	ladj[ee].push_back( tint (red.size()));
	red.push_back(Arista(ee,ss,c,0));
	
}


bool bfs ()
{
	forn(i,n+1)
		nivel[i] = -1;
	vector<tint> vecinos = {s}, nuevosVecinos;
	nivel[s] = 0;
	while (!vecinos.empty() && nivel[t] == -1)
	{
		tint actual = vecinos.back();
		vecinos.pop_back();
		
		for (auto indiceArista : ladj[actual])
		{
			tint vecino = red[indiceArista].end;
			if (nivel[vecino] == -1 && red[indiceArista].flow < red[indiceArista].capacity) // Si bajo en uno el nivel y puedo mandar flujo en la red residual
			{
				nivel[vecino] = nivel[actual] + 1;
				nuevosVecinos.push_back(vecino);
			}
		}
		
		if (vecinos.empty())
		{
			swap(vecinos,nuevosVecinos);
			nuevosVecinos = {};
		}
	}
	return (nivel[t] != -1);
}

tint dfs (tint actual, tint flujo)
{
	if (flujo <= 0)
		return 0;
	else if (actual == t)
		return flujo;
	else
	{
		while (ultimoVecino[actual] < tint(ladj[actual].size()))
		{
			tint id = ladj[actual][ultimoVecino[actual]];
			
			if (nivel[red[id].end] == nivel[actual] + 1)
			{
				tint pushed = dfs (red[id].end,min(flujo, red[id].capacity - red[id].flow));
				
				if (pushed > 0)
				{
					red[id].flow += pushed;
					red[id^1].flow -= pushed;
					return pushed;
				}
			}
			ultimoVecino[actual]++;
			
		}
		return 0;	
	}
}

tint dinic ()
{
	tint flujo = 0;
	while (bfs())
	{
		
		forn(i,n+1)
			ultimoVecino[i] = 0;
		tint pushed = dfs(s,INFINITO);
		
		while (pushed > 0)
		{
			flujo += pushed;
			pushed = dfs(s,INFINITO);
		}
	}
	return flujo;
}

int main()
{
	//~ #ifdef ACMTUYO
		//~ assert(freopen("Dinic.in", "r", stdin));
	//~ #endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint m, caso = 1;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		forn(i,maxN)
		{
			ladj[i] = {};
			ultimoVecino[i] = 0;
			nivel[i] = 0;
		}
		red = {};
		forn(i,m)
		{
			tint a,b;
			cin >> a >> b;
			agregarArista(a,b,1);
		}
		cin >> s >> t;
		cout << "Case " << caso++ << ": ";
		if (dinic() >= 2)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}


