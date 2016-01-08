#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n);i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int) (n);i++)

typedef pair<int, char> pic;
typedef vector<pic> vpic;

int main(){
	int nivel,n,a,b;
	cin >> n;
	while(n!=-1){
		vpic v(n);
		nivel = 0;
		cin >> a;
		forn(i,n){
			cin >> b;
			if(a>b){
				nivel--;
				pic par = make_pair(nivel, '\\');
				v[i] = par;
				
			}
			else if(a<b){
				pic par = make_pair(nivel, '/');
				v[i] = par;
				nivel++;
			}
			else{
				pic par = make_pair(nivel, '_');
				v[i] = par;
			}
			a = b;
		}
		int maxi = v[0].first;
		int mini = v[0].first;
		forsn(i,1,n){
			maxi = (maxi<v[i].first)?v[i].first:maxi;
			mini = (mini>v[i].first)?v[i].first:mini;
		}
		int k = maxi; 
		while(k>=mini){
			forn(i,n)
				if(k==v[i].first)
					cout << v[i].second;
				else
					cout << ' ';
			cout << endl;
			k--;
		}
		cout << "***"<<endl;
		cin >> n;
	}
	return 0;
}
