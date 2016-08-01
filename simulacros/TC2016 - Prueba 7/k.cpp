#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define forn(i,n) for(int i=0;i<n;i++)
typedef long long tint;

using namespace std;

int main(){
    	
	tint n; cin >> n;
	tint counter = 0;
	
	while(n>0){
		tint tmp = n;
		counter++;
		vector<int> m;
		do{m.pb(tmp%10) ;
		}while((tmp/=10)>0);
		
		sort(m.begin(),m.end());
		
		
		
		tint k = 0;
		
		forn(i,m.size())k+=pow(10,i)*m[m.size()-i-1];
		//cout << "K: "<<k<<endl;
		n-=k;
    }
    cout << counter << endl;
	return 0;
}
