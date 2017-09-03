#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

typedef long tint;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)
#define forsn(i,s,n) for (tint i = tint(s); i < tint (n); i++)

int dx[] = { 1,  0, -1, -1, -1,  0,  1,  1};
int dy[] = { 1,  1,  1,  0, -1, -1, -1,  0};

int N, M;
bool enGrilla(int i, int j) {
	return i>=0 && j>=0 && i<N+2 && j<M+2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> N >> M) {
		vector<vi> mapa(N+2, vi(M+2, 0));
		vector<vi> visit(N+2, vi(M+2, 0));
		vector<vi> comps(N+2, vi(M+2, 0));
		char c;
		forsn(i,1,N+1){
			forsn(j,1,M+1){
				cin >> c;
				if (c == '#') mapa[i][j] = 2;	// edificio
				if (c == '*') mapa[i][j] = 1;	// pared
			}
		}
		//
		int COMP = 0;
		map<int, int> edificios;
		vector<pair<int, int> > paredes;
		queue<pair<int, int> > Q;
		forn(i,N+2){
		forn(j,M+2){
			// no visitado y no pared
			if (!visit[i][j] && mapa[i][j] != 1) {
				// bfs
				COMP++;
				int edi = 0;
				
				Q.push({i,j});
				visit[i][j] = true;
				comps[i][j] = COMP;
				while(!Q.empty()){
					auto p = Q.front(); Q.pop();
					int x = p.first, y = p.second;
					if (mapa[x][y]==2) {
						//~ cout << "fjksdjfksjfks\n";
						edi++;
					}
					int xx, yy;
					//~ cout << "------ " << x << " " << y << "\n";
					forn(k,8) {
						
						xx = x - dx[k];
						yy = y - dy[k];
						if (enGrilla(xx, yy) && !visit[xx][yy] && mapa[xx][yy] != 1) {
							//~ cout << xx << " " << yy << endl;
							Q.push({xx,yy});
							visit[xx][yy] = true;
							comps[xx][yy] = COMP;
						} else if (enGrilla(xx, yy) && !visit[xx][yy] && mapa[xx][yy] == 1 && COMP==1) {
							paredes.push_back({xx,yy});
							visit[xx][yy] = true;
						}
					}
				}
				//~ cout << edi << endl;
				edificios[COMP] = edi;
			}
		}
		}
		//
		int ANS = edificios[1];
		for(auto &p : paredes) {
			int x = p.first, y = p.second;
			set<int> cmp;
			forn(k,8){
				cmp.insert(comps[x-dx[k]][y-dy[k]]);
			}
			int nueva = 0;
			for(auto casita : cmp) nueva += edificios[casita];
			ANS = max(ANS, nueva);
		}
		cout << ANS << "\n";
	}
	return 0;
}
