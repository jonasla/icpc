#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < (tint) n; i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint) n; i++)

//~ ldouble epsilon = 1e-15;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	while (cin >> n)
	{
		vector<ldouble> x (n);
		forn(i,n)
			cin >> x[i];
		sort(x.begin(),x.end());
		ldouble lastParche = x[0] + 1.0;
		tint ans = 1;
		forsn(i,1,n)
		{
			if (x[i] > lastParche)
			{
				lastParche = x[i] + 1.0;
				ans++;
			}
		}
		cout << ans << "\n";
		
	}
	return 0;
}
