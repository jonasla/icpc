#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long tint;

unsigned long long floyd(vector<vector<int> > g, int ign){
	int n = g.size();
	
	for(int k=0; k<n; k++)
		if(k != ign)
			for(int i=0; i<n; i++)
				if(i != ign)
					for(int j=0; j<n; j++)
						if(j != ign)
							g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	
	return g[0][g.size()-1];
}

int main(){
	
	int N, M;
	cin >> N >> M;
	
	while(N){
		vector<vector<int> > graf(N, vector<int>(N, -1));
		for(int i=0; i<N; i++){
			graf[i][i] = 0;
		}
		
		unsigned long long INF = 0;
		
		for(int i=0; i<M; i++){
			int u, v, w;
			cin >> u >> v >> w;
			
			graf[u-1][v-1] = w;
			graf[v-1][u-1] = w;
			
			INF += w;
		}
		
		//cout << INF << endl;
		
		for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		if(graf[i][j] == -1) graf[i][j] = INF;
		
		// N floyds
		unsigned long long MAXPAGO = 0;
		for(int i=1; i<N-1; i++){
			unsigned long long minPago = floyd(graf, i);
			//cout << minPago << endl;
			MAXPAGO = max(MAXPAGO, minPago);
		}
		
		if(MAXPAGO == INF){
			cout << "Inf\n";
		}else{
			cout << MAXPAGO << endl;
		}
				
		cin >> N >> M;
		
	}
	
	return 0;
}
