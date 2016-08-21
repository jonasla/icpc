#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++) 
#define forsn(i,s,n) for(int i=(int)s; i<(int)n; i++) 
#define dforn(i,n) for(int i=(int)(n-1); i>=0; i--) 

// 26 * 2 * 2 = 104

const int MAXN = 104;
const int lets = 26;
typedef long long tint; 
typedef vector<int> vi;

int nodeNumber(char c, int p, int v){
	//A1,  B1,  C1, ... 
	//A2,  B2,  C2, ...
	//!A1, !B1, !C1, ...
	//!A2, !B2, !C2, ...
	int r = (int)(c-'A');
	if (p==2) r+=(lets);
	if (!v) r+=(lets*2);
	return r;
}

int notNode(int node){
	if(node>=lets*2) return node-2*lets;
	else return node+2*lets;
}

void dfs(int s, vector<vi> &graf, vi &visit, stack<int> &S){
	visit[s] = true;
	for(auto u : graf[s]){
		if(!visit[u]) dfs(u, graf, visit, S);
	}
	S.push(s);
}

void printVec(vi &v){
        for(auto &e : v) cout << e << " ";
        cout << endl;
}

int main(){
	int N; 
	forsn(i,3,27){
                cout << i << "\t" << (i*(i-1)*(i-2))/6 << endl;
        }
	while(cin >> N){
		vector<vi> graf(MAXN, vi());
		vector<vi> grafInv(MAXN, vi());
                vi letrasTocadas(26, false);
		forn(i,N){
			string par; int play, cant;
			cin >> par >> play >> cant;
			char a, b; a = par[0]; b = par[1];
			int nodA = nodeNumber(a, play, 1);
			int nodNoA = nodeNumber(a, play, 0);
			int nodB = nodeNumber(b, play, 1);
			int nodNoB = nodeNumber(b, play, 0);
                        letrasTocadas[a-'A'] = true;
                        letrasTocadas[b-'A'] = true;
			if(cant == 0){			// no tiene a y no tiene b
				graf[nodA].push_back(nodNoA);
				graf[nodB].push_back(nodNoB);
				
				grafInv[nodNoA].push_back(nodA);
				grafInv[nodNoB].push_back(nodB);
			}else if(cant == 1){	        // tiene a o b (exactamente 1)
				graf[nodNoA].push_back(nodB);
				graf[nodA].push_back(nodNoB);
				graf[nodNoB].push_back(nodA);
				graf[nodB].push_back(nodNoA);
				
				grafInv[nodNoA].push_back(nodB);
				grafInv[nodA].push_back(nodNoB);
				grafInv[nodNoB].push_back(nodA);
				grafInv[nodB].push_back(nodNoA);
			}else if(cant == 2){	        // tiene a y b
				graf[nodNoA].push_back(nodA);
				graf[nodNoB].push_back(nodB);
				
				grafInv[nodA].push_back(nodNoA);
				grafInv[nodB].push_back(nodNoB);
			}
		}
                forn(i,26){
                        if(!letrasTocadas[i]){
                                int nodX = nodeNumber(i+'A', 1, 1);
                                int nodNoX = nodeNumber(i+'A', 1, 0);
				graf[nodX].push_back(nodNoX);
				grafInv[nodNoX].push_back(nodX);
                                
                                nodX = nodeNumber(i+'A', 2, 1);
                                nodNoX = nodeNumber(i+'A', 2, 0);
				graf[nodX].push_back(nodNoX);
				grafInv[nodNoX].push_back(nodX);
                        }
                }
		vi visit(MAXN, 0);
		stack<int> S;
		forn(i,MAXN) if(!visit[i]) dfs(i, graf, visit, S);
		
		vi visitInv(MAXN, 0);
		vi CC(MAXN, -1);
		int CCs = 0;
                vector<vi> comps;
		while(!S.empty()){
			int v = S.top(); S.pop();
			if(!visitInv[v]){
				stack<int> Si; 
				dfs(v, grafInv, visitInv, Si);
                                vi Ci;
				while(!Si.empty()){
					int u = Si.top(); Si.pop();
					CC[u] = CCs;
                                        Ci.push_back(u);
				}
                                comps.push_back(Ci);
                                CCs++;
			}
		}
                
                //Chequear si hay contradiccion
                printVec(CC);
                bool haySolucion = true;
                vi val(MAXN, -1);
                forn(i,MAXN){
                        if(CC[i] == CC[notNode(i)]) haySolucion = false;
                }
                if(!haySolucion) cout << 0 << endl;
                else{
                        dforn(i,CCs){
                                if(val[comps[i][0]] == -1){
                                        for(auto n : comps[i]) {
                                                val[n] = 1;
                                                val[notNode(n)] = 0;
                                        }
                                }
                        }
                        dforn(i,2){
                                forn(j,2){
                                        forn(k,26){
                                                int nn = nodeNumber(k+'A', j+1, i);
                                                cout << (char)('A'+k) << " " << j+1 << " " << i << " -> " << val[nn] << endl;
                                        }
                                }
                        }
                        int cantFuera=26;
                        vi cartaTomada(26, false);
                        forn(j,2){
                                forn(k,26){
                                        int nn = nodeNumber(k+'A', j+1, 1);
                                        if(val[nn]) cartaTomada[k] = true;
                                }
                        }
                        forn(i,26){
                                if(cartaTomada[i]) cantFuera--;
                        }
                        cout << "Cantidad fuera: " << cantFuera << endl;
                        cout << (cantFuera*(cantFuera-1)*(cantFuera-2))/6 << endl;
                }
                
	}
	return 0;
}
