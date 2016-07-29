#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int (i) = 0; i < int(n); i++)

using namespace std;

typedef long long tint;

struct Dumbell
{
	tint tam;
	vector<tint> costs;
	Dumbell(tint tamm, vector<tint> cc)
	{
		tam = tamm;
		costs = cc;
	}
	Dumbell()
	{
		tam = 0;
		costs = {};
	}
};

//bool operator < (Dumbell d1, Dumbell d2)
//{
//	return make_pair(d1.tam, d2.costs) < make_pair(d2.tam,d1.costs);
//}

int main()
{
	tint n,k;
	cin >> n >> k;
	map<tint, Dumbell> mapita;
	forn(i,n)
	{
		tint m,c;
		cin >> m >> c;
		mapita[m].tam++;
		mapita[m].costs.push_back(c);
	}
	
	vector<tint> ans, tamanos;
	for (auto x : mapita)
		tamanos.push_back(x.second.tam);		
	sort(tamanos.begin(),tamanos.end());
	reverse(tamanos.begin(),tamanos.end());
	if (tamanos.size() < k)
		cout << "0 0\n";
	else
	{
		tint tami = tamanos[k-1];
		for (auto x : mapita)
		{
			if (x.second.tam >= tami)
			{
				sort(x.second.costs.begin(),x.second.costs.end());
				reverse(x.second.costs.begin(), x.second.costs.end());
				//cout << x.first << " : [";
				//for (auto y : x.second.costs)
				//	cout << y << ",";
				//cout << "]\n";
				tint suma = 0;
				forn(i,tami)
					suma += x.second.costs[i];
				ans.push_back(suma);
			}		
		}
		sort(ans.begin(), ans.end());
		reverse(ans.begin(),ans.end());
		tint sumaPosta = 0;
		//cout << "tami = " << tami << endl;
		forn(i,k)
			sumaPosta += ans[i];
		cout << tami << " " << sumaPosta << endl;
	}
	
	return 0;
}
