#include <iostream>
#include <vector>
#include <queue>

#define forn(i,n) for(int (i) = 0; i < int (n); i++)
#define forsn(i,s,n) for(int (i) = s; i < int (n); i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long utint;
typedef long long tint;
typedef pair<int, int> ii;


const int maxN = 100;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool graf[maxN][maxN];
bool visit[maxN][maxN];

bool inG(int x, int y){
	return x>=0 && y>=0 && x<maxN && y<maxN;
}

bool isBorde(int x, int y){
	return x==0 || y==0 || x==maxN-1 || y==maxN-1;
}

int perim(int sx, int sy, bool &borde){
	borde = false;
	int per = 0;
	visit[sx][sy] = true;
	//cout << "visit " << sx << " " << sy << endl;
	queue<ii> Q; Q.push(mp(sx,sy));
	if(isBorde(sx,sy)) borde = true;
	while(!Q.empty()){
		ii v = Q.front(); Q.pop(); per+=4;
		forn(i,4){
			int ax = v.first - dx[i];
			int ay = v.second - dy[i];
			if(inG(ax,ay)){
				if(graf[ax][ay] == graf[sx][sy]){
				per--;
				if(!visit[ax][ay]){
					visit[ax][ay] = true;
					//cout << "visit " << ax << " " << ay << endl;
					Q.push(mp(ax,ay));
					if(isBorde(ax,ay)) borde = true;
				}
				}
			}
		}
	}
	return per;
}

int main(){
	ios::sync_with_stdio(false);
	int N; cin >> N;
	int sx, sy;
	forn(i,N){
		cin >> sx >> sy; sx--; sy--;
		graf[sx][sy] = true;
	}
	bool b = false;
	int per = perim(sx, sy, b);
	//cout << per << endl;
	
	forn(i,maxN){
	forn(j,maxN){
		if(!visit[i][j]){
			int p = perim(i,j,b);
			if(!b) per -= p; //cout << "borde\n" << "resto " << p << endl;; }
			//cout << per << endl;
		}
	}
	}
	
	cout << per << endl;
	return 0;
}
