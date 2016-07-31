#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define forn(i,n) for(int (i) = 0; i < n; i++)
#define forsn(i,s,n) for(int (i) = s; i < (int)n; i++)
#define pb push_back

using namespace std;

typedef unsigned long long utint;
typedef vector<utint> vi;
typedef set<utint> si;
utint x, y;
si res;


// inv: si lo llame es que no me pase (curr)
void bt(utint curr, vi &pr, utint indice){
	//cout << res.size() << endl;
	
	if(curr >= x){
		res.insert(curr);
	}
	forsn(i,indice,pr.size()){
		utint p = pr[i];
		if(curr*p <= y ) bt(curr*p,pr,i);
	}
}

int main(){
	ios::sync_with_stdio(false);
	int N; 
	while(cin >> N && N!=0){
		vi pr(N);
		forn(i,N) cin >> pr[i];
		
		cin >> x >> y;
		res.clear();
		utint curr = 1;
		bt(curr, pr,0);
		
		int k=0;
		for(auto r: res){
			if(k) cout << ",";
			cout << r;
			k++;
		}
		if(res.empty()){
			cout << "none";
		}cout << endl;
	}
	return 0;
}
