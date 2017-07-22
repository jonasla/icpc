#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>


using namespace std;

typedef long long tint;


#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,q;
	while (cin >> n >> q && n != 0)
	{
		vector<string> juke(n);
		forn(i,n)
			cin >> juke[i];
		forn(query,q)
		{
			if (n == 1)
			{
				tint k;
				cin  >> k;
				cout << juke[0] << "\n";
			}
			else
			{
				tint largo = 1, pot = n, k;
				cin >> k;
				while (k - largo*pot > 0)
				{
					k -= largo*pot;
					pot *= n;
					largo++;
				}
				k--;
				vector<tint> des;
				tint p = k/largo, r = k%largo;
				while (p > 0)
				{
					des.push_back(p % n);
					p /= n;
				}
				while (tint (des.size()) < largo)
					des.push_back(0);
				reverse(des.begin(),des.end());
				cout << juke[des[r]] << "\n";
			}
			
		}
		cout << "\n";
		
	}
	return 0;
}
