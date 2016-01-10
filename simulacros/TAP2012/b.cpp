#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>

#define forn(i,n) for (tint i = 0; i <(tint) (n); i++)
#define forsn(i,s,n) for (tint i = (s); i <(tint) (n); i++)

typedef long long tint;

using namespace std;

int main()
{
	tint n;
	cin >> n;
	while (n != -1)
	{
		tint total = 0;
		forsn(a,1,n+1)
		forsn(b,1,min((n/a),a)+1)
		{
			if ((n - a*b) % (a+b) == 0)
			{
				tint c = (n-a*b)/(a+b);
				if (c <= b)
					total++;
			}
		}
		cout << total << endl;
		
		cin >> n;
	}
	return 0;
}
