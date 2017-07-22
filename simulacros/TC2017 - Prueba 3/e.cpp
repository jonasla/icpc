#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;
typedef set<tint> si;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

/////

tint T, E;
vector<vi> graf;
vi _bs;
vi _ts;
vector<si> tareas;
vi sals;
vi vis;
vi topoOrd;

/////

void dfsTopo(tint s) {
	vis[s] = true;
	for(auto ad : graf[s])
		if (!vis[ad]) 
			dfsTopo(ad);
	topoOrd.push_back(s);
}

void dfsMatar(tint t) {
	vis[t] = true;
	for (auto ad : graf[t]) {
		if (!vis[ad])
			dfsMatar(ad);
	}
}

void dfsSal(tint e, tint t) {
	// e hace la tarea t
	vis[t] = true;
	cout << "visitando " << t+1 << endl;
	if (tareas[e].find(t) != tareas[e].end()) { 
		sals[e] += _ts[t];
		dfsMatar(t);
		return;
	} else {
		for(auto td : graf[t]) {
			if (!vis[td])
				dfsSal(e, td);
		}
	}
}

void getSal(tint e) {
	//~ cout << "CHABON " << e+1 << endl;
	vis.assign(T, 0);
	for(auto o : topoOrd) 
		if (!vis[o]) {
			 
			//~ dfsSal(e, o);
				vis[o] = true;
				//~ cout << "visitando " << o+1 << endl;
				if (tareas[e].find(o) != tareas[e].end()) { 
					sals[e] += _ts[o];
					dfsMatar(o);
					//~ return;
				//~ } else {
					//~ for(auto td : graf[t]) {
						//~ if (!vis[td])
							//~ dfsSal(e, td);
					//~ }
				}
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	while(cin >> T >> E && T != 0) {
		//~ cout << "CASOOOOOO\n";
		
		graf.assign(T, vi());
		//~ entradas.assign(T, 0);
		_bs.assign(T, 0);
		_ts.assign(T, 0);
		tareas.assign(E, si());
		sals.assign(E, 0);
		///////
		tint nd, ne;
		forn(i,T){ 
			cin >> _bs[i] >> nd >> ne ;
			forn(d,nd){
				tint td; cin >> td; td--;
				graf[i].push_back(td);
			}
			forn(e,ne){
				tint te; cin >> te; te--;
				tareas[te].insert(i);
			}
		}
		///// topo
		topoOrd.clear();
		vis.assign(T, 0);
		forn(i,T) 
			if (!vis[i]) 
				dfsTopo(i);
		
		///////////// dp
		for(auto o : topoOrd) {
			_ts[o] = _bs[o];
			for(auto t : graf[o])
				_ts[o] += _ts[t];
		}
		
		//// solucions
		reverse(topoOrd.begin(), topoOrd.end());
		forn(i,E){
			getSal(i);
		}

		///////
		cout << "*****\n";
		forn(i,E) 
		{
			cout << i+1 << " " << sals[i] << "\n";
		}
	}
	return 0;
}
