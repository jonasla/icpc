#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

#define forsn(i,s,n) for (int i = (s); i <(int) (n); i++)
#define forn(i,n) for (int i = 0; i <(int) (n); i++)

typedef long long tint;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef unsigned long long utint;

vi graf[1050];
bool visit[1050];


#define pb push_back

void dfs(int s, vi &nods){	
	visit[s] = true;
	nods.pb(s);
	
	//cout << "visito " << s << endl;
	for(unsigned int i=0; i<graf[s].size(); i++){
		if(!visit[graf[s][i]]){			
			dfs(graf[s][i], nods);
		}
	}
}

void clearALL(){
	for(int i=0; i<1050; i++){
		visit[i] = false;
		graf[i].clear();
	}
}

int main(){

	int N, M, R, E; 
	
	while(cin >> N >> M >> R >> E && N != 0){
		
		clearALL();
		
		forn(i, M){
			int u , v; cin >> u >> v;
			graf[u].pb(v);
			graf[v].pb(u);
		}
		
		utint TOTAL = 0;
		
		for(int i=1; i<=N; i++){
			if(!visit[i]){
				vi nods;
				dfs(i, nods);
				
				int ars = 0;
				
				//cout << nods.size() << endl;
				for(unsigned int j=0; j<nods.size(); j++){
					//cout << "nod " << nods[i] << endl;
					
					ars += graf[nods[j]].size();
				}
				ars /= 2;
				
				//cout << "tiene aristas " << ars << endl;
				int cantNods = nods.size();
				if(cantNods == 1){
					TOTAL += 0;
				}else{
					int faltan = (cantNods*(cantNods-1))/2 - ars;
					
					//cout << "faltan " << faltan << endl;
					
					int SUMO = min(faltan*R, cantNods*E);
					//cout << "sumo " << SUMO << endl;
					TOTAL += SUMO; 
				}
				
			}
		}
		
		cout << TOTAL << endl;
	}
	return 0;
}
