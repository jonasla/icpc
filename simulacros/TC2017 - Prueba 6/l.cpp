#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

const tint maxN = 1048576;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	tint K; cin >> K;
	 
	vi vots(K);
	forn(i,K) cin >> vots[i]; 

	sort(vots.begin(), vots.end());

	tint cant = 0;
	forn(i,vots.size()/2 +1) {
		cant += vots[i] / 2 + 1;
	}
	cout << cant << endl;

	return 0;
}
