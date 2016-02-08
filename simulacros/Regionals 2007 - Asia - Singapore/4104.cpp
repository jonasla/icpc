#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for(tint i=0;i<(tint)(n);i++)

vector<tint> desarrollo (tint n)
{
	vector<tint> des;
	while (n > 0) 
	{
		des.push_back(n % 2);
		n /= 2;
	}
	return des;
}

tint expMod (tint x, tint y, tint nmod)
{
	tint ans = 1;
	vector<tint> des = desarrollo(y);
	tint acc = x;
	forn(k,des.size())
	{
		if (des[k] != 0)
			ans = (((ans * acc) % nmod) * des[k]) % nmod;
		acc = (acc * acc) % nmod;
	}
	return ans % nmod; 
	
}

int main()
{	
	tint c,x,y,nmod;
	cin >> c;
	forn(i,c)
	{
		cin >> x >> y >> nmod;
		cout << expMod(x,y,nmod) << endl;
	}
	cin >> c;
	return 0;
}
