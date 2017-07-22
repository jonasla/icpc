#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

typedef int tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)

tint f (tint t, vector<vector<tint> > &v)
{
	tint n = v.size(), ans = 0;
	forn(i,n)
	{
		tint menores = 0, r = v[i].size();
		for (auto &x : v[i])
			menores += (x < t);
		ans += abs(2*menores - r);	
	}
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint n;
	while (cin >> n && n != 0)
	{
		vector<vector<tint> > v (n);
		forn(i,n)
		{
			tint k;
			cin >> k;
			forn(j,k)
			{
				tint r;
				cin >> r;
				v[i].push_back(r);
			}
		}
		//~ tint a = 0, b = 1001;
		//~ while (b-a > 10)
		//~ {
			//~ tint t1 = (2*a+b)/3, t2 = (a+2*b)/3;
			//~ if (f(t1,v) > f(t2,v))
				//~ a = t1;
			//~ else
				//~ b = t2;
		//~ }
		tint bestT = 2e9;
		//~ cout << a << " " << b << endl;
		forn(t,1001)
			bestT = min(bestT,f(t,v));
		cout << bestT << "\n";
		
	}
	
}
