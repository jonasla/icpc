#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long tint;

#define forn(i,n) for(tint i = 0; i < (tint)(n); i++)

tint f (tint a, tint b, tint c, tint i, tint j)
{
	return a*abs(i-j)*abs(i-j) + b*abs(i-j) + c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint t;
	cin >> t;
	forn(caso,t)
	{
		tint n,a,b,c;
		cin >> n >> a >> b >> c;
		vector<tint> r (n);
		forn(i,n)
			cin >> r[i];
		sort(r.begin(),r.end());
		vector<tint> p (n);
		tint s = 0;
		forn(i,(n+1)/2)
			p[s++] = r[2*i];
		forn(i,n/2)
			p[s++] = r[n-1-n%2-2*i];
		//~ for (auto x : p)
			//~ cout << x << " ";
		//~ cout << endl;
		tint k = n/2, mini = 1e18;
		forn(mask, (1LL << k))	
		{
			tint ans = 0;
			forn(j,k)
				if (mask & j)
					swap(p[j],p[n-j-1]);
			forn(i,n)
			forn(j,n)
			{
				ans += p[i]*p[j]*f(a,b,c,i,j);
			}
			mini = min(mini,ans);
			forn(j,k)
				if (mask & j)
					swap(p[j],p[n-j-1]);
			
		}
		tint num = mini, denom = 10000;
		while (num % 2 == 0 && denom % 2 == 0)
		{
			num /= 2;
			denom /= 2;
		}
		while (num % 5 == 0 && denom % 5 == 0)
		{
			num /= 5;
			denom /= 5;
		}
		cout << num << "/" << denom << "\n";
		
	}
	return 0;
}
