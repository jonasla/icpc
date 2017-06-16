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

int gcd (int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}


int main()
{
	#ifdef ACMTUYO
		assert(freopen("I.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t,q;
	while (cin >> t >> q && t != 0)
	{
		vector<int> tel (t);
		forn(i,t)
			cin >> tel[i];
		if (t == 1)
		{
			forn(k,q)
			{
				int s,d;
				cin >> s >> d;
				bool sePuede = (s == d or s == 2*tel[0]-d);
				if (k)
					cout << " ";
				if (sePuede)
					cout << "Y";
				else
					cout << "N";
					
			}
		}
		else
		{
			vector<int> diff (t-1);
			forn(i,t-1)
				diff[i] = tel[i] - tel[i+1];		
			int	acc = diff[0];
			forsn(i,1,t-1)
				acc = gcd(acc,diff[i]);
			
			forn(k,q)
			{
				bool sePuede = false;
				int s,d;
				cin >> s >> d;
				
				sePuede |= (( (d-s) % 2 == 0) && ( ((d-s)/2) % acc == 0));
				forn(i,t)
					sePuede |= (( (d+s-2*tel[i]) % 2 == 0) && ( ((d+s-2*tel[i])/2) % acc == 0));
				
				if (k)
					cout << " ";
				if (sePuede)
					cout << "Y";
				else
					cout << "N";
			}
		}
		cout << "\n";
		
		
		
			
		
	}
	return 0;
}




