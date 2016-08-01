#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

typedef long long tint;

#define forn(i,n) for(int i=0; i<(int)n; i++)

struct Boss
{
	tint pelear,stars,id,super;
	Boss(tint pp, tint ss, tint ii, tint ssss)
	{
		pelear = pp;
		stars = ss;
		id = ii;
		super = ssss;
	}
};

bool operator < (Boss b1, Boss b2)
{
	return make_tuple(b1.pelear,b2.stars) > make_tuple(b2.pelear,b1.stars);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint t;
	cin >> t;
	forn(caso,t)
	{
		priority_queue<Boss> bosses;
		//vector<Boss> v;
		
		tint n;
		cin >> n;
		vector<int> sps(n);
		forn(i,n)
		{
			tint p,sp;
			cin >> p >> sp;
			bosses.push(Boss(p,1,i,0));
			sps[i] = sp;
			//v.push_back(Boss(p,1,i,0));
			//v.push_back(Boss(sp,2,i,1));
		}
		//sort(v.begin(),v.end());
		tint compro = 0, stars = 0;
		//for(auto boss : v)
		while(!bosses.empty())
		{
			Boss boss = bosses.top(); bosses.pop();
			//cout << "BOSS = (" << boss.pelear << ", " << boss.stars << ", " << boss.id << ", " << boss.super << ")" << endl;
			if (boss.pelear > stars)
			{
				compro += boss.pelear - stars;
				stars = boss.pelear;
	
			}
			if(!boss.super){
					//cout << "agrego super\n";
					int id = boss.id;
					int sp = sps[id];
					bosses.push(Boss(sp,2,id,1));
			}
			stars += boss.stars;
		}
		cout << compro << "\n";
	}
	return 0;
}
