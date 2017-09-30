#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e7;
int kmp_table[MAXN];
string s, t;
// Deja en kmp_table[i] el borde de longitud i de s
// en kmp_table[s.size()] el maximo borde
void fill_table() {
	int pos = 2, cnd = 0;
	kmp_table[0] = -1;
	kmp_table[1] = 0;
	while(pos <= int(s.size())) {
		if (s[pos-1] == s[cnd]) 
			kmp_table[pos++] = ++cnd;
		else if (cnd>0) 
			cnd = kmp_table[cnd];
		else kmp_table[pos++] = 0;
	}
}
// Matchear s (chico) en t (grande)
// Devuelve todos los indices donde matchea
vector<int> kmp2() {
	vector<int> r;
	int m = 0, i = 0;
	while(m+i < int(t.size())) {
		if (s[i] == t[m+i]) {
			if (i == int(s.size()-1)) r.push_back(m);
			i++;
		} else {
			m = m + i - kmp_table[i];
			if (kmp_table[i] > -1) i = kmp_table[i];
			else i = 0;
		}
	}
	return r;
}

int main() {
	s = "abracadabra";
	fill_table();
	for(int i=0; i<int(s.size()+1); i++) cout << kmp_table[i] << " ";
	cout << endl; // -1 0 0 0 1 0 1 0 1 2 3 4 
	s = "abra";
	fill_table();
	t = "abracadabracadabra";
	for(auto e : kmp2()) cout << e << " ";
	cout << endl; // 0 7 14
	return 0;
}
