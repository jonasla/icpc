#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define forsn(i,s,n) for(int i=int(s); i<(int)n; i++)

typedef long long tint;

int main()
{
	tint n,l,c;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n >> l >> c)
	{
		vector<tint> k (n);
		forn(i,n)
			cin >> k[i];
		sort(k.begin(),k.end());
		reverse(k.begin(),k.end());
		tint r = 0;
		bool gane = true;
		for(tint i = 0; i < n; i += l)
		{
			if (c - r >= k[i])
				r += k[i];
			else
				gane = false;
		}
		
		if (gane)
			cout << "S\n";
		else
			cout << "N\n";
	}
}
