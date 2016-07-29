#include <iostream>
#include <vector>

#define forn(i,n) for(int i=0;i<(int)n;i++)

using namespace std;

typedef long long int tint;

int main(){
	int T; cin >> T;
	while(T--){
		int E, F, C;
		cin >> E >> F >> C;
		if(E+F >=1 && C<=1){
			cout << 0 << "\n";
		}else{
			int Q =0;
			int curr = E+F;
			while(curr >= C){
				int nuevas = curr / C;
				Q += nuevas;
				curr = nuevas + (curr%C);
			}
			cout << Q << "\n";
		}
	}
	return 0;
}
