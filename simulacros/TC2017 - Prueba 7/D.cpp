#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

typedef int tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

const vector<tint> w = {'@','.'};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint a,b;
	while (cin >> a >> b)
	{
		
		tint r = 315, c = 315;
		vector<vector<char> > q (r, vector<char> (c,'@'));
		forn(i,r/2)
		forn(j,c)
			q[i][j] = '.';
		
		a--;
		b--;
		forn(i, r/4 - 1)
		forn(j, c/2)
			if (a > 0)
			{
				q[2*i][2*j] = '@';
				a--;
			}
		
		forn(i, r/4 - 1)
		forn(j, c/2)
			if (b > 0)
			{
				q[2*i+r/2+1][2*j] = '.';
				b--;
			}
		cout << "315 315\n";
		forn(i,r)
		{
			forn(j,c)
				cout << q[i][j];
			cout << "\n";
		}
		cout << endl;
			
	}
	return 0;
}
