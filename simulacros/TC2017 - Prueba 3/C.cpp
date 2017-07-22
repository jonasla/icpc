#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>


using namespace std;

typedef long long tint;


#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

vector<tint> desB(tint b, tint k)
{
	vector<tint> des;
	while (k > 0)
	{
		des.push_back(k % b);
		k /= b;
	}
	return des;
	
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint n,q;
	while (cin >> n >> q && n != 0)
	{	
		vector<string> juke (n);
		forn(i,n)
			cin >> juke[i];
		if (n == 1)
		{
			forn(query,q)
			{
				tint k;
				cin >> k;
				cout << juke[0] << "\n";
			}
		}	
		else
		{		
			forn(query,q)
			{
				tint k;
				cin  >> k;
				
				tint largo = 1, pot = n;
				while (k - largo*pot > 0)
				{
					k -= largo*pot;
					largo++;
					pot *= n;
				}
				k--;
				tint palabra = k/largo, indice = k % largo;
				vector<tint> des = desB(n,palabra);
				while (tint(des.size()) < largo)
					des.push_back(0);
				reverse(des.begin(),des.end());
				

				cout << juke[des[indice]] << "\n";
			}
			cout << "\n";
		}
	}
	return 0;
}
