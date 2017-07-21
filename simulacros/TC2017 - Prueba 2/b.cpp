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

vi bfs(vector<vi> &g, tint s) {
	vi d(g.size(), -1);
	queue<tint> Q;
	Q.push(s);
	d[s] = 0;
	while(!Q.empty()) {
		tint v = Q.front(); Q.pop();
		for(auto ad : g[v]) {
			if (d[ad] == -1) {
				d[ad] = d[v] + 1;
				Q.push(ad);
			}
		}
	}
	return d;
}

int main() {
	tint T; cin >> T;
	while(T--) {
		tint N; cin >> N;
		vector<vi> graf(N);
		forn(i,N-1) {
			tint a, b; cin >> a >> b;
			a--; b--;
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
		///
		vi ds1 = bfs(graf, 0);
		tint lejano = max_element(ds1.begin(), ds1.end()) - ds1.begin();
		vi ds2 = bfs(graf, lejano);
		cout << *max_element(ds2.begin(), ds2.end())+1 << endl;
	}

	return 0;
}
