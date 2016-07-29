#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define forsn(i,s,n) for(int i=(int)s; i<(int)n; i++)

const int maxN = 2000;
bool hor[maxN][maxN];
int dp[maxN][maxN][4];
int sig[2][4];

int main(){
	sig[0][0] = 3;
	sig[0][1] = 0;
	sig[0][2] = 1;
	sig[0][3] = 2;
	
	sig[1][0] = 1;
	sig[1][1] = 2;
	sig[1][2] = 3;
	sig[1][3] = 0;
	
	int N; cin >> N;
	forn(i,N){
	forn(j,N){
		char s; cin >> s;
		if(s == 'H') hor[i][j] = true;
	}}
	// DP
	dp[0][0][0] = 0;
	int curr = 0;
	int next = 0;
	forn(i,3){
		next = sig[hor[0][0]][curr];
		dp[0][0][next] = 1 + dp[0][0][curr];
		curr = next;
	}
	//forn(i,4) cout << dp[0][0][i] << " ";
	//cout << "\n   -   \n";
	
	forsn(i,1,N){		// Fila 1
		curr = 0;
		dp[0][i][curr] = dp[0][i-1][2];
		forn(j,3){
			next = sig[hor[0][i]][curr];
			dp[0][i][next] = 1 + dp[0][i][curr];
			curr = next;
		}
		//forn(k,4) cout << dp[0][i][k] << " ";
		//cout << endl;
	}
	//cout << "\n   -   \n";
	
	forsn(i,1,N){		// Colum 1
		curr = 1;
		dp[i][0][curr] = dp[i-1][0][3];
		forn(j,3){
			next = sig[hor[i][0]][curr];
			dp[i][0][next] = 1 + dp[i][0][curr];
			curr = next;
		}
		//forn(k,4) cout << dp[i][0][k] << " ";
		//cout << endl;
	}
	//cout << "\n   -   \n";
	
	forsn(i,1,N){
	forsn(j,1,N){
		//cout << i << " " << j << endl;
		dp[i][j][0] = dp[i][j-1][2];
		dp[i][j][1] = dp[i-1][j][3];
		//cout << "\t" << dp[i][j][0] << " " << dp[i][j][1] << endl;
		
		dp[i][j][0] = min( dp[i][j][0] , (hor[i][j] ? 3 : 1) + dp[i][j][1] );
		dp[i][j][1] = min( dp[i][j][1] , (hor[i][j] ? 1 : 3) + dp[i][j][0] );
		//cout << "\t" << dp[i][j][0] << " " << dp[i][j][1] << endl;
		
		dp[i][j][2] = min( dp[i][j][0] + 2 , (hor[i][j] ? 1 : 3) + dp[i][j][1] );
		dp[i][j][3] = min( dp[i][j][1] + 2 , (hor[i][j] ? 3 : 1) + dp[i][j][0] );
		
		
		//forn(k,4) cout << dp[i][j][k] << " ";
		//cout << endl;
	}}
	
	cout << dp[N-1][N-1][2] << endl;
	
	return 0;
}
