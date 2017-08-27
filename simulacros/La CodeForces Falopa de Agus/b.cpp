#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for(tint i = 0; i < (tint) (n); i++)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	tint n,x;
	vector<vector<tint> > v = {{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1}};
	while(cin >> n >> x)
		cout << v[n%6][x] << "\n";
	
	return 0;
}
