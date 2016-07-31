#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define dforn(i,n) for(int i=(int)(n-1); i>=0; i--)
#define forsn(i,s,n) for(int i=(int)s; i<(int)n; i++)
#define pb push_back

typedef long long tint;
typedef vector<tint> vi;

const tint MAXN = 200050;
typedef tint tipo;
struct rmq {
	int MAX;
	tipo vec[4*MAXN];
	tipo* init(int n) {
		MAX = 1 << (32-__builtin_clz(n)); 
		fill(vec, vec+2*MAX, 0); // 0 = elemento neutro
		return vec+MAX;
	}
	void updall() { dforn(i, MAX) vec[i] = max(vec[2*i] , vec[2*i+1]); } // max = operacion
	void pset(int i, tipo vl) {
		vec[i+=MAX] = vl;
		while(i) { i /= 2; vec[i] = max(vec[2*i] , vec[2*i+1]); } // max = operacion
	}
	tipo pget(int i, int j) { return _pget(i+MAX, j+MAX); }
	tipo _pget(int i, int j) {
		tipo res = 0;             // 0 = elemento neutro
		if (j-i <= 0) return res;
		if (i%2) res = max(res,vec[i++]); // max = operación
		res = max(res,_pget(i/2, j/2));   // max = operación
		if (j%2) res = max(res,vec[--j]); // max = operación
		return res;
	}
};

rmq miRmq;

void printVec(vi &vec){
	for(auto &e : vec) cout << e << " ";
	cout << endl;
}

int main(){
	int Z; cin >> Z;
	while(Z--){
		int N; cin >> N;
		vi nums(N);
		forn(i,N) cin >> nums[i];
		
		vi incIzq(N, 1);
		vi incDer(N, 1);
		forn(i,N)  if(i!=0)   if(nums[i] > nums[i-1]) incIzq[i] = incIzq[i-1] + 1;
		dforn(i,N) if(i!=N-1) if(nums[i] < nums[i+1]) incDer[i] = incDer[i+1] + 1;
		
		//printVec(incIzq);
		//printVec(incDer);
		
		map<tint,tint> compresion;
		forn(i,N) compresion[nums[i]] = 0;
		int idx=0;
		for(auto &m : compresion) m.second = idx++;
		
		//for(auto &m : compresion){
		//	cout << m.first << " -> " << m.second << endl;
		//}
		
		// RMQ
		tipo* vec = miRmq.init(idx);
		tint res = 0;
		forn(i,N){
			// query
			//cout << "query: " << 0 << " - " << compresion[nums[i]] << endl;
			tint query = miRmq.pget(0, compresion[nums[i]]);
			//cout << query << endl;
			res = max(res, query + incDer[i] );
			//cout << query + incDer[i] << endl;
			
			// upd
			tint viejoInc = vec[compresion[nums[i]]];
			tint nuevoInc = incIzq[i];
			tint upd = max(viejoInc, nuevoInc);
			miRmq.pset(compresion[nums[i]], upd);
			//cout << "upd: " << compresion[nums[i]] << " " << upd << endl;
		}
		cout << res << endl;
	}
	return 0;
}
