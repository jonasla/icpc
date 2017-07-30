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

const tint INFINITO = 1e8;


struct Arista
{
	tint end,soyPuente,indice,grado1;
	Arista (tint ee, tint ss, tint ii, tint gg)
	{
		end = ee;
		soyPuente = ss;
		indice = ii;
		grado1 = gg;
	}
};

tint timer,n;
const tint maxN = 131072;
bool usado[maxN];
tint highest[maxN], tIn[maxN], tOut[maxN]; 

void bridges (tint actual, tint padre, vector<vector<Arista> > &ladj, vector<tint> &puente)
{
	usado[actual] = true;
	tIn[actual] = timer;
	highest[actual] = timer;
	timer++;
	bool yaIgnore = false;
	for (auto &arista : ladj[actual])
	{
		tint vecino = arista.end;
		if (vecino != padre || yaIgnore)
		{
			if (usado[vecino])
				highest[actual] = min(highest[actual],tIn[vecino]);
			else
			{
				bridges(vecino,actual,ladj,puente);
				highest[actual] = min(highest[actual],highest[vecino]);
				if (highest[vecino] > tIn[actual])
					puente[arista.indice] = 1;
			}
		}
		else
			yaIgnore = true;
	}
	tOut[actual] = timer++;
}

void find_bridges(vector<vector<Arista> > &ladj, vector<tint> &puente)
{
    timer = 0;
    forn(i,n)
        usado[i] = false;
    forn(i,n)
        if (!usado[i])
            bridges(i,-1,ladj,puente);
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
