#include <iostream>
#include <vector>
#include <algorithm>

typedef long long tint;
const tint nmod = 1000000007; // o el primo que deseamos

using namespace std;

vector<tint> desBaseB (tint n, tint b) // Calcula el desarrollo de n en base b
{
	if (n == 0)
		return {0};
	vector<tint> des;
	while (n > 0)
	{
		des.push_back(n%b);
		n /= b;
	}
	reverse(des.begin(),des.end());
	return des;
}

tint potLogMod (tint x, tint y) // Calcula: (x^y) mod nmod
{
	tint ans = 1;
	while (y > 0)
	{
		if (y % 2)
			ans = (x * ans) % nmod;
		x = (x * x) % nmod;
		y /= 2;
	}
	return ans;
}

tint invMod(tint a) // Solo funciona si nmod es primo y devuelve un numero b tal que: (a*b) = 1 mod nmod 
{
	return potLogMod(a,nmod-2);
}

int main()
{
	return 0;
}
