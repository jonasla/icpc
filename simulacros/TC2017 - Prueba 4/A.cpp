#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

const ldouble pi = acos(-1);
const ldouble epsilon = 1e-4;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint RR,rr;
	while (cin >> RR >> rr)
	{
		if (RR < rr)
			cout << "Coin cannot fit in tray.\n";
		else
		{
			if (2*rr > RR)
				cout << 1 << " coin of size " << rr << " will fit the inner rim of a tray of size " << RR << ".\n";
			else
			{
				ldouble R = ldouble(RR), r = ldouble(rr);
				ldouble a = R-r, b = R-r, c = 2*r;
				ldouble alfa = acos((a*a+b*b-c*c)/(2*a*b));
				//~ cout << (a*a+b*b-c*c)/(2*a*b) << endl;
				if (alfa < 0)
					alfa += 2*pi;
				tint ans = 2*pi/alfa + epsilon;
				cout << ans << " coins of size " << rr << " will fit the inner rim of a tray of size " << RR << ".\n";
			}
			
		}
	}
	return 0;
}
