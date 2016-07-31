#include <iostream> 

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forsn(i,s,n) for(int i=s;i<(int)n;i++)

using namespace std;


const int maxN = 3050;
int p[maxN];

void criba(){
	for(int i=4;i<maxN;i+=2) p[i]=1;
	for(int i=3;i<maxN;i+=2)
		if(!p[i]) for(int j=2*i;j<maxN;j+=i) p[j]++;
}

int main()
{
	criba();

	int N; 
	cin >> N;
	int res = 0;
	forsn(i,2,N+1){
		if(p[i]==2)  res ++;
	}
	cout << res << endl;
	return 0;
}
