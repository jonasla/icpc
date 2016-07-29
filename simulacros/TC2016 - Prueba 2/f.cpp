#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define dforn(i,n) for(int i=(int)(n-1); i>=0; i--)
#define forsn(i,s,n) for(int i=(int)s; i<(int)n; i++)

typedef unsigned long long utint;

const int MAXN = 100000;
struct {
	typedef int tipo;
	int MAX;
	tipo vec[4*MAXN];
	tipo* init(int n) {
		MAX = 1 << (32-__builtin_clz(n)); 
		fill(vec, vec+2*MAX, 0); // 0 = elemento neutro
		return vec+MAX;
	}
	void updall() { dforn(i, MAX) vec[i] = vec[2*i] + vec[2*i+1]; } // + = operacion
	void pset(int i, tipo vl) {
		vec[i+=MAX] = vl;
		while(i) { i /= 2; vec[i] = vec[2*i] + vec[2*i+1]; } // + = operacion
	}
	tipo pget(int i, int j) { return _pget(i+MAX, j+MAX); }
	tipo _pget(int i, int j) {
		tipo res = 0;             // 0 = elemento neutro
		if (j-i <= 0) return res;
		if (i%2) res += vec[i++]; // + = operación
		res += _pget(i/2, j/2);   // + = operación
		if (j%2) res += vec[--j]; // + = operación
		return res;
	}
} rmq;

utint fibs[100];
const utint maxX = 5000000000000000000;
set<utint> sons;

int cantFib;

void fillFib(){
	fibs[0] = 1;
	fibs[1] = 2;
	forsn(i,2,100) { 
		fibs[i] = fibs[i-1] + fibs[i-2]; if(fibs[i] > maxX) { 
			cantFib=i;
			break; 
		} 
	}
	
	forn(i,cantFib){
		forn(j,i){
			sons.insert(fibs[i]+fibs[j]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	fillFib();
	int N, Q; cin >> N >> Q;
	
	// ST
	int * arreglo = rmq.init(N);
	forn(i,N) { 
		utint x; cin >> x;
		arreglo[i] = (sons.find(x)!=sons.end());
	}
	rmq.updall();
	
	// queries
	forn(i,Q){
		int t; cin >> t;
		if(t==1){
			int x, y; cin >> x >> y;
			int a = min(x,y);
			int b = max(x,y);
			cout << rmq.pget(a-1, b) << "\n";
		}else if(t==2){
			int j; utint x; cin >> j >> x;
			rmq.pset(j-1, (sons.find(x)!=sons.end()));
		}
	}

	return 0;
}
