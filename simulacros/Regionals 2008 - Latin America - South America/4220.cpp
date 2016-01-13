#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


#define forn(i,n) for(int (i) = 0; (i) < (int)(n); i++ )
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define debug(x) cout << #x << " = "  << x << endl


typedef long long tint;
using namespace std;

bool sePuede (tint lado, vector<tint> &arco, tint qarcos)
{
	tint n = arco.size();
	map<tint, tint> resto;
	tint suma = 0;
	forn(i,n)
	{
		suma = (suma + arco[i]) % lado;
		resto[suma]++;
	}
	tint maxi = -2;
	for(auto r : resto)
		maxi = max(maxi,r.second);
	return (maxi >= qarcos);
}

int main()
{
	tint n;
	while(cin >> n && n != 0)
	{
		tint suma = 0;
		vector<tint> arco (n);
		forn(i,n)
		{
			cin >> arco[i];
			suma += arco[i];
		}
		bool gane = false;
		for(tint qarcos = n; qarcos >= 3; qarcos--)
		{
			if (suma % qarcos == 0 && sePuede(suma/qarcos,arco,qarcos))
			{
				gane = true;
				cout << n - qarcos << endl;
				break;
			}
		}
		if (!gane)
			cout << -1 << endl;
	}
	return 0;
}

