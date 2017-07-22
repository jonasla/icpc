#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint n;
	while (cin >> n && n != 0)
	{
		bool tuttiZero = true;
		deque<tint> t (n);
		forn(i,n)
		{
			cin >> t[i];
			tuttiZero &= (t[i] == 0);
		}
		if (tuttiZero)
			cout << (n+1)/2 << "\n";
		else
		{
			while (t.front() != 1)
			{
				t.pop_front();
				t.push_back(0);
			}
			vector<tint> l;
			tint r = 2;
			forn(i,n)
			{
				if (t[i] == 0)
					r += 2;
				else
				{
					l.push_back(r);
					r = 2;
				}
			}
			l.push_back(r);
			tint ans = 0;
			for (auto x : l)
				ans += (x-1)/4;
			cout << ans << "\n";
			
		}
	}
	
}

