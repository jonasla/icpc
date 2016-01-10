#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n); i++)

void imprimirVector (vector<int> &v){
	if (!v.empty()){
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}else
		cout << "[]" << endl;
}

vector<int> BFS(vector<vector<int> > &lista, int nodoIni){
	int n = lista.size(), t;
	queue<int> cola;
	vector<int> dist(n,n);
	cola.push(nodoIni);
	dist[nodoIni] = 0;
	while(!cola.empty()){
		t = cola.front();
		cola.pop();
		for(unsigned int i=0; i<lista[t].size(); i++){
			if(dist[lista[t][i]] == n){
				dist[lista[t][i]] = dist[t]+1;
				cola.push(lista[t][i]);
			}
		}
	}
	return dist;
}

int main(){

	int n;
	cin >> n;
	
	while(n != -1){
		
		vector<vector<int> > graf(n);
		
		for(int i=1; i<n; i++){
			
			int t;
			cin >> t;
			
			graf[i].push_back(t-1);
			graf[t-1].push_back(i);			
		}
		
		///primer BFS desde cualquier nodo
		vector<int> dist1 = BFS(graf, 0);
		//imprimirVector(dist1);
		int maxelemidx1 = max_element(dist1.begin(), dist1.end()) - dist1.begin();
		//cout << maxelemidx1 << endl;
		
		///segundo BFS desde el nodo mas lejano
		vector<int> dist2 = BFS(graf, maxelemidx1);
		//imprimirVector(dist2);
		
		int diam = (*max_element(dist2.begin(), dist2.end())) + 1;
		int radio = diam >> 1;
		
		//cout << diam << endl;
		cout << radio << endl;
		
		cin >> n;
	}

	return 0;
}
