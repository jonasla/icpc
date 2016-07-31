#include <iostream>

typedef long long tint;

#define forn(i,n) for(int i  = 0; i < int(n); i++)
#define forsn(i,j,n) for(int i  = j; i < int(n); i++)
using namespace std;

const int maxN = 1000000;

int p[maxN];

void criba(){
	for(int i=4; i<maxN; i+=2) p[i] = 2;
	for(int i=3; i*i<maxN; i+=2) 
		if(!p[i]) for(int j=i*i; j<maxN; j+=2*i) p[j] = i;
}

int main(){
	criba();
	int n;
	scanf("%d",&n);
	while(n!=0){
		forsn(i,3,1000000){
			if(!p[i] && !p[n-i]){
				printf("%d = %d + %d\n",n,i,(n-i));
				break;
			}
		}
		scanf("%d",&n);
	}
	return 0;
}
