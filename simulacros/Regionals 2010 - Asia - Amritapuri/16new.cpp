#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <map>
#include <queue>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (tint)(s); i < (tint)(n); i++)

unordered_set<tint> solutions;
const tint maxN = 71;
unordered_set<tint> yaPase [maxN];
tint m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint t;
	cin >> t;
	forn(caso,t)
	{
		tint n;
		cin >> n >> m;
		solutions.clear();
		forn(i,n+1)
			yaPase[i].clear();
		queue<pair<tint,tint> > vecinos;
		vecinos.push({n,1});
		yaPase[n].insert(1);
		
		while (!vecinos.empty())
		{
			pair<tint,tint> actual = vecinos.front();
			vecinos.pop();
			
			forsn(i,1,actual.first+1)
			{
				pair<tint,tint> v = {actual.first-i,(actual.second*i)%m};
				if ( (yaPase[v.first].find(v.second) == yaPase[v.first].end()) && v.first >= 0)
				{
					if (v.first == 0)
						solutions.insert(v.second);
					else
					{
						vecinos.push(v);
						yaPase[v.first].insert(v.second);
					}
				}
			}
		}
		cout << solutions.size() << "\n";
	}
	
	return 0;
}

