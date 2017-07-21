#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long tint;
typedef long double ldouble;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)

bool POSSIBLE;

void dfsTopo(vector<vi> &g, tint s, vi &visitG, vi &ord) {
	visitG[s] = 1;
	//~ cout << "visit " << s+1 << endl;
	for (auto ad : g[s]){ 
		if (visitG[ad] == 1) {
			//~ cout << "imposible visitando " << ad+1 << endl;
			POSSIBLE = false;
		}
		if (!visitG[ad])  
			dfsTopo(g, ad, visitG, ord);
	}
	ord.push_back(s);
	visitG[s] = 2;
	//~ cout << "fin " << s+1 << endl;
	//~ return true;
}

//~ void dfsCiclo(vector<vi> &g, tint s, vi &visitG, vi &ord) {
	//~ vi visitL(g.size(), false);
	//~ dfsTopo(g, s, visitG, visitL, ord);
//~ }

//~ void dfsCiclo(vector<vi> &g, tint s, vi &visit) {
	//~ visit[s] = true;
	//~ for(auto ad : g[s]) {
		//~ if 
	//~ } 
//~ }

int main() {
	ios:: sync_with_stdio(false);
	cin.tie(NULL);

	tint N, M;
	while(cin >> N >> M && N != 0) {
		vector<vi> graf(N);
		//~ vector<vi> grafInv(N);
		forn(i,M) {
			tint a, b; cin >> a >> b;
			a--; b--;
			graf[a].push_back(b);
			//~ grafInv[b].push_back(a);
		}
		//
		vi visitG(N, 0);
		vi ord;
		POSSIBLE = true;
		forn(i,N) {
				if (visitG[i] == 0) {
					dfsTopo(graf, i, visitG, ord);
				}
		}
		////
		if (POSSIBLE) {
			reverse(ord.begin(), ord.end());
			for(auto o : ord) cout << o+1 << "\n";
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
	return 0;
}
