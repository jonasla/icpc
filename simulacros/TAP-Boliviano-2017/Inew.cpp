#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)
#define forsn(i,s,n) for (tint i = tint(s); i < tint (n); i++)

const tint maxD = 64;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint m,k;
	while (cin >> m >> k)
	{
		vector<tint> desarrollo (maxD,0);
		tint rr = maxD-1, mOrig = m;
		while (m > 0)
		{
			desarrollo[rr--] = (m%2);
			m /= 2;
		}
		tint ansPosta = 4611686018427387904;
	}
	return 0;	
}
