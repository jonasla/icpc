#include <iostream>
#include <vector>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)n;i++)

int main(){
	bool notpos;
	int n,p,c;while(cin>>n && n!=0){
		notpos = false;
		vector<int> pos(n,0);
		forn(i,n){
			cin >> c >> p;
			if(0<=i+p && i+p<n && pos[i+p]==0)
				pos[i+p]=c;
			else notpos = true;
		}
		if(notpos)
			cout << "-1";
		else{
			forn(i,n-1)cout << pos[i] << " ";
			cout << pos[n-1];
		}
		cout << endl;
	}
	return 0;
}
