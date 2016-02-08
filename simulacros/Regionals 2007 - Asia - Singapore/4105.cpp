#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef long long tint;
typedef pair<int, int> ii;
int R, T;

#define forn(i,n) for(tint i=0;i<(tint)(n);i++)
#define forsn(i,s,n) for(tint i=(s);i<(tint)(n);i++)
#define MAXN 505
#define pb push_back
#define mp make_pair

bool esta[MAXN][MAXN];
vector<ii> ady[MAXN][MAXN];

int main(){
	int CASOS; cin >> CASOS;
	forn(caso, CASOS){
		cin >> R >> T;
		forn(i,MAXN){
			memset(esta[i], false, sizeof(esta[i]));
			forn(j,MAXN){
				ady[i][j].clear();
			}
		}
		forn(i,T+1){
			esta[i][0  ] = true;
			esta[i][R+1] = true;
		}
		///
		vector<bool> stat(R, true);
		forn(i,T){
			forn(j,R){
				if(stat[j]){
					esta[i][j+1] = true;
				}
				char o; cin >> o;
				if(o == 's') stat[j] = false;
				else if(o == 'r') stat[j] = true;
			}
		}
		/*
		forn(i,T+1){
			forn(j,R+2){
				cout << esta[i][j] << " ";
			}cout << endl;
		}
		*/
		///
		forn(i,T+2){
			forn(j,R+2){
				#define hia esta[i+1][j-1]
				#define hii esta[i  ][j-1]
				
				#define hda esta[i+1][j+1]
				#define hdi esta[i  ][j+1]
				
				#define ha esta[i+1][j  ]
				
				if(ha) 						ady[i][j].pb(mp(i+1,j  ));
				if(j > 0   && hia && hii) 	ady[i][j].pb(mp(i+1,j-1));
				if(j < R+1 && hda && hdi) 	ady[i][j].pb(mp(i+1,j+1));
			}
		}
		/// ponele que arme el grafo
		queue<ii> Q; 
		Q.push(mp(0,0));
		
		vector<vector<int > > dist(MAXN, vector<int>(MAXN, -1));
		dist[0][0] = 0;
		
		while(!Q.empty()){
			ii v = Q.front(); 
			Q.pop();
			for(auto &vec : ady[v.first][v.second]){
				if (dist[vec.first][vec.second] == -1){
					dist[vec.first][vec.second] = dist[v.first][v.second] + 1;
					Q.push(vec);
				}
			}
		}
		///
		/*
		forn(i,T+1){
			forn(j,R+2){
				//cout << esta[i][j] << " ";
				printf("%02d  ", dist[i][j]);
			}cout << endl;
		}
		*/
		///
		int res = -1;
		forn(i,T+1){
			if(dist[i][R+1] != -1){
				res = i;
				break;
			}
		}
		if(res > 0) res--;
		cout << res << endl;
	}
	cin >> CASOS;
	return 0;
}
