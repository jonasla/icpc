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
	tint T; cin >> T;
	while(T--) {
		tint N, A, D; cin >> N >> A >> D;
		tint sum = 0;
		forn(i,N) {
			sum += A;
			A += D;
		}
		cout << sum << "\n";
	}
	return 0;
}
