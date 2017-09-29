#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>

using namespace std;

typedef long long tint;

#define forsn(i,s,n) for(tint i = (tint)(s) ;  i < (tint)(n); i++)
#define forn(i,n) for(tint i = (tint)(0) ;  i < (tint)(n); i++)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	tint T; cin >> T;
	while(T--) {
		tint N, K; cin >> N >> K;
		vector<tint> nums(N, 0);
		forn(i,N) cin >> nums[i];
		
		sort(nums.begin(), nums.end());
		
		tint e = K-1;
		tint mini = 1e15;
		forsn(i,e,N) {
			mini = min(mini, nums[i]-nums[i-K+1]);
		}
		cout << mini << "\n";
	}
	return 0;
}
