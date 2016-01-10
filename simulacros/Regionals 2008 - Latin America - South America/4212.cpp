#include <iostream>
#include <vector>
#include <algorithm>


#define forn(i,n) for(int (i) = 0; (i) < (int)(n); i++ )
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)


typedef unsigned long long utint;
using namespace std;

int main(){
	
	int N, M;
	while(cin >> M >> N && N != 0){
		
		vector<utint> mFilas(M, 0);
		
		for(int i=0; i<M; i++){			
			
			vector<utint> filaI;
			
			for(int j=0; j<N; j++){
				utint e; 
				cin >> e;
				
				filaI.push_back(e);
			}
			
			vector<utint> dpI(N+1, 0);
			dpI[1] = filaI[0];
			for(int j=2; j<N+1; j++){
				dpI[j] = max(dpI[j-1], dpI[j-2] + filaI[j-1]);
			}
			
			mFilas[i] = dpI[N];
		}
		/*
		for(unsigned int i=0; i<mFilas.size(); i++){
			cout << mFilas[i] << endl;
		}*/
		
		vector<utint> dp(M+1, 0);
		dp[1] = mFilas[0];
		for(int i=2; i<M+1; i++){
			dp[i] = max(dp[i-1], dp[i-2] + mFilas[i-1]);
		}
		cout << dp[M] << endl;
	}

	return 0;
}
