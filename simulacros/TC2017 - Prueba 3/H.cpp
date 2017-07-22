#include <iostream>
#include <vector>
#include <algorithm>
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
		vector<tint> p (n), s(n);
		forn(i,n)
		{
			cin >> p[i];
			p[i]--;
			s[p[i]]++;
		}
		bool tuttiOne = true;
		forn(i,n)
			tuttiOne &= (s[i] == 1);
		if (tuttiOne)
		{
			vector<tint> palitos;
			forn(pasada,n+1)
			{
				forn(i,n-1)
				if (p[i] > p[i+1])
				{
					swap(p[i],p[i+1]);
					palitos.push_back(i+1);
				}
			}
			tint m = palitos.size();
			
			cout << m;
			forn(i,m)
				cout << " " << palitos[i];
			cout << "\n";
			
		}
		else
			cout << "No solution\n";
		
	}
	return 0;
}
