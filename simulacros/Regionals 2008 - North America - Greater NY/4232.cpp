#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(int)(n); (i)++)

int gcd(int a, int b){
	if(a == 0) return b;
	else gcd(b%a, a);
}

int main(){

	int N;
	cin >> N;
	forn(i,N){
		int a, b;
		cin >> a >> b;
				
		int g = gcd(a, b);
		int l = (a*b)/g;
		
		cout << i+1 << " " << l << " " << g << endl;
	}
	
	return 0;
}
