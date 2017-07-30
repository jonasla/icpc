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

// CRIBA

//const tint maxN = 1000500;
//int p[maxN + 1] = {1, 1};
//tint phi[maxN]; // DAR CHANGUI DE 500 O MAS

//
//map<tint,tint> factorizar (tint n)
//{
//	map<tint,tint> f;
//	while (n > 1) 
//	{ 
//		f[p[n]]++;
//		n /= p[n]; 
//	}
//	return f;
//}
// ESTO VA EN EL MAIN
//	for (int i = 1; i <= maxN; ++i)
//		if (p[i] == 1)
//			for (int j = i; j <= maxN; j += i)
//				p[j] = i;
//for (tint i = 0; i < maxN; i++) 
//		phi[i] = i;	
//	for (tint i = 1; i < maxN; i++)
//		for (tint j = 2 * i; j < maxN; j += i)
//			phi[j] -= phi[i];

void add (tint k, tint x, vector<tint> &fenwick)
{
	tint n = fenwick.size() -1;
	while (k <= n)
	{
		fenwick[k] += x;
		k += (k & -k);
	}
}

tint sum (tint k, vector<tint> &fenwick)
{
	tint s = 0;
	while (k >= 1)
	{
		s += fenwick[k];
		k -= (k & -k);
	}
	return s;
}
 

int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint n;
	cin >> n;
	vector<tint> fenwick (n+1,0);
	forn(i,n)
	{
		tint a;
		cin >> a;
		add(i+1,a,fenwick);
	}
	imprimirVector(fenwick);
	forn(i,n)
		cout << sum(i,fenwick) << "\n";
	
	
	return 0;
}



