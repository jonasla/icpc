#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define mp make_pair

typedef long long tint;
typedef pair<int, int> ii;
typedef vector<tint> vi;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int acc(char c) {
	if (c == 'U') return 0;
	if (c == 'D') return 1;
	if (c == 'L') return 2;
	if (c == 'R') return 3;
	return -1;
}

struct Nodo {
	int i, j, k;
	Nodo(int x, int y, int kk) {
		i = x;
		j = y;
		k = kk;
	}
};

const int INF = 99999999;
int N, M; 
vector<vi> map;
vector<vector<vi>> dist;

bool movimientoValido(int xn, int yn) {
    return (xn >= 0 && xn < N && yn >= 0 && yn < M && !map[xn][yn]);
}

void relajarPeso(int xn, int yn, int k, tint nuevaDist, deque<Nodo> &Q, bool front) {
    if (dist[xn][yn][k] > nuevaDist) {
        dist[xn][yn][k] = nuevaDist;
        if (front)
            Q.push_front(Nodo(xn,yn,k));
        else 
            Q.push_back(Nodo(xn,yn,k));
    }
}

int main() {
	cin >> N >> M;
	map = vector<vi>(N, vi(M, 0));
	int Rx = -1, Ry = -1, Ex = -1, Ey = -1;
	
	forn(i,N){
		forn(j,M){
			char c; cin >> c;
			if (c == 'R'){
				Rx = i; Ry = j;
			} else if (c == 'E') {
				Ex = i; Ey = j;
			} else if (c == '#') {
				map[i][j] = 1;
			}
		}
	}
	string str;
	cin >> str;
	
	dist = vector<vector<vi>>(N, vector<vi>(M, vi(str.size()+1, INF)));
	dist[Rx][Ry][0] = 0;
	deque<Nodo> Q;
	Q.push_front(Nodo(Rx,Ry,0));
	while(!Q.empty()){
		Nodo p = Q.front();
		Q.pop_front();
		int xx = p.i, yy = p.j, k = p.k;
		// agregar letra
		forn(i,4){
			int xn = xx - dx[i];
			int yn = yy - dy[i];
			if(movimientoValido(xn,yn)){
                tint nuevaDist = dist[xx][yy][k]+1;
                relajarPeso(xn,yn,k,nuevaDist,Q,false);
            }
		}
		// usar letra
		if (k < (int)str.size()){
			int ac = acc(str[k]);
			int xn = xx - dx[ac];
			int yn = yy - dy[ac];
			if(movimientoValido(xn,yn)){
                tint nuevaDist = dist[xx][yy][k];
                relajarPeso(xn,yn,k+1,nuevaDist,Q,true);
			} else {
                tint nuevaDist = dist[xx][yy][k];
                relajarPeso(xx,yy,k+1,nuevaDist,Q,true);
			}
		}
		// borrar letra
		if (k < (int)str.size()){ 
            tint nuevaDist = dist[xx][yy][k]+1;
            relajarPeso(xx,yy,k+1,nuevaDist,Q,false);
		}
	}

	tint SOL = INF;
	for(auto bla : dist[Ex][Ey]){
		SOL = min(SOL, bla);
	}
	cout << SOL << endl;
	return 0;
}
