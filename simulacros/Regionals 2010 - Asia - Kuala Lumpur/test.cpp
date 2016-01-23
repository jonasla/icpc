#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)

typedef unsigned long long utint;
typedef long long tint;
typedef pair<utint, utint> uu;


tint nmod = 23;

deque<tint> desarrollo(tint n)
{
	deque<tint> des;
	while (n > 0)
	{
		des.push_front(n%2);
		n /= 2;
	}
	return des;
}

tint invMod (tint a)
{
	tint ans = 1;
	deque<tint> des = desarrollo(nmod-2);
	tint acc = a;
	forn(k,des.size())
	{
		
		if (des[k] != 0)
			ans = (((ans * acc) % nmod) * des[k]) % nmod; 
		acc = (acc*acc) % nmod;
	}
	return ans;
	
}

int main()
{
	cout << invMod(4) << endl;
	return 0;
}
