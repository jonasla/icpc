#include <iostream>
#include <algorithm>

typedef long long tint;

#define forn(i,n) for(int i  = 0; i < int(n); i++)
#define forsn(i,j,n) for(int i  = j; i < int(n); i++)
using namespace std;

int main()
{
	tint m;
	cin >> m;
	forn(i,m)
	{
		tint n;
		cin >> n;
		cout << 2+n*(n-1) << endl;
	}
	return 0;
}
