#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)

int borde(string st){
	int i=1, j=0;
	int n = st.size();
	vector<int> bordes(n, 0);
	bordes[0] = 0;
	while(i<n){
		while(j>0 && st[i] != st[j]){
			j = bordes[j-1];
		}
		if(st[i] == st[j]){
			j++;
		}
		bordes[i++] = j;
	}
	return bordes[n-1];
}

int main(){ 

	int T; cin >> T;
	forn(caso,T){
		int N; cin >> N;
		vector<string> strs(N);
		forn(i,N) cin >> strs[i];
		///
		/// tablitas bordes
		vector<vector< int > > tBordes(N, vector<int>(N, 0));
		forn(i,N){
			forn(j,N){
				if(i != j){
					tBordes[i][j] = borde(strs[i] + " " + strs[j]);
				}
			}
		}
		
		///
		string perm;
		forn(i,N) perm += i;
		int RES = 0;
		forn(i,N) RES += strs[i].size();
				
		int MRES = 0;
		/// 1 perm
		for(int i=1; i<(int)perm.size(); i++){
			MRES += tBordes[perm[i]][perm[i-1]];
		}
				
		/// el resto
		while(next_permutation(perm.begin(), perm.end())){
			int resp = 0;
			forsn(i,1,N){
				resp += tBordes[perm[i]][perm[i-1]];
			}
			MRES = max(MRES, resp);
		}
		
		cout << "Case " << caso+1 << ": " << RES - MRES << endl;
	}
	
	return 0;
	
}
