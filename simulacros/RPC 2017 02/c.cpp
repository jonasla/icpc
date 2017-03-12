#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)

typedef long long tint;
typedef vector<tint> vi;
typedef vector<bool> vb;

int main() 
{
	int N, K, R;
	cin >> N >> K >> R;
	vb cams(N, false);
	forn(i,K){
		int e; cin >> e;
		cams[e-1] = true;
	}
	
	int RES = 0;
	int cant_cams = 0;
	forn(i,N){
		cant_cams += cams[i];
		if (i+1 >= R){
			if (i-R >= 0) cant_cams -= cams[i-R];
			int r = i;
			while (cant_cams < 2) {
				if (!cams[r]){
					cams[r] = true;
					cant_cams++;
					RES++;
				}
				r--;
			}
		}
	}
	cout << RES << endl;
	return 0;
}
