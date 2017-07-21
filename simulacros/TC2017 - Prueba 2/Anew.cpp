#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long tint;
typedef long double ldouble;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)

tint W;
const tint MAXW = 1<<17;
const tint NMOD = 1000000000+7;
tint dp[MAXW][4][4][4][4];

bool compatible(vi a, vi b) {
	if (a[0] == 1) return false;
	if (b[0] == 1) return false;
	if (a[3] == 3) return false;
	if (b[3] == 3) return false;
	
	forn(i,4){
		if(a[i] != 0 && b[i] == 2) return false;
		else if(a[i] == 0 && b[i] != 2) return false;  
	}
	forn(i,3){
		if (a[i] != 3 && a[i+1] == 1) return false;
		else if (a[i] == 3 && a[i+1] != 1) return false;
		
		if (b[i] != 3 && b[i+1] == 1) return false;
		else if (b[i] == 3 && b[i+1] != 1) return false;
	}
	return true;
}

tint mod (tint x)
{
	return x % NMOD;
}

int main() {
	ios:: sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> W;
	dp[0][2][2][2][2] = 1;
	
	forsn(f,1,W+1) {
		forn(i1,4)
		forn(j1,4)
		forn(k1,4)
		forn(l1,4)
		forn(i2,4)
		forn(j2,4)
		forn(k2,4)
		forn(l2,4){
			if (compatible({i1,j1,k1,l1},{i2,j2,k2,l2})) {
				dp[f][i2][j2][k2][l2] =mod (dp[f][i2][j2][k2][l2] + dp[f-1][i1][j1][k1][l1]);
			}
		}
	}
	tint suma = 0;
	forsn(i,1,4)
	forsn(j,1,4)
	forsn(k,1,4)
	forsn(l,1,4){
		suma = mod(suma +  dp[W][i][j][k][l]);
		//~ if (compatible({i,j,k,l},{0,0,0,0})) {
			//~ dp[W+1][0][0][0][0] += dp[W][i][j][k][l];
		//~ }
	}
	cout << suma << endl;
	//~ cout << dp[W+1][0][0][0][0] << "\n";

	return 0;
}
