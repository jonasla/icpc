#include <vector>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define pb push_back
#define mp make_pair
#define MAXN 512
#define INFTO 0x7f7f7f7f

const int INF = 1000000000;

int R;
int mt[MAXN][MAXN];	// Matriz de costos
int xy[MAXN], yx[MAXN];	// Matching

// Cosas del matching...
int lx[MAXN], ly[MAXN], slk[MAXN], slkx[MAXN], prv[MAXN];
char S[MAXN], T[MAXN];

// Hungaro, tal cual notebook...
void updtree(int x){
	forn(y, R) if (lx[x] + ly[y] - mt[x][y] < slk[y]) {
		slk[y] = lx[x] + ly[y] - mt[x][y];
		slkx[y] = x;
	}
}

int hungar(){
	forn(i, R){
		ly[i] = 0;
		lx[i] = *max_element(mt[i], mt[i]+R);
	}
	memset(xy, -1, sizeof(xy));
	memset(yx, -1, sizeof(yx));
	forn(m, R){
		memset(S, 0, sizeof(S));
		memset(T, 0, sizeof(T));
		memset(prv, -1, sizeof(prv));
		memset(slk, 0x7f, sizeof(slk));
		queue<int> q;
		#define bpone(e, p) { q.push(e); prv[e] = p; S[e] = 1; updtree(e); }
		forn(i, R) if (xy[i] == -1) { bpone(i, -2); break; }
		int x=0, y=-1;
		while(y==-1){
			while(!q.empty() && y==-1){
				x = q.front(); q.pop(); 
				forn(j, R) if(mt[x][j] == lx[x] + ly[j] && !T[j]) {
					if (yx[j] == -1) { y = j; break; }
					T[j] = 1;
					bpone(yx[j], x);
				}
			}
			if(y!=-1) break;
			int dlt = INFTO;
			forn(j, R) if(!T[j]) dlt = min(dlt, slk[j]);
			forn(k, R) {
				if(S[k]) lx[k] -= dlt;
				if(T[k]) ly[k] += dlt;
				if(!T[k]) slk[k] -= dlt;
			}
			forn(j, R) if (!T[j] && !slk[j]) {
				if(yx[j] == -1){
					x = slkx[j]; y = j; break;
				} else{
					T[j] = 1;
					if (!S[yx[j]]) bpone(yx[j], slkx[j]);
				}
			}
		}
		if(y!=-1) { 
			for(int p=x; p!= -2; p = prv[p]){
				yx[y] = p;
				int ty = xy[p]; xy[p] = y; y = ty;
			}
		}else break;
	}
	int res = 0;
	forn(i, R) res += mt[i][xy[i]];
	return res;
}

// Fin hungaro :D 
void printHora(int mins){
	int h = 8;
	h += mins/60;
	mins = mins % 60;
	printf("%02d:%02d\n", h, mins);
}

int main(){
	int CASOS; cin >> CASOS;
	forn(casito,CASOS){
		int V, E; cin >> V >> E;
		vector<vi> graf(V, vi(V, INF));
		// Edges
		forn(i,E){
			int a, b, t; cin >> a >> b >> t; a--; b--;
			graf[a][b] = t;
			graf[b][a] = t;
		}
		// Representatives 
		cin >> R;
		vii reprs(R);
		forn(i,R){
			int r, d; cin >> r >> d; r--; d--;
			reprs[i] = mp(r,d);
		}
		// Customers
		int C; cin >> C;
		vi customs(C);
		forn(i,C){
			int c; cin >> c; c--;
			customs[i] = c;
		}
		// Stations
		int M; cin >> M;
		vi stations(M);
		forn(i,M){
			int s; cin >> s; s--;
			stations[i] = s;
		}
		// Floyd
		forn(k,V) forn(i,V) forn(j,V) graf[i][j] = min(graf[i][j], graf[i][k] + graf[k][j]);
		// Costos Tareas
		forn(i,R){
			ii r = reprs[i];
			/// Pasar por un cliente
			forn(j,C){
				int c = customs[j];
				/// Costo de ir de la casa hasta el cliente
				int costI = graf[r.first][c];
				/// Costo de ir del cliente a alguna estacion y luego a su oficina
				int costF = INF;
				for(auto &s : stations){
					costF = min(costF, graf[c][s] + graf[s][r.second]);
				}
				/// Costo total (suma)
				mt[i][j] = costI + costF;
			}
			/// Solamente ir a su oficina
			forsn(j,C,R){
				mt[i][j] = graf[r.first][r.second];
			}
		}
		forn(i,R) forn(j,R) mt[i][j] = -mt[i][j];
		// Hungaro...
		int RES = hungar();
		RES = -RES;
		
		int MINS = RES/R;
		if(RES % R) MINS++;
		printHora(MINS);
	}
	return 0;
}
