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

tint best[maxN];
bool adentro[maxN];

void spfa (tint start, vector<vector<pair<tint,tint> > > &ladj)
{
	tint n = ladj.size();
	forn(i,n)
		best[i] = INFINITO;
	best[start] = 0;
	vector<tint> vecinos = {start}, nuevosVecinos;
	while (!vecinos.empty())
	{
		tint actual = vecinos.back();
		vecinos.pop_back();
		
		adentro[actual] = false;
		for (auto vecino : ladj[actual])
		{
			if (best[actual] + vecino.second < best[vecino.first])
			{
				best[vecino.first] = best[actual] + vecino.second;
				if (!adentro[vecino.first])
				{
					nuevosVecinos.push_back(vecino.first);
					adentro[vecino.first] = 1;
				}
			}
		}
		if (vecinos.empty())
			vecinos.swap(nuevosVecinos);
	}
}


int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	return 0;
}



