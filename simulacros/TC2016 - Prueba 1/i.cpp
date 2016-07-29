#include <iostream>
#include <vector>

#define forn(i,n) for(int i=0;i<(int)n;i++)

using namespace std;

typedef long long int tint;

int main(){
	tint t;cin>>t;
	tint s;
	forn(k,t){
		tint n,m;cin>>n>>m;
		vector<tint> votos(n,0);
		forn(j,m)
			forn(i,n){
				cin>>s;votos[i]+=s;
			}
		int posmax=0;
		forn(i,n)
			if(votos[posmax]<votos[i])posmax=i;
			
		cout << posmax+1<<endl;
	}
	return 0;
}
