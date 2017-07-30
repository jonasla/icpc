#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef int tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

const tint INFINITO = 2e9;

const tint maxN = 4096;

tint visitado[maxN];

void dfs (vector<vector<pair<tint,tint> > > &ladj, tint l, tint r, tint actual)
{
	visitado[actual] = true;
	for (auto x : ladj[actual])
		if (!visitado[x.first] && l <= x.second && x.second <= r)
			dfs(ladj,l,r,x.first);
}

bool estaConectado (tint start, tint end, vector<vector<pair<tint,tint> > > &ladj, tint l, tint r)
{
	tint n = ladj.size();
	forn(i,n)
		visitado[i] = 0;
	dfs(ladj,l,r,start);
	return visitado[end];
}

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,r,start,end;
	while (cin >> n >> r >> start >> end)
	{
		vector<tint> aristas (r);
		vector<vector<pair<tint,tint> > > ladj(n);
		forn(i,r)
		{
			tint from,to,length;
			cin >> from >> to >> length;
			ladj[from].push_back({to,length});
			ladj[to].push_back({from,length});
			aristas[i] = length;
		}
		sort(aristas.begin(),aristas.end());
		tint best = INFINITO, p = 0;
		forn(i,r)
		{
			
			while(p < r && !estaConectado(start, end, ladj,aristas[i],aristas[p]))
				p++;
			if (p < r)
				best = min(best,aristas[p]-aristas[i]);
			
		}
		if (best == INFINITO)
			cout << "NO PATH\n";
		else
			cout << best << "\n";
		
	}
	return 0;
}
