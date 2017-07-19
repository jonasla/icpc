#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < (tint) n; i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint) n; i++)


const ldouble INFINITO = 1e15;
const ldouble epsilon = 1e-9;

ldouble f(ldouble a, ldouble b, ldouble c, ldouble d)
{
	if (a < c or b < d)
		return INFINITO;
	else
	{
		ldouble w = a, h = b;
		tint ans = 0;
		while (w > c)
		{
			w /= 2.0;
			ans++;
		}
		while (h > d)
		{
			h /= 2.0;
			ans++;
		}
		return ans;
	}
}

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ldouble a,b,c,d;
	while (cin >> a >> b >> c >> d)
	{
		if (abs(min(f(a,b,c,d),f(b,a,c,d)) - INFINITO) < epsilon)
			cout << "-1\n";
		else
			cout << min(f(a,b,c,d),f(b,a,c,d)) << "\n";
	}
	
	return 0;
}
