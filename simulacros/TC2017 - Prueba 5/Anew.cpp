#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forsn(i,s,n) for(int i=(tint)s; i<(tint)n; i++) 
#define forn(i,n) forsn(i,0,n) 

const tint INFINITO = 2e18;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint c,n;
	while (cin >> c >> n)
	{
		vector<vector<tint> > m (n, vector<tint> (n));
		forn(i,n)
		forn(j,n-i)
		{
			cin >> m[i][j];
			m[i][j] += c;
		}
		vector<tint> best(n,INFINITO);
		best[0] = m[0][0];
		forsn(i,1,n)
		forn(j,i)
			best[i] = min(best[i],best[j] + m[j][i]);
		for (auto x : best)
			cout << x << " ";
		cout << endl;
		cout << best[n-1] << "\n";
	}
	
	
	return 0;
}
