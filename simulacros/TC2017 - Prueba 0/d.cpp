#include <iostream>
#include <map>
#include <vector>

#define forn(i,n) for (int i = 0; i < (int) (n); i++)
#define forsn(i,s,n) for (int i = (s); i < (int) (n); i++)

typedef long long tint;

using namespace std;

const tint MAXN = 100000+50;
tint nodos = 1;

struct trie {
	map<char, int> sig;
	int eqs[2];
	
	void init() {
		sig.clear();
		eqs[0] = eqs[1] = 0;
	}
	
	int ambos() { 
		return min(eqs[0], eqs[1]);
	}
	
};

trie t[MAXN];

void clearTrie() { 
	t[0].init();
	nodos = 1;
}

void insertar(string st, int team) {
	int pos = 0;
	for(int i=0; i<(int)st.size(); i++) {
		if (t[pos].sig.find(st[i]) == t[pos].sig.end()) {
			t[pos].sig[st[i]] = nodos;
			t[nodos].init();
			nodos++;
		}
		t[pos].eqs[team]++;
		//~ cout << "letra: "<< st[i] <<" nodo " << pos << ": eq0 " << t[pos].eqs[0] << " eq1 " << t[pos].eqs[1] << endl;
		pos = t[pos].sig[st[i]];
	}
	t[pos].eqs[team]++;
	//~ cout << "letra: "<< st[i] <<" nodo " << pos << ": eq0 " << t[pos].eqs[0] << " eq1 " << t[pos].eqs[1] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	tint n;
	while (cin >> n && n != -1)
	{
		clearTrie();
		forn(i,2) {
			forn(j,n) {
				string st;
				cin >> st;
				insertar(st, i);
			}
		}
		tint ans = 0;
		forsn(i,1,nodos) {
			ans += t[i].ambos();
		}
		cout << ans << endl;
	}
	return 0;
}
