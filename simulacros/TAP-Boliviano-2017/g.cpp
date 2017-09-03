#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>

using namespace std;

typedef long tint;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)
#define forsn(i,s,n) for (tint i = tint(s); i < tint (n); i++)

void dfsTopo(int s, vector<vi> &g, vi &visit, vi &ord) {
	visit[s] = true;
	for (auto v : g[s]) {
		if (!visit[v])
			dfsTopo(v, g, visit, ord);
	}
	ord.push_back(s);
}

unordered_map<string, tint> nodos;
unordered_map<tint, string> nodosInv;

struct res {
	tint l, d, s;
	res(tint ll, tint dd, tint ss) {
		l = ll;
		d = dd;
		s = ss;
	}
	void print() {
		cout << l << "." << d << " " << s << "\n";
	}
};

bool operator<(const res &r1, const res &r2) {
	if (r1.l != r2.l) return r1.l < r2.l;
	else if (r1.d != r2.d) return r1.d < r2.d;
	else return nodosInv[r1.s] < nodosInv[r2.s];
}

struct trie {
	map<char, int> sig;
	bool final;
};

void insertar(string &st) {
	int pos = 0;
	for(int i=0; i<(int)st.size(); i++) {
		
	}
}

int sizeTrie = 1;
vector<trie> ELTRIE;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	tint N;
	while (cin >> N) {
		nodos.clear();
		nodosInv.clear();
		int cNodos = 0;
		vector<vi> graf;
		
		
	
		string s, d; 
		forn(i,N) {
			cin >> s >> d;
			if (nodos.find(s)==nodos.end()) { 
				nodos[s] = cNodos;
				nodosInv[cNodos] = s;
				cNodos++;
				graf.push_back(vi());
			} 
			if (nodos.find(d)==nodos.end()) {
				nodos[d] = cNodos;
				nodosInv[cNodos] = d;
				cNodos++;
				graf.push_back(vi());
			}
			graf[nodos[s]].push_back(nodos[d]);
		}
		vi visit(cNodos, false);
		vi ord;
		forn(i,cNodos) 
			if (!visit[i]) 
				dfsTopo(i, graf, visit, ord);
		reverse(ord.begin(), ord.end());
		vi deps(cNodos, 0);
		vi level(cNodos, 0);
		for(auto o : ord) {
			if (deps[o] == 0) level[o] = 1;
			else level[o]++;
			for (auto v : graf[o]) {
				deps[v]++;
				level[v] = max(level[v], level[o]);
			}
		}
		vector<res> ans;
		forn(i,cNodos) {
			ans.push_back(res(level[i],deps[i],i));
		}
		sort(ans.begin(), ans.end());
		for(auto &r : ans) {
			r.print();
		}
	}
	return 0;
}
