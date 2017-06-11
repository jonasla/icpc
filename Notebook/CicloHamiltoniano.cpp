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

const tint INFINITO = 1e15;

tint minimumHamiltonianCycle (vector<vector<tint> > &d)
{
	tint r = d.size(), minHam = INFINITO;
	if (r > 1)
	{
		vector<vector<tint> > dp ((1 << r), vector<tint> (r,INFINITO));
		dp[1][0] = 0;
		for(tint mask = 1; mask < (1 << r); mask += 2)
		forn(i,r)
			if ( (i > 0) && (mask & (1 << i)) && (mask & 1) )
				forn(j,r)
					if ((i != j) && (mask & (1 << j)))
						dp[mask][i] = min(dp[mask][i],dp[mask ^ (1 << i)][j] + d[j][i]);
		
		forsn(i,1,r)
			minHam = min(minHam,dp[(1 << r) - 1][i] + d[i][0]);
	}
	else
		minHam = d[0][0];
	return minHam;
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



