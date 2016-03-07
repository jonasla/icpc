#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(int)(n); (i)++)
#define forsn(i,s,n) for(int (i)=(s); (i)<(int)(n); (i)++)
typedef long long tint;

tint dp[1005];

void llenardp(){
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	forsn(i,3,1005){
		dp[i] = 1;
		forsn(j,1,(i/2)+1) dp[i] += dp[j];
	}
}

int main(){
	llenardp();
	
	int N; cin >> N;
	forn(i,N){
		int c; cin >> c;
		cout << i+1 << " " << dp[c] << endl;
	}
	
	
	return 0;
}
