#include <iostream>
#include <vector>

typedef long long tint;
typedef unsigned long long utint;
using namespace std;

#define forn(i,n) for(int (i) = 0; (i) < (int)(n); i++ )
#define forsn(i,s,n) for(int i=(s);i<(

int main(){
	int N;
	
	while(cin >> N && N != 0){
		utint res = 0;
		for(int i=0; i<N; i++){
			res += (N-i)*(N-i);
		}
		
		cout << res << endl;
	}
}
