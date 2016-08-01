#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

typedef long long tint;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define dforn(i,n) for(int i=(int)(n-1); i>=0; i--)
#define forsn(i,s,n) for(int i=(int)s; i<(int)n; i++)

const int INF = 1000000;	// inifinito de FLUJO
const int MAX_M = 40020;	//	maximo de aristas 
const int MAX_N = 20020;

int v[2*MAX_M], l[2*MAX_M];
long c[2*MAX_M];
int sz[MAX_N], po[MAX_N], r[MAX_N], n, S, T;
typedef map<int,long> Mii;
Mii CAP[MAX_N];
void iniG(){
	n = 0;
	memset(sz,0,sizeof(sz));
	forn(i,MAX_N) CAP[i].clear();
}
void aEje(int d, int h, long cap){
	if (d==h) return;
	n = max(n,max(d,h));
	pair<Mii::iterator,bool> par = CAP[d].insert(make_pair(h,0));
	if(par.second){
		CAP[h][d] = 0;
		sz[d]++;
		sz[h]++;
	}
	par.first->second += max(cap, (long)0);
}
void _aEje(int d, int h, long capDH, long capHD){
	#define ASIG(d,h,cap) { v[po[d]] = h; c[po[d]] = cap; l[po[d]] = po[h]; }
	ASIG(d,h,capDH);
	ASIG(h,d,capHD);
	po[d]++; po[h]++;
}

void _iniG(){
	po[0] = 0;
	forn(i,n-1) po[i+1] = po[i] + sz[i];
	forn(u,n) for(auto &vv : CAP[u])
		if (u < vv.first) _aEje(u,vv.first, vv.second, CAP[vv.first][u]);
}

long aumentar() {
	// bfs
	forn(i,n) r[i] = -1;
	r[S] = 0;
	queue<int> q;
	q.push(S);
	while(!q.empty()){
		int x = q.front(); q.pop();
		int d = r[x] + 1, b = po[x];
		if(r[T] >= 0 && d > r[T]) break;
		forsn(j,b,b+sz[x])
		if(c[j]>0 && r[v[j]] < 0){
			r[v[j]] = d;
			q.push(v[j]);
		}
	}
	// dfs magia
	long res = 0;
	static int path[MAX_N]; path[0] = S;
	static int p[MAX_N], ind[MAX_N];
	memset(p,-1,sizeof(p));
	int pp = 0;	// path pointer, es la longitud
	while(pp >= 0){
		int x = path[pp];
		if (x == T){	// llegamo, hay que hacer magia...
			long f = INF;
			int pri = 0;
			dforn(i,pp) if(c[ind[i]]<=f) f = c[ind[i]], pri = i;
			forn(i,pp) c[ind[i]] -= f, c[l[ind[i]]] += f;
			res += f;
			pp = pri;
		}
		else if (++p[x] < sz[x]){
			int j = po[x]+p[x];
			if(p[v[j]] < 0 && c[j] > 0 && r[v[j]] == 1 + r[x])
				ind[pp] = j, path[++pp] = v[j];
		}
		else pp--;
	}
	return res;
}

long flujo(int ss, int tt){
	S = ss; T = tt;
	n = max(n,max(S,T)) + 1;	// aca, n ya tiene valor posta (que sera esto...) tengo miedo
	_iniG();
	forn(i,n) po[i] -= sz[i];
	
	long res = 0, cc;
	do { res += (cc = aumentar()); } while (cc>0);
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int nods, ars; 
	
	while(cin >> nods >> ars && nods != 0){
		iniG();
		forn(i,ars){	// aristas piolas
			int d,h; cin >> d >> h;
			aEje(d,h+nods,1);
		}
		forn(i,nods){	// aristas s -> primer capa
			aEje(2*nods,i,1);
		}
		forn(i,nods){	// aristas segunda capa -> t
			aEje(i+nods,2*nods+1,1);
		}
		
		long haceMagia = flujo(2*nods,2*nods+1);
		cout << haceMagia << "\n";
	}
	return 0;
}
