#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long tint;
typedef long double ldouble;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)

class UF {
	private:
		vi p, rank;
	public:
		UF(tint N) { 
			rank.assign(N, 0); 
			p.assign(N,0); 
			forn(i,N) p[i] = i;
		}
		
		tint findSet(tint i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		bool sameSet(tint i, tint j) { return findSet(i) == findSet(j); }
		void unionSet(tint i, tint j) {
			if (!sameSet(i,j)) {
				tint x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) {
					p[y] = x;
				} else {
					p[x] = y;
					if (rank[x] == rank[y]) rank[y]++;
				}
			}
		}
};

struct ars {
	tint a, b, w;
	ars(tint aa, tint bb, tint ww) {
		a = aa; b = bb; w = ww;
	}
};

bool operator<(const ars& a1, const ars& a2) {
	return make_pair(a1.w, make_pair(a1.a, a1.b)) > make_pair(a2.w, make_pair(a2.a, a2.b));
}

int main() {
	ios:: sync_with_stdio(false);
	cin.tie(NULL);

	tint S, L; 
	while(cin >> S >> L) {
		UF uf(S);
		vector<ars> aristas;
		
		forn(i,L) {
			tint a, b, w; 
			cin >> a >> b >> w; 
			a--; b--;
			aristas.push_back(ars(a,b,w));
		}
		sort(aristas.begin(), aristas.end());
		
		set<ars> enAGM;
		for(auto &ar : aristas) {
			//~ cout << "ar " << ar.w << " " << ar.a << " " << ar.b << endl;
			if (!uf.sameSet(ar.a, ar.b)){
				//~ cout << "uniendo " << ar.w << " " << ar.a << " " << ar.b << endl;
				uf.unionSet(ar.a, ar.b); 
				enAGM.insert(ar);
			}
		}
		//
		tint TOTAL=0, MAXC=0;
		for(auto &ar : aristas) {
			if (enAGM.find(ar) == enAGM.end()) {
				TOTAL += ar.w;
				MAXC = max(MAXC, ar.w);
			}
		}
		cout << TOTAL << " " << MAXC << "\n";
	}
	return 0;
}
