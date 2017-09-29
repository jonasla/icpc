#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>

using namespace std;

typedef long long tint;

#define forsn(i,s,n) for(tint i = (tint)(s) ;  i < (tint)(n); i++)
#define forn(i,n) for(tint i = (tint)(0) ;  i < (tint)(n); i++)

const tint MAXN = 1e6 + 50;

tint p[MAXN];
void criba() {
	for(int i=4; i<MAXN; i+=2) p[i] = 2;
	for(int i=3; i*i<MAXN; i+=2) 
		if (!p[i]) for(int j=i*i; j<MAXN; j+=2*i) p[j] = i;
}

map<tint, tint> facts(tint N) {
	map<tint, tint> fs;
	while(p[N]) {
		fs[p[N]]++;
		N /= p[N];
	}
	fs[N]++;
	return fs;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	criba();
	
	tint T; cin >> T;
	while(T--) {
		tint N; cin >> N;
		auto f = facts(N);
		tint maxcoso = 0;
		for(auto e : f) maxcoso = max(maxcoso, e.second);
		cout << maxcoso << "\n";
	}
	return 0;
}
