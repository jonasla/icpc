#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long tint;

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)

int main()
{
	vector<tint> tutti = {1,1,1};
	tint tests = 1;
	forsn(i,3,1000)
		tutti.push_back(tutti[i-1] + tutti[i-2] + tutti[i-3]);
	tint n;
	while (cin >> n && n != 0)
	{
		cout << "Case " << tests << ": " << tutti[n-1] << endl;
		tests++;
	}
	return 0;
}
