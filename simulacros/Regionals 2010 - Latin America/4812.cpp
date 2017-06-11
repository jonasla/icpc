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



void imprimirVector (vector<int> v)
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

struct Intervalo // [a,b]
{
	int start,end;
	Intervalo (int ss, int ee)
	{
		start = ss;
		end = ee;
	}
};

bool operator < (Intervalo i1, Intervalo i2)
{
	return make_pair(i1.end, i1.start) < make_pair(i2.end, i2.start);
}

const int nmod = 100000000;

int main()
{
	#ifdef ACMTUYO
		assert(freopen("H.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int m,n;
	while (cin >> m >> n && m != 0)
	{
		vector<Intervalo> v (n+1, Intervalo(-1,-1));
		forn(i,n)
		{
			int a,b;
			cin >> a >> b;
			v[i] = Intervalo(a,b);
		}
		
		sort(v.begin(),v.end());
		vector<vector<int> > cant (n+1, vector<int> (n+1,0) ); // cantidad de soluciones que usan el i-esimo y terminan completando todo hasta alli viniendo desde el j
		forn(i,n+1)
		{
			if (v[i].start == 0)
				cant[i][0] = 1;
			else
			{
				forn(j,i)
				if (v[j].end < v[i].end && v[j].start < v[i].start && v[j].end >= v[i].start) // el anterior tiene que terminar estrictamente antes, empezar estrictamente antes, pero terminar desde el comienzo del que estoy
					forn(k,j)
						if (v[k].end < v[i].start) // ademas, el del medio no tiene que quedar incluido en la union del anterior y el siguiente.
							cant[i][j] = (cant[i][j] + cant[j][k]) % nmod;
			}
		}
		
		int ans = 0;
		forn(i,n+1)
			if (v[i].end == m)
				forn(j,n)
					ans = (ans + cant[i][j]) % nmod;
		cout << ans << "\n";
		
		
		
		
		
		
	}
	return 0;
}




