#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

tint sototo(tint N) {
	tint a = N*(N+1)*(2*N+1) / 6;
	tint b = (N-1)*(N)*(2*N-1) / 6;
	return a + b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	//~ cout << sototo(0) << endl;
	//~ cout << sototo(1) << endl;
	//~ cout << sototo(2) << endl;
	//~ cout << sototo(3) << endl;
	//~ cout << sototo(4) << endl;
	
	
	tint N; cin >> N;
	
	//~ tint levels = 0;
	//~ tint currTotal = 1;
	//~ tint currLev = 0;
	
	//~ while(N >= currTotal) {
		//~ levels++;
		//~ currLev += 4;
		//~ N -= currTotal;
		//~ currTotal += currLev;
	//~ }

	//~ cout << levels << endl;
	
	tint L = 0;
	tint aux = sototo(L);
	while(aux <= N){ 
		//~ cout << aux << endl;
		
		L++;
		aux = sototo(L);
	}
	
	cout << L-1 << endl;
	
	return 0;
}
