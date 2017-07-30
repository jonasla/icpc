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

const tint INFINITO = 2e15;

int main()
{
	//~ #ifdef ACMTUYO
		//~ assert(freopen("entrada.in", "r", stdin));
	//~ #endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint n;
	while (cin >> n && n != 0)
	{
		vector<tint> a (n);
		tint suma = 0;
		forn(i,n)
		{
			cin >> a[i];
			suma += a[i];
		}
		forn(i,n-1)
			a[i+1] += a[i];
			
		tint k = 3, best = INFINITO;
		while (k <= min(suma,n))
		{
			if (suma % k == 0)
			{
				vector<tint> restos (suma/k,0);
				
				forn(i,n)
					restos[a[i]%(suma/k)]++;
				if (*max_element(restos.begin(),restos.end()) >= k)
				best = min(best,n-k);
			}
			k++;
		}
		if (best == INFINITO)
			cout << "-1\n";
		else
			cout << best << "\n";
	}
	return 0;
}



