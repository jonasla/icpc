#include <iostream>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

const tint maxN = 1024;

tint binom[maxN][maxN];

tint comb(tint n, tint m)
{
	if (m < 0 or m > n)
		return 0;
	if (m == 0 or m == n)
		return 1;
	if (n >= maxN)
		return comb(n-1,m-1) + comb(n-1,m);
	if (binom[n][m] == -1)
		binom[n][m] = comb(n-1,m-1) + comb(n-1,m);
	return binom[n][m];
	
}

tint nBolasEnkCajas (tint n, tint k)
{
	return comb(n+k-1,n);
}

int main()
{
	forn(i,maxN)
	forn(j,maxN)
		binom[i][j] = -1;
	cout << comb(5,5) << endl;
	return 0;
}
