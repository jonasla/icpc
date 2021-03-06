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

struct Nodo
{
	tint num,fila,columna;
	Nodo (tint nn, tint ff, tint cc)
	{
		num = nn;
		fila = ff;
		columna = cc;
	}
	Nodo()
	{
		num = 0;
		fila = 0;
		columna = 0;
	}
};

const tint maxN = 1024;

int v[maxN][maxN], s[maxN][maxN];
Nodo sa[maxN][maxN], sb[maxN][maxN], mfb[maxN][maxN], mcfb[maxN][maxN], mfbTranspuesta[maxN][maxN];

void agrandarVentana (tint &r, deque<pair<tint,tint> > &rmq, Nodo ventana[])
{
	while (!rmq.empty() && rmq.back().first >= ventana[r].num)
		rmq.pop_back();
	rmq.push_back({ventana[r].num,r});
	r++;
	
}

void achicarVentana (tint &l, deque<pair<tint,tint> > &rmq)
{
	if (l == rmq.front().second)
		rmq.pop_front();
	l++;
}

pair<tint,tint> minimoVentana (deque<pair<tint,tint> > &rmq)
{
	return rmq.front();
}

int main()
{
	#ifdef ACMTUYO
		assert(freopen("pyramid.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	deque<pair<tint,tint> > rmq; // numero | indice
	tint l = 0, r = 0;
	return 0;
}
