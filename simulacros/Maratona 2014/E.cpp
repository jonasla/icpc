#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (tint)(s); i < (tint)(n); i++)

int main()
{
	tint n,r;
	while (cin >> n >> r)
	{
		vector<tint> w (n,1);
		forn(i,r)
		{
			tint x;
			cin >> x;
			w[x-1] = 0;
		}
		bool soyPrimero = true;
		forn(i,n)
		{
			if (w[i] == 1)
			{
				if (!soyPrimero)
					cout << " ";
				soyPrimero = false;
				cout << i+1;
			}
		}
		if (n == r)
			cout << "*";
		cout << "\n";
	}
}
