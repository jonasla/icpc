#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)

typedef long long tint;
typedef vector<tint> vi;

set<tint> SOL;

void bt(tint i, vi &barras, vi &pesas, tint l, tint r) {
	if (i < (int)pesas.size()){
		tint peso = pesas[i];
		bt(i+1, barras, pesas, l+peso, r);
		bt(i+1, barras, pesas, l, r+peso);
		bt(i+1, barras, pesas, l, r);
	} else {
		if (l == r) {
			for(auto b : barras) {
				SOL.insert(l + r + b);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	vi barras(N);
	vi pesas(M);
	forn(i,N) cin >> barras[i];
	forn(i,M) cin >> pesas[i];
	
	bt(0, barras, pesas, 0, 0);
	
	for(auto s : SOL) {
		cout << s << "\n";
	}
	
	return 0;
}
