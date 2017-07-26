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
	
	tint C;
	set<ii> Q;
	tint p, k;
	while(cin >> C && C != 0) {
		if (C == 1) { //add
			cin >> k >> p;
			Q.insert({p,k});
		} else if (C ==2) {
			if (Q.empty()) cout << 0 << "\n";
			else {
				ii i = *Q.rbegin();
				Q.erase(i);
				
				cout << i.second << "\n";
			}
		} else if (C==3) {
			if (Q.empty()) cout << 0 << "\n";
			else {
				ii i = *Q.begin();
				Q.erase(i);
				
				cout << i.second << "\n";
			}
		}
	}
	return 0;
}
