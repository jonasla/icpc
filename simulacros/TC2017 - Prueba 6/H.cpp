#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

int main()
{
	
	tint w,h,ax,ay,bx,by;
	while (cin >> w >> h >> ax >> ay >> bx >> by)
	{
		if (abs(ax-bx) > 1)
			cout << min(ax,bx) + 1 << " " << 0 << " " << min(ax,bx) + 1 << " " << h << "\n";
		else if (abs(ay-by) > 1)
			cout << 0 << " " << min(ay,by) + 1 << " " << w << " " << min(ay,by) + 1 << "\n";
		else if (ax == bx)
			cout << 0 << " " << max(ay,by) << " " << w << " " << min(ay,by) << "\n";
		else if (ay == by)
			cout << min(ax,bx) << " " << 0 << " " << max(ax,bx) << " " << h << "\n";
		
	}
	return 0;
}
