#include <iostream>
#include <vector>

#define forn(i,n) for(int (i) = 0; i < n; i++)
#define forsn(i,s,n) for(int (i) = s; i < n; i++)

typedef long long tint;

using namespace std;

const int maxN = 1000500;
const tint nmod = 10000000000;

int p[maxN];

void criba()
{
	for (int i = 4; i < maxN; i+= 2) p[i]=2;
	for (int i = 3; i*i < maxN; i+=2)
		if (!p[i])
			for (int j = i*i; j < maxN; j+= 2*i)
				p[j] = i;
}

int main()
{
	criba();
	tint producto = 1;
	tint b = -1;
	bool flag=false;
	vector<tint> ans (maxN);
	forsn(i,2,maxN)
	{
		if (!p[i] && producto * i >= nmod){
			producto = (producto * i) % nmod;
			if(!flag){b=i;flag=true;}
		}
		else if (!p[i])
			producto = (producto * i);
		ans[i] = producto;
	}
	tint t;
	//cin >> t;
	
	scanf("%Ld", &t);
	forn(i,t)
	{
		tint a;
		//cin >> a;
		scanf("%Ld", &a);
		//cout << ans[a] << "\n";
		if(b>a)
			printf("%Ld\n", ans[a]);
		else
			printf("%010Ld\n", ans[a]);
	}
	return 0;
}
