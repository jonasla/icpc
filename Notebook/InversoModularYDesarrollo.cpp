#include <iostream>
#include <vector>
#include <algorithm>


#define forn(i,n) for(tint i=0;i<(tint)(n);i++)

typedef long long tint;
tint nmod = 1000000007; // o el primo que deseamos

using namespace std;

vector<tint> desarrollo (tint n) // En des queda guardado el desarrollo dado vuelta, ya que necesitamos iterar desde las unidades en invMod
{
	vector<tint> des;
	while (n > 0)
	{
		des.push_back(n%2);
		n /= 2;
	}
	return des;
}

tint invMod (tint a) // Devuelve el inverso de a modulo nmod
{
	tint ans = 1;
	vector<tint> des = desarrollo(nmod-2);
	tint acc = a;
	forn(k,des.size())
	{
		if (des[k] != 0)
			ans = (((ans * acc) % nmod) * des[k]) % nmod;
		acc = (acc*acc) % nmod;
	}
	return ans % nmod;
}

int main()
{
	return 0;
}
