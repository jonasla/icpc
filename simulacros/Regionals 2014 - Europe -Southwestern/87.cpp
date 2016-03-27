#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int (i)=0; i<(int)(n); (i)++)
#define forsn(i,s,n) for(int (i)=(s); i<(int)(n); (i)++)

#define mp make_pair
#define pb push_back

typedef vector<int> vi;

void dfs(int s, vector<vi> &graf, vi &visit, vi &orden){
	visit[s] = true;
	//cout << "visit " << s << endl;
	for(auto &ady : graf[s]){
		if(!visit[ady]){
			dfs(ady, graf, visit, orden);
		}
	}
	orden.pb(s);
}

void printvec(vi &vec){
	cout << "[";
	forn(i,vec.size()){
		if(i) cout << ",";
		cout << vec[i];
	}cout << "]\n";
}

int main(){

	int N, M;
	while(cin >> N >> M && N != 0){
		vector<vi> graf(N, vi());
		vector<vi> grafInv(N, vi());
		forn(i,M){
			int u, v; cin >> u >> v;
			graf[u].pb(v);
			grafInv[v].pb(u);
		}
		//
		vi orden;
		vi visit(N, false);
		forn(i,N){
			if(!visit[i]){
				dfs(i, graf, visit, orden);
			}
		}
		//
		reverse(orden.begin(), orden.end());
		
		vector<vi> CC;
		vi visitInv(N, false);
		for(auto &i : orden){
			if(!visitInv[i]){
				vi comp;
				dfs(i, grafInv, visitInv, comp);
				CC.pb(comp);
				printvec(comp);
			}
		}
		//
		bool res = true;
		for(auto &c : CC){
			if(c.size() == 1){
				res = false;
				break;
			}
		}
		if(res){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}

	return 0;
}
