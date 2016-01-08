#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

#define forn(i,n) for(int i = 0; i < (int) (n);i++)

using namespace std;

vector<int> listaDivisores (int n)
{
	vector<int> lista;
	int d = 1;
	while (d * d <= n)
	{
		if (n % d == 0)
		{
			lista.push_back(d);
			if (n/d != d)
				lista.push_back(n/d);
		}
		d++;
		
	}
	return lista;
}



int main()
{
	string s;
	cin >> s;
	while (s != "*")
	{
	int largo = s.size();
		vector<int> divList = listaDivisores(largo);
		sort(divList.begin(),divList.end());
		int ans;
		forn(i,divList.size())
		{
			int k = divList[i];
			string patron = s.substr(0,k);
			bool tuttiTrue = true;
			forn(j,largo/k)
			{
				if (patron != s.substr(k*j, k) )
				{
					tuttiTrue = false;
					break;
				}
				if (tuttiTrue)
					ans = k;
			}
			if (tuttiTrue)
				break;
		}
		cout << largo/ans << endl;
		cin >> s;
	}
	return 0;
}
