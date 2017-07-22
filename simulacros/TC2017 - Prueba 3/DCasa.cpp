#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>


using namespace std;

typedef long long tint;


#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,r, genoma = 1;
	while (cin >> n >> r && n != 0)
	{	
		cout << "Genome " << genoma++ << "\n";
		vector<tint> s (r), e (r);
		forn(i,r)
			cin >> s[i] >> e[i];
		tint q;
		cin >> q;
		forn(query,q)
		{
			
			tint k;
			cin >> k;
			forn(i,r)
			{
				if (s[i] <= k && k <= e[i] && k <= ((s[i]+e[i]) / 2))
					k = e[i] - (k - s[i]);
				else if (s[i] <= k && k <= e[i])
					k = s[i] + e[i] - k;	
			}
			cout << k << "\n";
		}
	}
	return 0;
}
