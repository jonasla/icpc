#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint) n; i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint) n; i++)

const tint maxB = 1 << 19;
const tint nmod = 1000000007;
const tint INFINITO = 2e18;
tint t [maxB];
tint c [maxB];
tint best [maxB];


int main()
{
	tint n;
	while (cin >> n)
	{
		vector<tint> f (n);
		forn(i,n)
			cin >> f[i];
		best[0] = 0;
		t[0] = 1;
		forsn(b,1,maxB)
		{
			c[b] = __builtin_popcount(b);
			best[b] = INFINITO;
			t[b] = 1;
			forn(i,n)
				if ((1 << i) & b)
				{
					t[b] = (t[b]*f[i]) % nmod;
					if ((1 << i) == b)
						best[b] = 0;
				}
		}
		tint tutti = (1 << n) -1;
		forsn(k,2,n+1)
		forn(b,(1<<n))
		{
			if (c[b] == k)
			{
				tint r = 0;
				do
				{
					best[b] = min(best[b],best[r] + best[b & (~r)] + t[r]*c[r] + t[b & (~r)]*c[b & (~r)]);
				}
				while (r = (r-b)&b);
			}
		}

		cout << best[tutti] << "\n";
	}
	return 0;
}
