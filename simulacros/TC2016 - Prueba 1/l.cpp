#include <iostream>
#include <vector>
#include <queue>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forsn(i,s,n) for(int (i)=(s);i<(int)n;i++)

using namespace std;

typedef long long int tint;

tint potLog(tint b,tint e, tint m){
	if(!e)return 1LL;
	tint r=potLog(b,e>>1,m);
	r=(r*r)%m;
	return (e&1)?(r*b)%m:r;
}

int main(){
	string n; tint c,m;
	while(cin >> n >>c >> m){
		tint l = n.size();
		vector<tint> potes(l,0);
		potes[0]=c%m;
		for(int i=1;i<l;i++)
			potes[i]=potLog(potes[i-1],10,m);
		forn(i,l)
			potes[i]=potLog(potes[i],n[l-i-1]-'0',m);
		tint resu = 1;
		forn(i,l)
			resu = (resu*potes[i])%m;
		cout << resu << endl;
	}
}
