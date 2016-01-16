#include <iostream>
#include <cmath>
#include <stdio.h>
#define forn(i,n) for(int i=0;i<(int)n;i++)

using namespace std;

int main(){
	
	int n,m;
	bool f,c;
	f = false;
	double t;
	int k;cin >>k;
	forn(h,k){
		cin>>n>>m;
		forn(i,n){
			c=!f;
			f=!f;
			forn(j,m-1){
				cin >> t;
				if(floor(t)==t) cout << t<<" ";
				else{
					if(c) cout << floor(t)<<" ";
					else cout << ceil(t)<<" ";
					c=!c;
				}
			}
			cin >> t;
			if(floor(t)==t) cout << t;
			else{
				if(c) cout << floor(t);
				else cout << ceil(t);
				c=!c;
			}
			if(i!=n-1)
				cout << endl;
		}
		if(h!=k-1)
			cout <<endl;
	}
	return 0;
}
