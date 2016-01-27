#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>

using namespace std;

#define forn(i,n) for(int i=0; i < (int) (n); i++)
#define forsn(i,s,n) for(int i=(s); i < (int) (n); i++)

#define mp make_pair
#define pb push_back
#define ins insert
#define x first
#define y second
#define sqr(a) ((a)*(a))

typedef long long tint;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef set<int> si;
typedef map<string, int> mstr;
typedef pair<tint, tint> pto;
typedef vector<pto> VP;

const double INF = 1000000000000000000;

tint dist2(pto &p1, pto &p2){
	return sqr(p1.x-p2.x) + sqr(p1.y-p2.y);
}

double dist(pto &p1, pto &p2){
	return sqrt((double)dist2(p1,p2));
}

void dfs(int s, vector<bool> &visit, vector<vi> &arbol, vector<VP> &estaciones, vector<vd> &dp){
	visit[s] = true;
	vi hijos;
	for(auto &ady : arbol[s]){
		if(!visit[ady]){
			hijos.pb(ady);
			dfs(ady, visit, arbol, estaciones, dp);
		}
	}
	///
	forn(i,estaciones[s].size()){	// para cada estacion i de s
		double resI = 0;
		
		for(auto &j : hijos){			// para cada hijo j de s en el dfs
			double minJ = INF;
			
			forn(k,estaciones[j].size()){	// para cada estacion k del hijo j
				double distIK = dist(estaciones[s][i], estaciones[j][k]);
				minJ = min(minJ, distIK + dp[j][k]);
			}
			
			resI += minJ;
		}
		
		dp[s][i] = resI;
	}
}

int main(){
	int N;
	while(cin >> N && N != 0){
		///
		vector<VP> estaciones(N, VP());
		vector<vd> dp(N, vd());
		mstr nombres;
		forn(i,N){
			string name; cin >> name;
			nombres[name] = i;
			int ci; cin >> ci;
			forn(j,ci){
				tint xx, yy; cin >> xx >> yy;
				estaciones[i].pb(mp(xx,yy));
				dp[i].pb(0);
			}
		}
		///
		vector<vi> arbol(N, vi());
		forn(i,N-1){
			string s1, s2; cin >> s1 >> s2;
			int c1 = nombres[s1];
			int c2 = nombres[s2];
			arbol[c1].pb(c2);
			arbol[c2].pb(c1);
		}
		///
		vector<bool> visit(N, false);
		dfs(0, visit, arbol, estaciones, dp);
		double RES = INF;
		forn(i,dp[0].size()){
			RES = min(RES, dp[0][i]);
		}
		printf("%.1f\n", RES);
	}
	return 0;
}
