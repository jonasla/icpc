#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

typedef int tint;
typedef long double ldouble;
typedef vector<tint> vi;
typedef unordered_set<tint> si;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)


si dp[30][30];
tint num[30][30];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	tint N;
	cin >> N;
	
	vi ss(N, 1), ns(N);
	ss[0] = 1;
	cin >> ns[0];
	forsn(i,1,N) {
		char s; cin >> s;
		if (s == '-') ss[i] = -1;
		cin >> ns[i];
	}
	
	forn(i,N)
	forn(j,i+1) {
		num[j][i] = ns[j];
		forsn(k,j+1,i+1) {
			num[j][i] += ns[k]*ss[k];
		}
		num[j][i] *= ss[j];
		//~ cout << j << " " << i << " " << num[j][i] << endl;
	}
	
	//~ forn(i,N) cout << ns[i] << " ";
	//~ cout << endl;
	
	//~ forn(i,N) cout << ss[i] << " ";
	//~ cout << endl;
	
	forn(i,N) {
		dp[i][i].insert(ns[i]*ss[i]);
		//~ dp[i][i].insert(num[i][i]);
	}
	
	forsn(l,1,N) {
		forn(i,N-l) {
			//~ cout << i << " " << i+l << endl;
			dp[i][i+l].insert(num[i][i+l]);
			forsn(k,i,i+l) {
				//~ cout << "\t" << k << endl;
				
				for(auto di : dp[i][k]) {
					for (auto dl : dp[k+1][i+l]) {
						//~ cout << di + dl << endl;
						//~ dp[i][i+l].insert(ss[i]*num[i][k] + ss[k+1]*num[k+1][i+l]);
						dp[i][i+l].insert(di + dl);
					}
				}
			}
			
			//~ for (auto n : dp[i][i+l] ) {
				//~ cout << "\t" << n << endl;
			//~ }
		}
	}
	
	cout << dp[0][N-1].size() << "\n";
	
	return 0;
}
