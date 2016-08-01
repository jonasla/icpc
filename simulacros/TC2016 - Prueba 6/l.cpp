#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define dforn(i,n) for(int i=(int)(n-1); i>=0; i--)
#define forsn(i,s,n) for(int i=(int)s; i<(int)n; i++)

void printVec(vi &v){
        for(auto &e : v){
                cout << e << " ";
        }cout << endl;
}

int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int N, H;
        while(cin >> N >> H && N != -1){
                vi dists(N-1);
                forn(i,N-1) cin >> dists[i];
                
                vi sumDist(N); sumDist[0] = 0;
                forsn(i,1,N) sumDist[i] = dists[i-1] + sumDist[i-1];

                //printVec(sumDist);

                vector<vi> graf(N, vi());
                forn(i,N){
                        forsn(j,i+1,N){
                                if(sumDist[j] - sumDist[i] <= (j-i)*H){
                                        graf[i].push_back(j);
                                }
                        }
                }
                
                //for(auto &v : graf){
                //        printVec(v);
                //}
                
                vi dp(N, -1);
                dp[0] = 0;
                forn(i,N){
                        for(auto adj : graf[i]){
                                if(dp[i] != -1){
                                        dp[adj] = max(dp[adj] , dp[i] + 1);
                                }
                        }
                }
                if(dp[N-1] != -1)
                        cout << ((N-1) - dp[N-1]) << "\n";
                else
                        cout << "-1\n";
        }
        return 0;
}
