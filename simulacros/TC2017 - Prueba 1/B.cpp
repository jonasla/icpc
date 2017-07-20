#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint) n; i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint) n; i++)

const tint maxN = 131072;

tint pot[maxN];

int main()
{
	tint n,s,w,q;
	while (cin >> n >> s >> w >> q)
	{
		pot[0] = 1;
		forsn(i,1,n)
			pot[i] = (pot[i-1]*10) % q;
		vector<tint> a (n);
		tint g = s;
		forn(i,n)
		{
			a[i] = (g/7) % 10;
			if (g % 2 == 0)
				g = (g/2);
			else 
				g = (g/2) ^ w;
		}
		tint ans = 0, numero = 0, zero = 0;
		map<tint,tint> hist;
		forn(i,n)
		{
			zero += (a[i] == 0);
			numero = (numero * 10 + a[i]) % q;
			ans += hist[(numero*pot[n-i-1])%q] + (numero == 0);
			if (a[i] != 0)
				hist[(numero*pot[n-i-1])%q]++;
		}
		cout << ans - zero << "\n";
	}
	
	return 0;
}
