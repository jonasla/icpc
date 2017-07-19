#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint) n; i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint) n; i++)


int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	while (cin >> n)
	{
		vector<tint> f(n+1);
		forsn(i,1,n+1)
		{
			tint a;
			cin >> a;
			f[i] = a + f[i-1];
		}
		tint q;
		cin >> q;
		forn(query,q)
		{
			tint r;
			cin >> r;
			if (r > f[n])
				cout << "none\n";
			else
			{
				tint a = 1, b = n;
				if (f[a] >= r)
					b = 1;
				while (b - a > 1)
				{
					tint c = (a+b)/2;
					if (f[c] >= r)
						b = c;
					else
						a = c;
				}
				cout << b << "\n";
			}
		}
	}
	
	
	return 0;
}
