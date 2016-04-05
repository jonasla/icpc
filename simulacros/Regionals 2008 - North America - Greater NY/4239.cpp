#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(int)(n); (i)++)

typedef long long tint;
int r;

bool notGood(tint p){
	int c = 0;
	while(p%10==1 || p%10==2){
		p/=10;
		c++;
	}
	return p!=0 || c!=r;
}

int main(){
	int n;cin>>n;
	
	forn(i,n){
		cin >> r;
		tint m = 1;
		forn(i,r){
			m*=10;
		}
		tint p = 2;
		tint k = 352446259265;
		while(notGood(p)){
			p = (16*p)%m;
			k+=4;
		}
		cout << i+1 <<" "<<r<<" "<< k << endl;
	}
	return 0;
}
