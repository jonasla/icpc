#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n); i++)

typedef long long tint;



int main()
{
	tint n,salida, llegada, maxN = 160;
	while (cin >> n >> salida >> llegada && n != 0 && salida != 0 && llegada != 0 )
	{
		vector<vector<tint> > w (maxN, vector<tint> (maxN,9999999999));
		forn(i,n)
		{
			tint m;
			cin >> m;
			vector<tint> f (m);
			forn(j,m)
			{
				tint floor;
				cin >> floor;
				f[j] = floor;
			}
			forn(j,m)
			forn(k,m)
				w[f[j]][f[k]] = min(w[f[j]][f[k]], abs(f[j]-f[k]));
			
		}
		forn(k,maxN)
		forn(i,maxN)
		forn(j,maxN)
			w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
		cout << w[salida][llegada] << endl;
	}
	
	return 0;
}
