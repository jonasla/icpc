#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

const tint maxD = 64;

int main()
{
	vector<tint> pot2 (maxD);
	tint cavegol = 1;
	forn(i,maxD)
	{
		pot2[i] = cavegol;
		cavegol *= 2;
	}
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint m,k;
	while (cin >> m >> k)
	{
		vector<tint> desarrollo (maxD,0);
		tint rr = maxD-1, mOrig = m;
		while (m > 0)
		{
			desarrollo[rr--] = (m%2);
			m /= 2;
		}
		
		tint maxUnos = 0;
		forn(d,2)
		{
			tint l = 0, r = 0;
			while (desarrollo[l] == 0)
				l++;
			r = l;
			while (l < maxD)
			{
				if (desarrollo[l] == d)
				{
					tint c = 0;
					while (r < maxD && desarrollo[r] == d)
					{
						c++;
						r++;
					}
					maxUnos = max(maxUnos,c);
				}
				else
					r++;
				l = r;
			}
		}
		if (maxUnos >= k)
			cout << mOrig << "\n";
		else
		{
			tint j = maxD-1;
			forn(i,k)
				desarrollo[j--] = 1;
			tint cantidadDeUnos = 0, p = maxD-1;
			while (desarrollo[p] == 1)
			{
				p--;
				cantidadDeUnos++;
			}
			tint w = maxD-1;
			forn(i,cantidadDeUnos-k)
				desarrollo[w--] = 0;
			tint ans = 0;
			forn(i,maxD)
				ans += desarrollo[i]*pot2[maxD-i-1];
			cout << ans << "\n";
		}
		
		
	}
	return 0;
}
