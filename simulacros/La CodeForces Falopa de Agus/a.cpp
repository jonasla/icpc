#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forn(i,n) for(tint i = 0; i < (tint) (n); i++)

class UF {
private: vi p, rank;
	int size;
public:
	UF(int N) { rank.assign(N, 0); 
		p.assign(N, 0); forn(i,N) p[i] = i; 
		size = N; }	
	int findSet(int i) { 
		return (p[i]==i) ? i : (p[i] = findSet(p[i])); 
	}
	bool sameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!sameSet(i,j)) {
			size--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
			}else { 
				p[x] = y;
				if (rank[x]== rank[y]) rank[y]++;
			}
		}
	}
	int components() { return size; }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	UF uf(N);
	int e;
	forn(i,N) {
		cin >> e; e--;
		uf.unionSet(i,e);
	}
	
	cout << uf.components() << endl;
	
	return 0;
}
