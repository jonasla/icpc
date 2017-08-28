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
#include <bitset>
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


const tint maxF = 1 << 15;
const tint zero = 1 << 14;

vector<vector<bitset<maxF> > > sumas (2, vector<bitset<maxF> > (2));


int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint n,f;
	while (cin >> n >> f && n != 0)
	{
		string ans (n,'.');
		vector<tint> a (n);
		forn(i,n)
			cin >> a[i];
		forn(i,n)
		{
			
			forn(r,2)
			forn(w,2)
				sumas[r][w].reset();	
			sumas[0][0].set(zero+a[i]);
			sumas[1][0].set(zero-a[i]);
			tint actual = 0;
			
			forn(j,n)
				if (i != j)
				{
					forn(r,2)
					{
						forn(k,maxF)
							if (sumas[r][actual%2][k])
								for(tint p = -1; p <= 1; p += 2)
									if (0 <= k+p*a[j] && k+p*a[j] < maxF)
										sumas[r][(actual+1)%2].set(k+p*a[j]);
					}
					forn(r,2)
						sumas[r][actual%2].reset();
					actual++;
				}
			
			if (sumas[0][actual%2][zero+f] && sumas[1][actual%2][zero+f])
				ans[i] = '?';
			else if (sumas[0][actual%2][zero+f] && !sumas[1][actual%2][zero+f])
				ans[i] = '+';
			else if (!sumas[0][actual%2][zero+f] && sumas[1][actual%2][zero+f])
				ans[i] = '-';
			else
			{
				ans = "*";
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}



