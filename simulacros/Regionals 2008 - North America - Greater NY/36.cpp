#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(int)(n); (i)++)
#define forsn(i,s,n) for(int (i)=(s); (i)<(int)(n); (i)++)

int main(){
	int N; cin >> N;
	forn(i,N){
		int K; cin >> K;
		double freq[26];
		forn(j,26){
			cin >> freq[j];
		}
		vector<vector<vector<double> > > dp(26, vector<vector<double> >(26, vector<double>(26, 0)));
		vector<vector<vector<int> > > dpC(26, vector<vector<int> >(26, vector<int>(26, -1)));
		// K = 0
		forn(a,26){
			forsn(b,a,26){
				double t = 0;
				for(int c=a; c<=b; c++){
					t += (c-a+1)*freq[c];
				}
				if(b-a >= 8){
					dp[a][b][0] = 1000000;
				}else{
					dp[a][b][0] = t;
				}
			}
		}
		// K > 0
		for(int j=1; j<=K; j++){
			forn(a,26){
				forsn(b,a+j,26){
					
					double t = 1000000;
					int minc = -1;
					/// magia
					for(int c=a; c<=b-j && (c-a)<8; c++){
						//t = min(t, dp[a][c][0] + dp[c+1][b][j-1]);
						
						if(dp[a][c][0] + dp[c+1][b][j-1] < t){
							t = dp[a][c][0] + dp[c+1][b][j-1];
							minc = c;
						}
					}
					
					dp[a][b][j] = t;
					dpC[a][b][j] = minc;
				}
			}
		}
		//
		printf("%d %.3f ", i+1, dp[0][25][K-1] / 100.0);
		//
		vector<int> losC;
		losC.push_back(-1);
		int lastC = dpC[0][25][K-1];
		losC.push_back(lastC);
		for(int j=2; j<=K; j++){
			//cout << lastC << endl;
			lastC = dpC[lastC+1][25][K-j];
			if(lastC == -1) lastC = 25;
			losC.push_back(lastC);
		}
		//cout << lastC << endl;
		string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		
		for(int j=1; j<(int)losC.size(); j++){
			for(int a=losC[j-1]+1; a<=losC[j]; a++){
				cout << ABC[a];
			}
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}
