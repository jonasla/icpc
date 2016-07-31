#include <iostream>
#include <algorithm>

typedef long long tint;

#define forn(i,n) for(int i  = 0; i < int(n); i++)
#define forsn(i,j,n) for(int i  = j; i < int(n); i++)
using namespace std;

const int maxN = 100000;
vector<tint> primos;

bool p[maxN];

void criba(){
	for(int i=4; i<maxN; i+=2) p[i] = 1;
	for(int i=3; i*i<maxN; i+=2) 
		if(!p[i]) for(int j=i*i; j<maxN; j+=2*i) p[j] = 1;
	forsn(i,2,maxN)
		if (!p[i])
			primos.push_back(i);
	
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	criba();
	int N; cin >> N;
	while(N--){
		int a, b; cin >> a >> b;
		a = max(a,2);
		for(int i=a; i<=b; i++)
		{
			bool flag = true;
			for (auto x : primos)
			{
				if (x >= i)
					break;
				else if (i % x == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)
				cout << i << "\n";	
		}
		cout << "\n";
	}
	return 0;
}
