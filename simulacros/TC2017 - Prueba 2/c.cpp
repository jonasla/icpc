#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long tint;
typedef long double ldouble;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)


void dfsTopo(vector<vi> &g, tint s, vi &vis, vi &ord, vi &comp) {
	vis[s] = true;
	for(auto ad : g[s]) {
		if (!vis[ad]) 
			dfsTopo(g, ad, vis, ord, comp);
	}
	ord.push_back(s);
	comp.push_back(s);
}

vector<vi> kosaraju(vector<vi> &graf, vector<vi> &grafINV) {
	vi vis, ord, aux;
	tint N = graf.size();
	vis.assign(N, 0);
	forn(i,N)
		if (!vis[i]) 
			dfsTopo(graf, i, vis, ord, aux);
		
	vis.assign(N,0);
	reverse(ord.begin(), ord.end());
	vector<vi> comps;
	
	for (auto o : ord) {
		if (!vis[o]) {
			vi comp;
			dfsTopo(grafINV, o, vis, aux, comp);
			comps.push_back(comp);
		}
	}
	reverse(comps.begin(), comps.end());
	return comps;
}

tint n;
tint id(tint x) {
	return x+n;
}

tint negado(tint i) {
	tint d = abs(i-n);
	if (i > n) 
		return i - 2*d;
	else
		return i + 2*d;
}
int main() {
	ios:: sync_with_stdio(false);
	cin.tie(NULL);
	tint m;
	while (cin >> n >> m)
	{
		vector<vi> ladj (2*n+1);
		vector<vi> ladjINV (2*n+1);
		forn(i,m)
		{
			tint a,b;
			cin >> a >> b;
			ladj[negado(id(a))].push_back(id(b));
			ladj[negado(id(b))].push_back(id(a));
			
			
			ladjINV[id(b)].push_back(negado(id(a)));
			ladjINV[id(a)].push_back(negado(id(b)));
		}
		
		//~ forn(i,ladj.size()) {
			//~ cout << "nodo " << i << endl;
			//~ for(auto x : ladj[i]) cout << x << " ";
			//~ cout << endl;
		//~ }
		
		vector<vi> comps = kosaraju(ladj, ladjINV);
		//
		bool possible = true;
		for(auto &c : comps) {
			//~ cout << "comp\n";
			set<tint> comp;
			for(auto x : c){ 
				//~ cout << x << endl;
				tint org = abs(x-n);
				comp.insert(org);
			}
			possible &= (comp.size() == c.size());
		}
		cout << possible << "\n";
	}
	return 0;
}
