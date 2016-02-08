#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;
typedef vector<int> vi;

#define forn(i,n) for(tint i=0;i<(tint)(n);i++)
#define forsn(i,s,n) for(tint i=(s);i<(tint)(n);i++)

int main()
{	
	tint CASOS; cin >> CASOS;
	forn(casito, CASOS){
		int T, H, F; cin >> T >> H >> F;
		vector<vi> dp(T, vi(H, 0));
		vector<vi> corns(T, vi(H, 0));
		///
		forn(i,T){
			int ai; cin >> ai;
			forn(j,ai){
				int p; cin >> p; p--;
				corns[i][H-1-p]++;
			}
		}
		///
		forn(i,T){
			dp[i][0] = corns[i][0];
		}
		forsn(j,1,H){
			int ant = j-F;
			int maxAnt = -1;
			if(ant >= 0){
				forn(k,T){
					maxAnt = max(maxAnt, dp[k][ant]);
				}
			}
			forn(i,T){
				dp[i][j] = corns[i][j] + max(dp[i][j-1], maxAnt);
			}
		}
		///
		int res = 0;
		forn(i,T){
			res = max(res, dp[i][H-1]);
		}
		cout << res << endl;
	}
	cin >> CASOS;
	return 0;
}
