#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)

int main()
{
	ldouble w,h;
	while (cin >> w >> h)
	{
		ldouble a = max(w,h), b = min(w,h);
		cout << fixed << showpoint << setprecision(16) << max(min(a/3.0,b),b/2.0) << "\n"; 
	}
	return 0;
}
