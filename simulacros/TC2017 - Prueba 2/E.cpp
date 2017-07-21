#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)

int main()
{
	ios:: sync_with_stdio(false);
	cin.tie(NULL);
	tint r,c;
	while (cin >> r >> c)
	{
		vector<vector<tint> > v (r, vector<tint> (c));
		forn(i,r)
		forn(j,c)
			cin >> v[i][j];
		tint ans = 0;
		forn(i,r)
		forn(j,c)
		{
			bool derecha = true, izquierda = true, arriba = true, abajo = true;
			forn(k,j)
				izquierda &= (v[i][k] < v[i][j]);
			forsn(k,j+1,c)
				derecha &= (v[i][k] < v[i][j]);
			forn(k,i)
				arriba &= (v[k][j] < v[i][j]);
			forsn(k,i+1,r)
				abajo &= (v[k][j] < v[i][j]);
			ans += derecha + izquierda + arriba + abajo;
		}
		cout << ans << "\n";
	}
	return 0;
}
