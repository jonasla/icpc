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

const tint INFINITO = 1e15;

void dijkstra (tint comienzo, vector<vector<pair<tint,tint> > > &ladj, vector<tint> &distance, vector<vector<tint> > &parent)
{
	priority_queue <pair<tint,tint> > q; // {-peso,indice}
	tint n = distance.size();
	forn(i,n)
		distance[i] = (i != comienzo)*INFINITO;
	vector<tint> procesado (n,0);
	q.push({0,comienzo});
	while (!q.empty())
	{
		tint actual = q.top().second;
		q.pop();
		if (!procesado[actual])
		{
			procesado[actual] = 1;
			for (auto vecino : ladj[actual])
			{
				if (distance[actual] + vecino.second < distance[vecino.first])
				{
					distance[vecino.first] = distance[actual] + vecino.second;
					q.push({-distance[vecino.first],vecino.first});
					parent[vecino.first] = {actual};
				}
				else if (distance[actual] + vecino.second == distance[vecino.first])
					parent[vecino.first].push_back(actual);
			}
		}
		
	}
}

int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	// ladj : Por cada vertice, un par {indice,peso}
	// 
	return 0;
}
