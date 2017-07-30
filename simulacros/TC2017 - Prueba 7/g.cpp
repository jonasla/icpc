#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

typedef int tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

struct trie {
	map<char, tint> sig;
	bool tocado = false;
}; 

trie t[25000];

tint n = 1;

void insertar(string st) {
	tint pos = 0;
	forn(i,st.size()) {
		if (t[pos].sig.find(st[i]) == t[pos].sig.end()) {
			t[pos].sig[st[i]] = n;
			t[n].sig.clear();
			n++;
		}
		pos = t[pos].sig[st[i]];
	}
}

tint buscar(string st) {
	tint p=0, l=0;
	forn(i,st.size()) {
		if(t[p].sig.find(st[i]) == t[p].sig.end()) {
			return l;
		} else {
			l++;
			p = t[p].sig[st[i]];
			t[p].tocado = true;
		}
	}
	return l; // nunca deberia pasar esto
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	tint N, M; cin >> N >> M;

	set<string> S;

	string str;
	
	vector<string> adentro(N);
	
	forn(i,N) {
		cin >> adentro[i];
		//~ insertar(str);
		//~ insertar(str);
	}

	forn(i,M) {
		cin >> str;
		insertar(str);
	}

	//~ tint ans = 0;
	forn(i,N) {
		//~ cin >> str;
		tint pref = buscar(adentro[i]);
		//~ cout << "buscando: " << str  << endl;
		//~ cout << pref << endl;
		//~ if (pref > 0) ans += (pref+1);
		S.insert(adentro[i].substr(0,pref+1));
	}

	//~ for(auto tr : t[0].sig) {
		//~ cout << tr.first << endl;
		//~ if (!t[tr.second].tocado){ 
			//~ ans++;
			//~ cout << "sumo\n";
		//~ }
	//~ }

	

	tint ans = 0;
	for(auto st : S) ans += st.size();
	cout << ans << "\n";
	
	return 0;
}
