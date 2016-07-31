#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

#define forn(i,n) for(int i  = 0; i < int(n); i++)
#define dforn(i,n) for(int i  = (int)(n-1); i >= 0; i--)
#define forsn(i,j,n) for(int i  = (int)j; i < int(n); i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long tint;
typedef pair<int, pair<int,int> > seg;
typedef pair<int, int> ii;
typedef deque<int> dqi;
typedef deque<ii> dqii;
typedef deque<seg> dqseg;

const tint maxN = 60050;

dqii staH1;
dqii endH1;
dqii staH2;
dqii endH2;

dqseg ver1;
dqseg ver2;

typedef int tipo;

struct RMQ {
	
	int MAX;
	tipo vec[4*maxN];
	tipo * init(int N){
		MAX = 1 << (32 - __builtin_clz(N));
		fill(vec, vec+2*MAX, 0);
		return vec+MAX;
	}
	void updall() { dforn(i,MAX) vec[i] = vec[2*i] + vec[2*i+1]; }
	void pset(int i, tipo v1) {
		vec[i+=MAX] = v1;
		while(i) { i/=2; vec[i] = vec[2*i] + vec[2*i+1]; }
	}
	tipo pget(int i, int j) { return _pget(i+MAX, j+MAX); }
	tipo _pget(int i, int j) {
		tipo res = 0;
		if(j-i <= 0) return res;
		if (i%2) res += vec[i++];
		res += _pget(i/2, j/2);
		if (j%2) res += vec[--j];
		return res;
	}
} rmq1, rmq2;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int N; 
	int sx, sy; 
	int ax, ay;
	int s, e;
	
	// AUTO 1
	cin >> N;
	cin >> sx >> sy;
	ax=sx, ay=sy;
	forsn(i,1,N){
		int cx, cy; cin >> cx >> cy;
		if(cx-ax==0){	// ver
			s = min(cy,ay);
			e = max(cy,ay);
			ver1.pb(mp(ax, mp(s,e)));
		}else if(cy-ay==0){	// hor
			s = min(cx,ax);
			e = max(cx,ax);
			staH1.pb(mp(s,ay));
			endH1.pb(mp(e,ay));
		}
		ax=cx; ay=cy;
	}
	if(sx-ax==0){	// ver
		s = min(sy,ay);
		e = max(sy,ay);
		ver1.pb(mp(ax, mp(s,e)));
	}else if(sy-ay==0){	// hor
		s = min(sx,ax);
		e = max(sx,ax);
		staH1.pb(mp(s,ay));
		endH1.pb(mp(e,ay));
	}

	sort(staH1.begin(), staH1.end());
	sort(endH1.begin(), endH1.end());
	sort(ver1.begin(), ver1.end());
	
	// AUTO 2
	cin >> N;
	cin >> sx >> sy;
	ax=sx, ay=sy;
	forsn(i,1,N){
		int cx, cy; cin >> cx >> cy;
		if(cx-ax==0){	// ver
			s = min(cy,ay);
			e = max(cy,ay);
			ver2.pb(mp(ax, mp(s,e)));
		}else if(cy-ay==0){	// hor
			s = min(cx,ax);
			e = max(cx,ax);
			staH2.pb(mp(s,ay));
			endH2.pb(mp(e,ay));
		}
		ax=cx; ay=cy;
	}
	if(sx-ax==0){	// ver
		s = min(sy,ay);
		e = max(sy,ay);
		ver2.pb(mp(ax, mp(s,e)));
	}else if(sy-ay==0){	// hor
		s = min(sx,ax);
		e = max(sx,ax);
		staH2.pb(mp(s,ay));
		endH2.pb(mp(e,ay));
	}

	sort(staH2.begin(), staH2.end());
	sort(endH2.begin(), endH2.end());
	sort(ver2.begin(), ver2.end());
	///
	tint RES = 0;
	//cout << "holsdjkgjsdk" << endl;

	// RMQ1 tiene los horizontales de 1
	rmq1.init(maxN);
	rmq1.updall();
	while(!ver2.empty() || !staH1.empty() || !endH1.empty()){
		seg ver = mp(maxN, mp(0,0));
		if(!ver2.empty()){
			ver = ver2.front();
		}
		int sh = maxN;
		int eh = maxN;
		if(!staH1.empty()){
			sh = staH1.front().first;
		}
		if(!endH1.empty()){
			eh = endH1.front().first;
		}

		ii evnE = mp(eh,0);
		ii evnQ = mp(ver.first,1);
		ii evnS = mp(sh,2);
		deque<ii> eventos = {evnE, evnQ, evnS};
		sort(eventos.begin(), eventos.end());

		ii elevento = eventos.front();
		if(elevento.second == 0){ // end
			//cout << "end\n";
			rmq1.pset(endH1.front().second, 0);
			endH1.pop_front();
		}else if(elevento.second == 1){	// query
			//cout << "query\n";
			RES += rmq1.pget(ver.second.first, ver.second.second+1);
			ver2.pop_front();
		}else if(elevento.second == 2){	// start
			//cout << "start\n";
			rmq1.pset(staH1.front().second, 1);
			staH1.pop_front();
		}
	}
	//cout << "RMQ2\n";

	// RMQ1 tiene los horizontales de 1
	rmq2.init(maxN);
	rmq2.updall();
	while(!ver1.empty() || !staH2.empty() || !endH2.empty()){
		seg ver = mp(maxN, mp(0,0));
		if(!ver1.empty()){
			ver = ver1.front();
		}
		int sh = maxN;
		int eh = maxN;
		if(!staH2.empty()){
			sh = staH2.front().first;
		}
		if(!endH2.empty()){
			eh = endH2.front().first;
		}

		ii evnE = mp(eh,0);
		ii evnQ = mp(ver.first,1);
		ii evnS = mp(sh,2);
		deque<ii> eventos = {evnE, evnQ, evnS};
		sort(eventos.begin(), eventos.end());

		ii elevento = eventos.front();
		if(elevento.second == 0){ // end
			//cout << "end\n";
			rmq2.pset(endH2.front().second, 0);
			endH2.pop_front();
		}else if(elevento.second == 1){	// query
			//cout << "query\n";
			RES += rmq2.pget(ver.second.first, ver.second.second+1);
			ver1.pop_front();
		}else if(elevento.second == 2){	// start
			//cout << "start\n";
			rmq2.pset(staH2.front().second, 1);
			staH2.pop_front();
		}
	}

	
	cout << RES << "\n";
	
	return 0;
}
