#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)

typedef long long tint;

const int MAXN = 100050;
struct trie {
	map<char, int> sig;
	int cant[2];
	char c;
};

int nods;
trie t[MAXN];

void resetNode(int i){
	t[i].cant[0] = 0;
	t[i].cant[1] = 0;
	t[i].sig.clear();
}

void initT(){
	forn(i,nods){
		resetNode(i);
	}
	nods = 1;
}

void insertar(string st, int equipo){
	int pos=0;
	for(int i=0; i<(int)st.size(); i++){
		if(t[pos].sig.find(st[i]) == t[pos].sig.end()){
			t[pos].sig[st[i]] = nods;
			resetNode(nods);
			t[nods].c = st[i];
			nods++;
		}
		t[pos].cant[equipo]++;
		pos = t[pos].sig[st[i]];
	}
	t[pos].cant[equipo]++;
}

int main(){
	nods = 1;
	int N;
	while(cin >> N && N != -1){
		initT();
		
		forn(i,N){
			string s; cin >> s;
			insertar(s, 0);
		}
		forn(i,N){
			string s; cin >> s;
			insertar(s, 1);
		}
		
		//
		tint res = 0;
		forn(i,nods){
			if(i) {
				tint mini = min(t[i].cant[0], t[i].cant[1]);
				//if(mini){
					//cout << t[i].c << " " << t[i].cant[0] << " " << t[i].cant[1] << endl;
				//}
				res += mini;
			}
		}
		cout << res << endl;
		//cout << "--------\n";
	}
	return 0;
}
