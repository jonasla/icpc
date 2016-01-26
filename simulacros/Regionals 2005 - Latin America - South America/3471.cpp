#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define forn(i,n) for(int i=0; i < (int) (n); i++)
#define forsn(i,s,n) for(int i=(s); i < (int) (n); i++)

#define pb push_back
#define ins insert

typedef vector<int> vi;
typedef set<int> si;

void dfs(int s, vector<vi> &hijos, vector<vi> &emplea, vector<si> &depen, vector<si> &tareas, vector<bool> &visit, vi &bs, vi &ts){

	visit[s] = true;
	ts[s] = bs[s];
	for(auto &h : hijos[s]){
		if(!visit[h]){
			dfs(h, hijos, emplea, depen, tareas, visit, bs, ts);
		}
		ts[s] += ts[h];
		
		///
		for(auto &d : depen[h]){
			depen[s].ins(d);
		}
	}
	
	//cout << "tarea " << s << ":\n";
	for(auto &d : depen[s]){
		//cout << "\t" << d << endl;
		for(auto &e : emplea[s]){
			if(tareas[e].count(d) > 0){
				tareas[e].erase(d);
			}
		}
	}	
}

int main(){
	int T, E;
	while(cin >> T >> E && T != 0 && E != 0){
		vector<vi > hijos(T, vi());		// hijos de tarea
		vector<vi > emplea(T, vi());	// empleados de cada tarea
		vector<si > depen(T, si());		// tareas dependientes (todas)
		
		vi bs(T);						// basic significance
		vi ts(T);						// total significance

		vector<si > tareas(E, si());			// tareas que hace cada empleado
		///
		forn(i,T){
			int b, nd, ne; cin >> b >> nd >> ne;
			bs[i] = b;
			forn(j,nd){
				int t; cin >> t;
				hijos[i].pb(t-1);
				depen[i].ins(t-1);
			}
			forn(j,ne){
				int e; cin >> e;
				tareas[e-1].ins(i);
				emplea[i].pb(e-1);
			}
		}
		///
		vector<bool> visit(T, false);
		forn(i,T){
			if(!visit[i]){
				dfs(i, hijos, emplea, depen, tareas, visit, bs, ts);
			}
		}
		///
		cout << "*****\n";
		forn(e,E){
			int paga = 0;
			for(auto &t : tareas[e]){
				paga += ts[t];
			}
			cout << e+1 << " " << paga << endl;
		}
	}
	return 0;
}
