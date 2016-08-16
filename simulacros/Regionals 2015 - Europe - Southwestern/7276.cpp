#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <functional>
#include <sstream>
#include <stdio.h>



#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl


typedef long long tint;
typedef unsigned long long utint;

using namespace std;

struct Intervalo
{
	tint start, end;
	Intervalo(tint ss, tint ee)
	{
		start = ss;
		end = ee;
	}
};

bool operator < (Intervalo i1, Intervalo i2)
{
	return make_pair(i1.start, i1.end) < make_pair(i2.start, i2.end);
}

const tint nmod = 2147483647;

int main()
{
	tint n;
	while (cin >> n)
	{
		tint s,e;
		cin >> s >> e;
		map<Intervalo, tint> r = {{Intervalo(s,e),1}};
		forn(i,n-1)
		{
			map<Intervalo,tint> newR;
			tint m;
			cin >> m;
			for (auto x : r)
			{
				if (x.first.start < m)
					newR[Intervalo(x.first.start,m)] = (newR[Intervalo(x.first.start,m)] + x.second) % nmod;
				if (m < x.first.end)
					newR[Intervalo(m,x.first.end)] = (newR[Intervalo(m,x.first.end)] + x.second) % nmod;
			}
			r = newR;
		}
		tint ans = 0;
		for (auto x : r)
			ans = (ans + x.second) % nmod;
		cout << ans << endl;
	}
	return 0;
}
