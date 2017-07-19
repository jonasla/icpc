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
	tint W,H,w,h;
	while (cin >> W >> H >> w >> h)
	{
		tint a = W/(2*w) + ((W % (2*w)) >= w);
		tint b = H/(2*h) + ((H % (2*h)) >= h);
		cout << a*b << "\n";
		
	}
	return 0;
}
