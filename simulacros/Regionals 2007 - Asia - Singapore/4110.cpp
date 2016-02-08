#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long tint;
typedef pair<tint, pair<tint, tint> > eje;
int N;

#define forn(i,n) for(tint i=0;i<(tint)(n);i++)
#define MAXN 10010
#define pb push_back
#define mp make_pair

vector<eje> ejes;

int _cl[MAXN];
int cl(int i){ return (_cl[i] == -1 ? i : _cl[i] = cl(_cl[i])); }
void join(int i, int j){ if (cl(i) != cl(j)) _cl[cl(i)] = cl(j); }
int krus(){
	if(N==1) return 0;
	sort(ejes.begin(), ejes.end());
	int u = 0; tint t = 0;
	memset(_cl, -1, sizeof(_cl));
	forn(i,ejes.size()){
		eje &e = ejes[i];
		if (cl(e.second.first) != cl(e.second.second)){
			u++; t+= e.first; if(u==N-1) return t;
			join(e.second.first, e.second.second);
		}
	}
	return t;
}
	 
int main()
{	
	int CASOS; cin >> CASOS;
	forn(caso,CASOS){
		cin >> N; int M; cin >> M;
		ejes.clear();
		tint TOT = 0;
		forn(i,M){
			tint u, v, w; cin >> u >> v >> w;
			u--; v--;
			ejes.pb(mp(-w,mp(u,v)));
			TOT += w;
		}
		int res = krus();
		cout << TOT+res << endl;
	}
	cin >> CASOS;
	
	return 0;
}
