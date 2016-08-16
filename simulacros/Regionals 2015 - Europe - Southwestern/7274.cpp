#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)

typedef long long tint;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int T; cin >> T;
	while(T--){
		int N; cin >> N;
		multiset<tint> nums;
		forn(i,N){
			int e; cin >> e;
			nums.insert(e);
		}
		tint total = 0;
		while(nums.size() > 1){
			tint t1 = *nums.begin();
			nums.erase(nums.begin());
			tint t2 = *nums.begin();
			nums.erase(nums.begin());
			total += (t1 + t2);
			nums.insert(t1+t2);
		}
		cout << total << "\n";
	}
	return 0;
}
