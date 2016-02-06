#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>
#include <set>
#include <stdio.h>

using namespace std;

typedef long long tint;
typedef pair<tint, pair<tint, tint> > eje;
int N;

#define forn(i,n) for(tint i=0;i<(tint)(n);i++)
#define forsn(i,s,n) for(tint i=s;i<(tint)(n);i++)
#define debug(x) cout << #x << " = "  << x << endl

tint bfs(vector<set<tint> > &ladj, vector<vector<tint> > &w, tint b)
{
	tint n = w.size();
	vector<tint> d (n,b+2);
	deque<tint> vecinos;
	for (auto &v : ladj[0])
	{
		vecinos.push_back(v);
		d[v] = 0;
	}
	while (!vecinos.empty())
	{
		tint actual = vecinos.front();
		vecinos.pop_front();
		for (auto &v : ladj[actual])
		{
			if (d[actual] + w[actual][v] < d[v])
			{
				d[v] = d[actual] + w[actual][v];
				if (v != 0)
					vecinos.push_back(v);
			}
		}
	}
	return d[0]; 
	
	
}



int main()
{
	#ifdef ACMTUYO
		if (!freopen("09.in","r",stdin))
			return 1;
	#endif
	tint casos;
	cin >> casos;
	forn(test,casos)
	{
		tint b,p,q;
		cin >> b >> p >> q;
		vector<set<tint> > ladj (p+1);
		vector<vector<tint> > w (p+1,vector<tint> (p+1,b+1));
		forn(i,q)
		{
			tint pa;
			cin >> pa;
			w[0][pa] = 0;
			ladj[0].insert(pa);		
		}
		forsn(i,1,p+1)
		{
			tint r;
			cin >> r;
			forn(k,r)
			{
				tint g,pa;
				cin >> g >> pa;
				w[i][pa] = min(w[i][pa],g);
				ladj[i].insert(pa);
			}
		}
		tint sol = bfs(ladj,w,b),guitaUsher = 0, bolsa = sol;
		//cout << "sol = " << sol << endl;
		while (bolsa < b)
		{
			guitaUsher++;
			bolsa += sol -1; 
		}
		cout << guitaUsher << endl;
	}
	cin >> casos;
	return 0;
}
