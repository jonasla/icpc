#include <iostream>
#include <string>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	while (cin >> n)
	{
		
		forn(i,n)
		{
			tint a;
			cin >> a;
			if (a <= 2)
				cout << a << "\n";
			else
				cout << 3*a-5 << "\n";
		}
	}
	return 0;
}
