#include <iostream>
#include <vector>

#define forn(i,n) for(int (i) = 0; i < int (n); i++)
#define forsn(i,s,n) for(int (i) = s; i < int (n); i++)

typedef unsigned long long utint;
typedef long long tint;

const int maxN = 1000050;

using namespace std;

int main()
{
	int t;
	cin >> t;
	vector<tint> ans(maxN,1);
	ans[1] = 1;
	forsn(i,2,maxN)
		ans[i] = (1 + i*ans[i-1] % 1000003);
	forn(i,t)
	{
		tint n;
		cin >> n;
		cout << ans[n] << endl;
	}
	
	
	return 0;
	
}	

