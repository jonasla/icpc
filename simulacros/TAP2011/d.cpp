#include <iostream>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)

int c[100000+1];

int main()
{
	long long int n,m,s=0,t;
	cin >> n >> m;

	while(n!=-1 && m!=-1){
		s=0;
		cin >> c[0];
		for(int i=1;i<n;i++){
			cin >> t;
			c[i] = t+c[i-1];
		}
		for(int i=0;i<n;i++)
			s+=c[i];
		s*=m;
		cout << s << endl;
		cin >> n >> m;
	}
	return 0;
}
