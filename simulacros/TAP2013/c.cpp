#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <functional>
#include <string>
#include <tuple>

#include <iostream>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl

typedef long long tint;
typedef unsigned long long utint;

using namespace std;

void imprimirVector (vector<utint> &v){
	if (!v.empty()){
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}else
		cout << "[]" << endl;
}

typedef vector<utint> vutint;

int main(){
	
	int N, S;
	cin >> N >> S;
	
	vector<vutint> graf(N);
	
	forn(i,S){
		utint a, b;
		cin >> a >> b;
		graf[a-1].push_back(b-1);
	}
	
	//
	vutint level(N, 0);
	level[N-1] = 1;
	
	for(int i=N-2; i>=0; i--){
		for(auto ad : graf[i]){
			level[i] += level[ad];
		}
	}
	
	//imprimirVector(level);		// OK !
	
	vutint maxLevel(N, 0);
	
	for(int i=N-1; i>=0; i--){
		maxLevel[i] = level[i];
		utint maxp = 0;
		for(auto ad : graf[i]){
			maxp = max(maxp, maxLevel[ad]);
		}
		maxLevel[i] += maxp;
	}
	
	//imprimirVector(maxLevel);		// OK !
	
	cout << maxLevel[0] << endl;
	
	return 0;
}
