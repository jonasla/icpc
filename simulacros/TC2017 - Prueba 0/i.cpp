#include <iostream>
#include <vector>

#define forn(i,n) for (int i = 0; i < (int) (n); i++)
#define forsn(i,s,n) for (int i = (s); i < (int) (n); i++)

typedef long long tint;

using namespace std;

tint mod (tint n, tint m)
{
	return ((n % m) + m ) % m;
}

int main()
{
	tint n;
	while (cin >> n && n != -1)
	{
		tint r = 0;
		tint e;
		tint ans = 0;
		forn(i,n) {
			cin >> e;
			r += e;
			if (r % 100 == 0) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
