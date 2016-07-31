#include <iostream>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forsn(i,s,n) for(int i=s;i<(int)n;i++)

using namespace std;

typedef long long tint;

int main()
{
	tint t;
	cin >> t;
	forn(caso,t)
	{
		tint n;
		cin >> n;
		vector<tint> cant(5);
		forn(i,n)
		{
			tint a;
			cin >> a;
			cant[a]++;
		}
		tint res = 0;
		res+= cant[4];
		tint mini = min(cant[1],cant[3]);
		res += mini;
		cant[1] -= mini;
		cant[3] -= mini;
		res += cant[3];
		res += cant[2]/2;
		cant[2] = cant[2] % 2;
		if (cant[2] > 0)
		{
			res++;
			cant[2]--;
			cant[1] -= 2;
		}
		res += (cant[1]+3)/4;
		cout << res << endl;
	}
	return 0;
}

