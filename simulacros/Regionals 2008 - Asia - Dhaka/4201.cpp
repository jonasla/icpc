#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

vi bfs(vector<vi> &graf, int s){
	vi dists(graf.size(), -1);
	dists[s] = 0;
	
	queue<int> Q; Q.push(s);
	
	while(!Q.empty()){
		int nod = Q.front();
		Q.pop();
		
		for(auto ady : graf[nod]){
			if(dists[ady] == -1){
				dists[ady] = dists[nod] + 1;
				Q.push(ady);
			}
		}
		
	}
	
	return dists;
}

void printVector(vi &v){
	for(unsigned int i=0; i<v.size(); i++){
		if(i) cout << " ";
		cout << v[i];
	}
	cout << endl;
}

int toBase10(unsigned long long base10){
	int ret = 0;
	int count = 1;
	
	while(base10 > 0){
		if(base10 % 10 == 1){
			ret += count;
			//cout << "sumo " << count << endl;
		}
		count *= 2;
		base10 /= 10;
	}
	
	return ret;
}

int main(){
	
	//cout << toBase10(101) << endl;
	
	int T; cin >> T;
	for(int CASO=1; CASO <= T; CASO++){
		int N, M; cin >> N >> M;
		
		vi switches(M, 0);
		//switches
		for(int i=0; i<M; i++){
			int k; cin >> k;
			for(int j=0; j<k; j++){
				int lamp; cin >> lamp; //lamp++;
				switches[i] += (1<<lamp);
			}
		}
		
		//printVector(switches);
		
		//grafo
		vector<vi> graf(1<<N);
		for(unsigned int i=0; i<graf.size(); i++){
			for(unsigned int j=0; j<switches.size(); j++){
				graf[i].push_back(i ^ switches[j]);
			}
		}
		
		vi distancias = bfs(graf, 0);
		//printVector(distancias);
		
		int Q; cin >> Q;
		vi queries(Q, 0);
		
		for(int i=0; i<Q; i++){
			
			unsigned long long comb; cin >> comb;
			
			queries[i] = toBase10(comb);
			
		}
		
		//printVector(queries);
		
		cout << "Case " << CASO << ":\n";
		for(unsigned int i=0; i<queries.size(); i++){
			cout << distancias[queries[i]] << endl;
		}
		
		cout << endl;
	}

	return 0;
}
