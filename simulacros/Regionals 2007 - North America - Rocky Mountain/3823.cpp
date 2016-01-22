#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pto;

ll distS(pto &p1, pto &p2){
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int main(){

	int T;
	cin >> T;
	forn(caso,T){
		int N, S, E;
		double l1, l2;
		cin >> N >> S >> E >> l1 >> l2;
		S--; E--;
		
		double largoTS = (l1+l2)*(l1+l2);
		//cout << largoTS << endl;
		
		vector<pto> ptos;
		forn(i,N){
			ll xx, yy; cin >> xx >> yy;
			ptos.pb(mp(xx,yy));
		}
		
		vector<vi> graf(N, vi());
		
		forn(i,N){
		forsn(j,i+1,N){
			ll dist = distS(ptos[i], ptos[j]);
			if((double)dist <= largoTS){
				graf[i].pb(j);
				graf[j].pb(i);
			}
		}
		}
		
		vi distancias(N, -1);
		distancias[S] = 0;
		queue<int> Q;
		Q.push(S);
		while(!Q.empty()){
			int act = Q.front();
			Q.pop();
			
			for(auto &ady : graf[act]){
				if(distancias[ady] == -1){
					distancias[ady] = distancias[act] + 1;
					Q.push(ady);
				}
			}
		}
		if(distancias[E] == -1){
			cout << "Impossible\n";
		}else{
			cout << distancias[E] << endl;
		}
	}

	return 0;
}
