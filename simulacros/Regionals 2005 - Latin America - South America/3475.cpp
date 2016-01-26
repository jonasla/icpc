#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>

typedef long long tint;
#define forn(i,n) for(tint i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(tint i=s;i<(int)(n);i++)

using namespace std;

int main()
{
	tint n;
	while (cin >> n && n != 0)
	{
		vector<bool> used (n+1,false); // indexo de 1
		vector<tint> perm (n+1); // indexo de 1
		forsn(i,1,n+1)
		{
			tint p;
			cin >> p;
			perm[p] = i;
			used[p] = true;
		}
		bool flag = false;
		forsn(i,1,n+1)
			if (!used[i])
			{
				cout << "No solution" << endl;
				flag = true;
				break;
			}
		if (!flag)
		{
			vector<tint> ans;
			forsn(i,1,n+1)
			{
				while (perm[i] != i)
				{
					forsn(j,i,n+1)
					{
						if (perm[j] == i && j > 1)
						{
							swap(perm[j],perm[j-1]);
							ans.push_back(j-1);
						}
					}
				}

			}
			reverse(ans.begin(),ans.end());
			cout << ans.size();
			for(auto x : ans)
				cout << " " << x;
			cout << endl;
		}
	}
	return 0;
}
