#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)

typedef long long tint;
typedef vector<tint> vi;

int main() 
{
	string s;
	while (cin >> s)
	{
		int n = s.size();
		vector<int> lis (n,1);
		forn(i,n)
		forn(j,i)
			if (s[j] < s[i])
				lis[i] = max(lis[j] + 1, lis[i]);
		cout << 26 - *max_element(lis.begin(),lis.end()) << "\n";
	} 
	return 0;
}
