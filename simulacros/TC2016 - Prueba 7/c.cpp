#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define pb push_back
#define forn(i,n) for(tint i=0;i<(tint)n;i++)

typedef long long tint;
typedef vector<int> vi;

struct circ {
	tint x, r;
	circ(tint xx, tint rr){ x = xx; r = rr; }
};

struct event {
	tint x, r, id;
	bool abre;
	event(tint xx, tint rr, bool abr, tint dd) { x = xx; r = rr; abre = abr; id = dd; }
};

void printEvent(event &e){
	if(e.abre) cout << "abre ";
	if(!e.abre) cout << "cierra ";
	cout << e.id << " " << e.x << " " << e.r << "\n";
}

bool operator < (const event &e1, const event &e2){
	if(e1.x != e2.x) return e1.x < e2.x;
	else if(e1.x == e2.x){
		if(e1.abre == e2.abre && e1.abre == true){	// abren en el mismo lugar
			return e1.r > e2.r;
		}else if(e1.abre == e2.abre && e1.abre == false) {	// cierran en el mismo lugar
			return e1.r < e2.r;
		}else{	// distintos
			if(e1.abre) return false;
			else return true;
		}
	}
	return false;
}

vector<circ> circulos;

tint dfs(tint id, vector<vi> &graf, vector<bool> &visit) {
	tint cubierto = 0;
	tint regs = 1;
	visit[id] = true;
	for(auto &adj : graf[id]){
		if(!visit[adj]){
			regs += dfs(adj, graf, visit);
			cubierto += 2*circulos[adj].r;
		}
	}
	//cout << "circ " << id << ": " << regs << endl;
	if(cubierto == circulos[id].r*2) regs++;
	//cout << "circ " << id << ": " << regs << endl;
	return regs;
}

int main(){
	int N; cin >> N;
	vector<event> eventos;
	forn(i,N){
		int x, r; cin >> x >> r;
		circ c = circ(x, r);
		circulos.pb(c);
		
		event ab = event(x-r, r, true, i);
		event ci = event(x+r, r, false, i);
		eventos.pb(ab);
		eventos.pb(ci);
	}

	sort(eventos.begin(), eventos.end());
	
	//for(auto &e : eventos){
	//	printEvent(e);
	//}
	
	vector<vi> graf(N, vi());
	stack<int> S;
	for(auto &e : eventos){
		if(e.abre) S.push(e.id);
		if(!e.abre){
			tint hijo = S.top();
			S.pop();
			if(!S.empty()){
				tint padre = S.top();
				graf[padre].pb(hijo);
			}
		}
	}
	
	//forn(i,N){
	//	cout << i << ": ";
	//	forn(j, graf[i].size()){
	//		if(j) cout << " ";
	//		cout << graf[i][j];
	//	}cout << endl;
	//}

	vector<bool> visit(N, false);
	tint res = 0;
	for(auto e : eventos){
		if(e.abre){
			// dfs
			if(!visit[e.id]){
				res += dfs(e.id, graf, visit);
			}
		}
	}
	cout << res+1 << endl;

	return 0;
}
