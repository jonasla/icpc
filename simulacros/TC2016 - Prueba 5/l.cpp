#include <iostream>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forsn(i,s,n) for(int i=s;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)(n-1);i>=0;i--)

#define pb push_back
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;cin>>n;
	vector<int> w(n);
	vector<bool> v(n,false);
	dforn(i,n) cin>>w[i];
	
	forn(i,n){
		if(w[i]==i) {v[i] = true;
		}else if(i-w[i]-1 >= 0 && v[i-w[i]-1]){ v[i] = true;}
	}
	
	//reverse(v.begin(), v.end());
	
	dforn(i,v.size()){
		if(v[i]) cout << n-i-1 <<"\n";
	}
	cout << n << "\n";
	return 0;
}
