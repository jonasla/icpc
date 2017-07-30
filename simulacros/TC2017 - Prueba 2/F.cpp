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
	tint n,p,k,d;
	while (cin >> n >> p >> k >> d)
	{
		tint r = (d*(d-1))/2;
		vector<tint> ans (n, (p-r)/n);
		forn(i,d)
			ans[d-i-1] += i;
		ans[0] += (p-r) % n;
		set<tint> v;
		forn(i,k)
			v.insert(ans[i]);
		if (tint(v.size()) == d)
			forn(i,n)
				cout << ans[i] << "\n";
		else
			cout << "Wrong information\n";
	}
	return 0;
}
