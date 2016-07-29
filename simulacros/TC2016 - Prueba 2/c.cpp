#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 10050
#define pb push_back
#define forn(i,n) for(int i=0; i<(int)n; i++)

typedef vector<int> vi;
typedef long long tint;

int _cl[MAXN];
int _h[MAXN];
int _d[MAXN];
int _color[MAXN];
int _par[MAXN];

int cl(int i) { return (_cl[i]==-1 ? i : _cl[i] = cl(_cl[i])); }
void join(int i, int j) { if(cl(i) != cl(j)) _cl[cl(i)] = cl(j); };

void dfs(int v, vector<vi> &graf){
	_d[v] = _h[v];
	_color[v] = 1;
	for(auto u : graf[v]){
		if(_color[u] == 0){
			_par[u] = v;
			_h[u] = _h[v]+1;
			dfs(u, graf);
			_d[v] = min(_d[v], _d[u]);
			if(_d[u] > _h[v]){
				//cout << "join\n";
				join(v, u);
			}
		}else{
			if(u != _par[v]){
				_d[v] = min(_d[v], _h[u]);
			}
		}
	}
	_color[v] = 2;
}

int main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int N, M, Q;
	while(cin >> N >> M >> Q && N != 0){
		vector<vi> graf(N, vi());
		forn(i,M){
			int u, v; cin >> u >> v;
			graf[u-1].pb(v-1);
			graf[v-1].pb(u-1);
		}
		// puentes
		memset(_cl, -1, sizeof(int) * N);
		memset(_h, 0, sizeof(int) * N);
		memset(_d, 0, sizeof(int) * N);
		memset(_color, 0, sizeof(int) * N);
		memset(_par, -1, sizeof(int) * N);
		forn(i,N) if(_color[i]==0) { dfs(i, graf); }
		// queries
		//forn(i,N) cout << cl(i) << " ";
		//cout << endl;
		forn(i,Q){
			int u, v; cin >> u >> v;
			if(cl(u-1) == cl(v-1)) cout << "Y\n";
			else cout << "N\n";
		}
		cout << "-\n";
	}
	return 0;
}
