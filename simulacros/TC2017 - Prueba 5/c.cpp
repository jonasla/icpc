#include <iostream>
#include <set>

using namespace std;

typedef long long tint;
typedef pair<tint, tint> ii;

#define forsn(i,s,n) for(int i=(tint)s; i<(tint)n; i++) 
#define forn(i,n) forsn(i,0,n) 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	tint T;
	cin >> T;
	while(T--) {
		tint S = 1;
		tint N; cin >> N;
		tint P;
		while(N--) {
			cin >> P;
			S = S ^ P;
		}
		if (S == 0) {
			cout << "Brother\n";
		} else {
			cout << "John\n";
		}
	}
	
	return 0;
}
