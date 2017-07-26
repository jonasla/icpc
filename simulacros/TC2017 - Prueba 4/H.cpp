#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

const tint maxProblem = 9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint casos;
	cin >> casos;
	forn(caso,casos)
	{
		if (caso)
			cout << "\n";
		tint n;
		cin >> n;
		vector<map<string,tint> > ac (maxProblem);
		vector<map<string,ldouble> > su (maxProblem);
		vector<map<string,ldouble> > ti (maxProblem);
		forn(submission,n)
		{
			ldouble time;
			string team;
			char problem,veredict;
			cin >> time >> team >> problem >> veredict;
			if (!ac[problem-'A'][team])
			{
				su[problem-'A'][team] -= 1.0;
				if (veredict == 'A')
				{
					ac[problem-'A'][team] = 1;
					ti[problem-'A'][team] = time;
					su[problem-'A'][team] *= -1;
				}
			}
		}
		forn(p,maxProblem)
		{
			tint totalAc = 0;
			for (auto a : ac[p])
				totalAc += a.second;
			ldouble avSu = 0.0, avTi = 0.0;
			for (auto s : su[p])
				avSu += (s.second)*(s.second > 0);
			for (auto t : ti[p])
				avTi += t.second;
			
			cout << char('A' + p) << " " << totalAc;
			if (totalAc > 0)
			{
				avSu = avSu / ldouble(totalAc);
				avTi = avTi / ldouble(totalAc);
				cout << " " << fixed << showpoint << setprecision(2) << avSu << " " << avTi;
			}
			cout << "\n";
		}
	}
	return 0;
}

