#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define forn(i,n) for (int i = 0; i < (int) (n); i++)
#define forsn(i,s,n) for (int i = (s); i < (int) (n); i++)

using namespace std;

typedef long long tint;
typedef pair<tint, tint> ii;
typedef pair<ii, tint> jug;
typedef vector<jug> vjug;
typedef vector<ii> vii;
typedef map<jug, vjug> graf;

ii nodo(tint e1, tint e2) {
	tint mn = min(e1, e2);
	tint mx = max(e1, e2);
	return make_pair(mn, mx);
}

jug jugada(ii nod, tint j) {
	return make_pair(nod, j);
}

void topo(graf &g, jug &nod, set<jug> &visit, vjug &orden) {
	visit.insert(nod);
	for(auto c : g[nod]) {
		if (visit.find(c) == visit.end())
			topo(g, c, visit, orden);
	}
	orden.push_back(nod);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	jug nodo_start = jugada(nodo(0,0),0);
	while (cin >> n && n != -1)
	{
		graf grafo;
		string list;
		forn(i,n-1) {
			map<tint, tint> jugadas;
			jug start = nodo_start;
			cin >> list;
			tint e1 = i+2;
			tint e2 = 0;
			for(auto c : list) {
				e2 = c-'0';
				ii curr = nodo(e1,e2);
				tint j = jugadas[e2];
				jug jg = jugada(curr,j);
				grafo[start].push_back(jg);
				start = jg;
				jugadas[e2]++;
			}
		}
		/// grafo bien
		//~ for(auto vc : grafo) {
			//~ cout << vc.first.first.first << "," << vc.first.first.second << " => \n";
			//~ for(auto j : vc.second) {
				//~ cout << j.first.first << "," << j.first.second << "  ";
			//~ }
			//~ cout << endl;
		//~ }
		
		/// toposort
		set<jug> visit;
		vjug orden;
		topo(grafo, nodo_start, visit, orden);
		reverse(orden.begin(), orden.end());
		string ans;
		for(auto c : orden) {
			//~ cout << c.first.first  << " , " << c.first.second << endl;
			if (c.first.first == 1) {
				ans.push_back(c.first.second+'0');
			}
		}
		cout << ans << endl;
	}
	return 0;
}
