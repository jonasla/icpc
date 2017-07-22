#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,d;
	while (cin >> n >> d && n != 0 && d != 0)
	{
		vector<vector<tint> > v (d, vector<tint> (n));
		forn(i,d)
		forn(j,n)
			cin >> v[i][j];
		bool hayInterseccion = false;
		forn(j,n)
		{
			bool estaEnTodas = true;
			forn(i,d)
				estaEnTodas &= v[i][j];
			hayInterseccion |= estaEnTodas;
		}
		if (hayInterseccion)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}

