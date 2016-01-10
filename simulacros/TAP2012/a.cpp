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
#include <tuple>
#include <functional>
#include <unordered_set>
#include <unordered_map>
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

void imprimirVector (vector<int> v)
{
	if (!v.empty())
	{ 
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}
	else
		cout << "[]" << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n != -1)
	{
		vector<int> v (n+1);
		forn(i,n)
			cin >> v[i+1];
		int caja = 1;
		while (caja < n+1)
		{
			if (v[caja] == caja)
			{
				v[caja] = 0;
				forsn(i,1,caja)
					v[i]++;
				caja = 1;
			}
			else
				caja++;
		}
		bool tuttiCero = true;
		forsn(i,1,n+1)
			tuttiCero &= (v[i] == 0);
		if (tuttiCero)
			cout << "S" << endl;
		else
			cout << "N" << endl;
		cin >> n;
	}
	return 0;
}



