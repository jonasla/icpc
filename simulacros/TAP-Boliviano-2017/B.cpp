#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	while (cin >> n)
	{
		vector<tint> codigo(n-1);
		forn(i,n-2)
		{
			cin >> codigo[i];
			codigo[i]--;
		}
		codigo[n-2] = n-1;
		vector<tint> ultimaAparicion(n,-1);
		vector<bool> soyHoja (n,true);
		forn(i,n-1)
		{
			ultimaAparicion[codigo[i]] = i;
			soyHoja[codigo[i]] = false;
		}
		set<tint> hojas;
		forn(i,n)
			if (soyHoja[i])
				hojas.insert(i);
		tint momento = 0;
		vector<pair<tint,tint> > ans (n-1);
		while (momento < n-1)
		{
			tint hojita = *(hojas.begin());
			ans[momento] = {min(hojita+1,codigo[momento]+1),max(hojita+1,codigo[momento]+1)};
			if (ultimaAparicion[codigo[momento]] == momento)
				hojas.insert(codigo[momento]);
			hojas.erase(hojita);
			momento++;
		}
		sort(ans.begin(),ans.end());
		for (auto x : ans)
			cout << x.first << " " << x.second << "\n";
		
	}
	return 0;
}
