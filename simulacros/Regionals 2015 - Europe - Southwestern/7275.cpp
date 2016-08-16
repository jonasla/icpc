#include <iostream>
#include <vector>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)

typedef long long tint;

int main()
{
	tint n,m;
	tint caso = 0;
	while (cin >> n >> m)
	{
		vector<tint> p (50);
		forn(i,n)
		forn(j,m)
			p[i+j+2]++;
		tint maxi = -1;
		forn(i,50)
			maxi = max(maxi,p[i]);
		if (caso)
			cout << endl;
		forn(i,50)
			if (p[i] == maxi)
				cout << i << endl;
		caso++;	
	}
	
	return 0;
}
