#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long tint;
typedef pair<int, int> ii;
typedef pair<tint, pair<int, int> > eje; 

int padres[3500];
int prof[3500];

void initUF(int n){
	for(int i=0; i<n; i++) { padres[i] = i; prof[i] = 0;}
}

int find(int i){
	if(padres[i] == i) return i;
	padres[i] = find(padres[i]);
	return padres[i];
}

void join(int x, int y){
	int xr = find(x), yr = find(y);
	if(prof[xr] < prof[yr]) padres[xr] = yr;
	else if(prof[xr] > prof[yr]) padres[yr] = xr;
	else {
		padres[yr] = xr;
		prof[xr]++;
	}
}

vector<eje> kruskal(vector<eje> &ejes, int n){
	int aristas = 0;
	sort(ejes.begin(), ejes.end());

	vector<eje> ret;
	
	initUF(n);
	
	for(unsigned int i=0; i<ejes.size(); i++){
		eje& e = ejes[i];
		if(find(e.second.first) != find(e.second.second)){
			//cout << "kruskal agrego\n";
			aristas++;
			ret.push_back(e);
			if(aristas == n-1) break;
			join(e.second.first, e.second.second);
		}
	}
	
	return ret;
	
}

vector<tint> bfs(vector<vector<ii> > &graf, int s){
	vector<tint> ret(graf.size(), -1);
	ret[s] = 0;
	
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		int nod = Q.front();
		Q.pop();
		
		for(unsigned int i=0; i<graf[nod].size(); i++){
			ii& ady = graf[nod][i];
			if(ret[ady.second] == -1){
				//cout << "visit\n";
				ret[ady.second] = max((tint)ady.first, ret[nod]);
				Q.push(ady.second);
			}
		}
	}
	
	return ret;
}

int main(){

	int C, L, H;
	cin >> C >> L >> H;
	
	while(C != -1){
		vector<eje> ejes;
		vector<ii> hacks;
		
		// ejes grafo
		for(int i=0; i<L; i++){
			int a, b, v;
			cin >> a >> b >> v;
			
			ejes.push_back(make_pair(v, make_pair(a-1, b-1)));
		}
		// lista hackers
		for(int i=0; i<H; i++){
			int s, t;
			cin >> s >> t;
			
			hacks.push_back(make_pair(s, t));
		}
		//break;
		
		// kruskal
		vector<eje> ejesAGM = kruskal(ejes, C);
		
		//break;
		//return 0;
		
		// armo grafo
		vector<vector<ii> > graf(C);
		for(unsigned int i=0; i<ejesAGM.size(); i++){
			eje& e = ejesAGM[i];
			int u = e.second.first;
			int v = e.second.second;
			int w = e.first;
			
			//cout << "agrego arista\n";
			
			graf[u].push_back(make_pair(w, v));
			graf[v].push_back(make_pair(w, u));
		}
		
		// bfs cada nodo
		vector< vector< tint > > dists;
		for(unsigned int i=0; i<graf.size(); i++){
			vector<tint> d = bfs(graf, i);
			dists.push_back(d);
		}
		
		//break;
		// cada hacks
		for(unsigned int i=0; i<hacks.size(); i++){
			if(i) cout << " ";
			int s = hacks[i].first;
			int t = hacks[i].second;
			cout << dists[s-1][t-1];
		}
		cout << endl;
		
		// fin
		cin >> C >> L >> H;
	}

	return 0;
}
