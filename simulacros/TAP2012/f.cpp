#include <deque>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <string>

#define forn(i,n) for (tint i = 0; i <(tint) (n); i++)
#define forsn(i,s,n) for (tint i = (s); i <(tint) (n); i++)

typedef long long tint;

using namespace std;

struct part{
	int a, b, i;
};

// a, b, i
// a > b

vector<part> graf[100][100];
bool graf_exist[100][100];

int idxPart(int a, int b){
	if(b < a) swap(a, b);
	return a*10 + b;
}

void dfs(int nod, int it, vector<vector<bool > > &visit, vector<int> &topo){
	for(unsigned int i=0; i<graf[nod][it].size(); i++){
		part p = graf[nod][it][i];
		
		int idx = idxPart(p.a, p.b);
		int numi = p.i;
		
		if(!visit[idx][numi] && graf_exist[idx][numi]){
			//cout << "visito ady " << nod << " " << it << " -> " << idx << " " << numi << endl;
			visit[idx][numi] = true;
			dfs(idx, numi, visit, topo);
		}
	}
	
	//
	if(graf_exist[nod][it]){
		int a = nod / 10;
		int b = nod % 10;
		if(a == 1){
			topo.push_back(b);
		}else if(b == 1){
			topo.push_back(a);
		}
	}
}

int main()
{
	//cout << idxPart(1,2) << endl;
	//cout << idxPart(2,1) << endl;
	//cout << idxPart(8,9) << endl;
	//cout << idxPart(9,8) << endl;
	//return 0;
	
	int N; cin >> N;
	while(N != -1){ 
		for(int i=0; i<100; i++)
		for(int j=0; j<100; j++){
			graf_exist[i][j] = false;
			graf[i][j].clear();
		}
		
		vector<string> partidas;
		for(int i=1; i<N; i++){
			string p; cin >> p;
			partidas.push_back(p);
		}
		
		// armar grafo
		for(int i=0; i<N-1; i++){
			
			vector<int> cantP(N+1, 0);
			
			int a = i + 2;
			int b = (int)(partidas[i][0] - '1') + 1;
			
			part pini; 
			pini.a = a;
			pini.b = b;
			pini.i = 0;
			
			graf_exist[idxPart(pini.a, pini.b)][pini.i] = true;
			//cout << "Primer partida: " << pini.a << " " << pini.b << " " << pini.i << endl;
			
			cantP[b]++;
			
			for(unsigned int j=1; j<partidas[i].size(); j++){
				b = (int)(partidas[i][j] - '1') + 1;
				
				part pfin;
				pfin.a = a;
				pfin.b = b;
				pfin.i = cantP[b];
				
				graf[idxPart(pini.a, pini.b)][pini.i].push_back(pfin);
				graf_exist[idxPart(pini.a, pini.b)][pini.i] = true;
				graf_exist[idxPart(pfin.a, pfin.b)][pfin.i] = true;
				
				//
				//cout << "Al nodo " << idxPart(pini.a, pini.b) << " " << pini.i << " le meto " << idxPart(pfin.a, pfin.b) << " " << pfin.i << endl;
				cantP[b]++;
				
				pini = pfin;
				
			}
		}
		// topo sort
		vector<int> ordenTopo;
		vector<vector<bool > > visit(100, vector<bool>(100, false));
		
		for(int i=0; i<100; i++){
			for(int j=0; j<100; j++){
				if(!visit[i][j] && graf_exist[i][j]){
					//cout << "visito nodo " << i << " " << j << endl;
					visit[i][j] = true;
					dfs(i, j, visit, ordenTopo);
				}
			}
		}
		
		// topo?
		//cout << "TOPO\n";
		reverse(ordenTopo.begin(), ordenTopo.end());
		for(unsigned int i=0; i<ordenTopo.size(); i++){
			cout << ordenTopo[i];
		}
		cout << endl;
		
		//
		cin >> N;
	}

	return 0;
}
