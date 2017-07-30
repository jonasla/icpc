#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

tint MAXN = 1000000000000000000;

unordered_set<tint> S = {1};

void fillS() {
	tint p = 1;
	unordered_set<tint> de2;
	while(p <= MAXN/2) {
		p *= 2;
		de2.insert(p);
	}
	
	p = 1;
	unordered_set<tint> de3;
	while(p <= MAXN/3) {
		p *= 3;
		de3.insert(p);
	}
	
	for(auto n1 : de2) {
		for (auto n2 : de3) {
			S.insert(n1*n2);
		}
	}
	for(auto n : de2) S.insert(n);
	for(auto n : de3) S.insert(n);
}

int main() {
	fillS();

	//~ ios_base::sync_with_stdio(0);
	//~ cin.tie(NULL);
	
	//~ cout << S.size() << endl;
	
	tint T; cin >> T;
	tint aux = 1;
	while(T--) { 
		tint N = aux++; 
		cin >> N;
		
		// de a uno
		if (S.find(N) != S.end()) {
			cout << "1\n" << N << "\n";
		} else {
			bool find = false;
			for (auto n : S) {
				tint falta = N - n;
				if (n % falta != 0 && falta % n != 0) {
					if (S.find(falta) != S.end()) {
						find = true; 
						cout << "2\n" << n << " " << falta << "\n";
						break;
					}
				}
			}
			if (!find) assert(false);
		}
		
	}

	return 0;
}
