#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <utility>

using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n); i++)
#define forsn(i,s,n) for(int i = s; i < (int) (n); i++)

struct Submission
{
	int team,problem;
	string time;
	Submission (char tt, int pp, string ttime)
	{
		team = tt;
		problem = pp;
		time = ttime;
	}
};

bool operator < (Submission s1, Submission s2)
{
	return s1.time < s2.time;
}

int main()
{
	int t,p,s;
	while (cin >> t >> p >> s && t != 0 && p != 0 && s != 0)
	{
		vector<vector<bool> > w (t,vector<bool> (p,false));
		vector<int> team (t,0);
		vector<int> solved (p,0);
		vector<Submission> sub;
		forn(i,s)
		{
			int problem;
			char eq;
			bool result;
			string time,sResult;
			cin >> problem >> eq >> time >> sResult;
			result = (sResult[0] == 'Y');
			if (sResult[0] != 'Y')
			{
				cin >> sResult >> sResult;
				if (sResult[0] == 'T')
					cin >> sResult >> sResult ;
				else 
					cin >> sResult;
			}
			if (result)
				sub.push_back(Submission(problem,eq,time));
		}
		sort(sub.begin(),sub.end());
		string start = "--:--:--", end = "--:--:--";
		bool flag = false;
		for (auto su : sub)
		{
			if (!w[su.team-1][su.problem - 'A'])
			{
				solved[su.problem - 'A']++;
				team[su.team-1]++;
				w[su.team-1][su.problem - 'A'] = true;
			}
			for (auto x : team)
			{ 
				if (x == p && start[0] != '-' && !flag)
				{
					end = su.time;
					flag = true;
				}
				else if (x == p)
					flag = true;
			}		
			for (auto x : solved)
			{
				if (x == t && start[0] != '-' && !flag)
				{
					end = su.time;
					flag = true;
				}
				else if (x == t)
					flag = true;
			}
			if (flag)
				break;
			bool tuttiMayor = true;
			if (start[0] == '-')
			{
				for (auto x : team)
					tuttiMayor &= (x > 0);		
				for (auto x : solved)
					tuttiMayor &= (x > 0);
			}
			if (tuttiMayor)
				start = su.time;
		} 
		cout << start << " " << end << endl;
	}
}
