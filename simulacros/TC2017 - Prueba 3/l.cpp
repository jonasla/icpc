#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

void dfsTopo(vector<vi> &g, tint s, vi &vis, vi &ord, vi &comp) {
	vis[s] = true;
	for(auto ad : g[s])
		if (!vis[ad]) 
			dfsTopo(g, ad, vis, ord, comp);
	comp.push_back(s);
	ord.push_back(s);
}

vector<vi> kosaraju(vector<vi> &g, vector<vi> &gINV) {
	tint n = g.size();
	vi vis(n, 0);
	vi ord;
	vi aux;
	forn(i,n)
		if(!vis[i]) 
			dfsTopo(g, i, vis, ord, aux);
	
	vis.assign(n,0);
	reverse(ord.begin(), ord.end());
	vector<vi> comps;
	for(auto o : ord) {
		if (!vis[o]) {
			vi comp;
			dfsTopo(gINV, o, vis, aux, comp);
			comps.push_back(comp);
		}
	}
	return comps;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	tint T, N, M;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		vector<vi> graf(N);
		vector<vi> grafINV(N);
		forn(i,M){
			tint a, b; cin >> a >> b;
			a--; b--;
			graf[a].push_back(b);
			grafINV[b].push_back(a);
		}
		
		//~ continue;
		///
		tint NOENTRAN = 0, NOSALEN = 0;
		
		vector<vi> comps = kosaraju(graf, grafINV);
		
		//~ cout << "comps " << comps.size() << endl;
		//~ continue;
		
		for(auto c : comps) {
			set<tint> cset(c.begin(), c.end());
			//~ for(auto nod : cset) cout << nod << " ";
			//~ cout << endl;
			bool entra = false, sale = false;
			
			for(auto nod : cset) {
				//~ cout << "nodo " << nod << endl;
				for(auto ad : graf[nod]) {
					//~ cout << "\tvecino " << ad << endl;
					sale |= (cset.find(ad) == cset.end());
				}
				for(auto ad : grafINV[nod]) {
					//~ cout << "\tanti vecino " << ad << endl;	
					entra |= (cset.find(ad) == cset.end());
				}
			}
			
			if (!entra) {
				NOENTRAN++;
				//~ cout << "no entran\n";
			}
			if (!sale) {
				NOSALEN++;
				//~ cout << "no salen\n";
			}
		}
		if (comps.size() > 1)
			cout << max(NOENTRAN, NOSALEN) << "\n";
		else 
			cout << "0\n";
	}
	return 0;
}
