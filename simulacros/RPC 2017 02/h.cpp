#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef long long tint;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define forsn(i,s,n) for(int i=(int)s; i<(int)n; i++)



struct Intervalo
{
	tint start, end;
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

const tint INFINITO = -2000000000000000000;

int main()
{
	tint n,k;
	while (cin >> n >> k)
	{
		vector<Intervalo> v (k,Intervalo(0,0));
		forn(i,k)
		{
			tint ss,ee;
			cin >> ss >> ee;
			v[i] = Intervalo(ss,ee);
		}
		
		sort(v.begin(),v.end());
		
		vector<tint> ans (k,INFINITO);
		vector<tint> maximo (k,INFINITO); 
		ans[0] = v[0].end - v[0].start+1;
		maximo[0] = v[0].end - v[0].start+1;
		forsn(i,1,k)
		{

			tint a = 0, b = i;
			while (b-a > 1)
			{
				tint c = (a+b)/2;
				if (c < i && v[c].end < v[i].start)
					a = c;
				else
					b = c;
			}
			tint j = a;
			if (v[j].end < v[i].start)
				ans[i] = maximo[j] + v[i].end - v[i].start+1;
			else
				ans[i] = v[i].end - v[i].start+1;
			maximo[i] = max(maximo[i-1],ans[i]);
		}
		
		
		
		cout << n - maximo[k-1] << "\n";
		
	}
	return 0;
}
