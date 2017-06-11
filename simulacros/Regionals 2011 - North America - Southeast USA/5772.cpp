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

const vector<tint> primos = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51,53};

void backTrack(tint &ans, tint i, tint n, tint armado, tint cantidadDivisores, tint last,bool esCuadrado)
{
	tint p = primos.size();
	if ((i == p && cantidadDivisores == n && !esCuadrado) or (i == p && cantidadDivisores == n-1 && esCuadrado))
		ans = min(ans,armado);
	else if (i < p)
	{
		
		tint r = 1;
		while (armado < min(ans,tint(4e18)/primos[i]) && cantidadDivisores <= n && r <= last)
		{

			backTrack(ans,i+1,n,armado,cantidadDivisores,r, (esCuadrado && (r % 2)));
			cantidadDivisores /= r;
			r++;
			armado *= primos[i];
			cantidadDivisores *= r;
			
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
	tint n;
	
	while (cin >> n && n != 0)
	{
		tint ans = 4e18;
		backTrack(ans,0,2*n,1,1,64,true);
		cout << ans << "\n";
	}
	return 0;
}



