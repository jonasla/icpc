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

const vector<vector<tint> > filas = {{0,2,5,7},{0,3,6,10},{1,2,3,4},{1,5,8,11},{4,6,9,11},{7,8,9,10}};

void backTrack(tint &ans, vector<tint> &hex, vector<tint> &v,vector<tint> &usado, tint s)
{
	bool todoPiola = true;
	bool todoLleno = true;
	
	for (auto f : filas)
	{
		
		tint suma = 0,llenos = 0;
		for (auto x : f)
		{
			suma += hex[x];
			llenos += (hex[x] > 0);
		}
		if ((suma > s) or (llenos == 4 && suma < s))
			todoPiola = false;
		if (!todoPiola)
			break;
		todoLleno &= (llenos == 4);
	}
	if (todoPiola && todoLleno)
		ans++;
	else if (todoPiola)
	{
		
		forn(i,12)
		{
			if (hex[i] == 0)
			{
				forn(k,12)
				{
					if (!usado[k])
					{
						
						usado[k] = 1;
						hex[i] = v[k];
						backTrack(ans,hex,v,usado,s);
						usado[k] = 0;
						hex[i] = 0;
					}
				}
				break;
			}
			
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
	vector<tint> v (12);
	while (cin >> v[0] && v[0] != 0)
	{
		forsn(i,1,12)
			cin >> v[i];
		tint suma = 0;
		forn(i,12)
			suma += v[i];
		if (suma % 3)
			cout << "0\n";
		else
		{
			tint s = suma/3;
			tint ans = 0;
			vector<vector<tint> > hex (2, vector<tint> (12,0));
			vector<vector<tint> > usado (2, vector<tint> (12,0));
			vector<tint> aux = {0,2};
			
			forn(k,2)
			{
				hex[k][aux[k]] = v[0];
				usado[k][0] = 1;
				backTrack(ans,hex[k],v,usado[k],s);
			}
			
			
			cout << ans/2 << "\n";
		}
		
		
	}
	return 0;
}



