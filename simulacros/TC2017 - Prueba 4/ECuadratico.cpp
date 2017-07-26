#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;

typedef int tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

struct Intervalo
{
	tint start,end;
	Intervalo (tint ss, tint ee)
	{
		start = ss;
		end = ee;
	}
};

bool operator < (Intervalo i1, Intervalo i2)
{
	return make_pair(i1.end,i1.start) < make_pair(i2.end,i2.start);
}

const tint INFINITO = 2e9;

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
		tint n,m;
		cin >> n >> m;
		vector<Intervalo> v (m,Intervalo(0,0));
		forn(i,m)
		{
			tint s,e;
			cin >> s >> e;
			v[i] = Intervalo(s,e);
		}
		sort(v.begin(),v.end());

		vector<tint> bestEndingAt(m,INFINITO);
		forn(i,m)
		{
			if (v[i].start > 1)
			{
				forn(j,i)
					if (v[j].end >= v[i].start)
						bestEndingAt[i] = min(bestEndingAt[i],1+bestEndingAt[j]);
			}		
			else
				bestEndingAt[i] = 1;
		}
		tint ans = INFINITO;
		forn(i,m)
			if (v[i].end == n)
				ans = min(ans,bestEndingAt[i]);
		cout << ans << "\n";
		
			
	}
	return 0;
}

