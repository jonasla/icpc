#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

const tint mod = (1 << 21)*11 + 1 ; // es re primo
const tint root_pw = 1 << 21 ; // largo del arreglo
const tint root = 38;
const tint root_1 = 21247462;

/*
 * const tint mod = 7340033 ;
 * const tint root = 5 ;
 * const tint root_1 = 4404020 ;
 * const tint root_pw = 1 << 20 ;
 */

tint potLogMod (tint x, tint y) // Calcula: (x^y) mod nmod
{
	tint ans = 1;
	while (y > 0)
	{
		if (y % 2)
			ans = (x * ans) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return ans;
}

tint invMod(tint a) // Solo funciona si mod es primo y devuelve un numero b tal que: (a*b) = 1 mod nmod 
{
	return potLogMod(a,mod-2);
}



tint modulo (tint n)
{
	return ((n % mod) + mod) % mod;
}
 
void fft (vector <tint> &a, bool invert )
{
	tint n = a. size();
	for (tint i = 1 , j = 0 ; i < n ; ++ i )
	{
		tint bit = n >> 1 ;
		while(j >= bit)
		{
			j -= bit ;
			bit >>= 1;
		}
		j += bit ;
		if ( i < j )
			swap (a[i],a[j]);
	}
 
	for (tint len = 2 ; len <= n ; len <<= 1) 
	{
		tint wlen = root;
		if (invert)
			wlen = root_1;
		for (tint i = len ; i < root_pw ; i <<= 1)
			wlen = modulo(wlen * wlen);
		for (tint i = 0 ; i < n ; i += len ) 
		{
			tint w = 1 ;
			forn(j,len/2)
			{
				tint u = a[i+j], v = modulo(a[i+j+len/2] * w) ;
				a[i+j] = modulo(u+v);
				a[i+j + len/2] = modulo(u - v);
				w = modulo(w * wlen) ;
			}
		}
	}
	if (invert) {
		tint nrev = invMod(n);
		forn(i,n)
			a[i] = modulo(a[i] * nrev) ;
	}
}

void multiply (const vector<tint> &a, const vector<tint> &b, vector <tint> &res ) 
{
	vector<tint> fa(a.begin(), a.end() ), fb(b.begin(), b.end() );
	tint n = 1 ;
	while (n < max(tint(a.size()), tint(b.size())))
		n <<= 1;
	n <<= 1 ;
	fa.resize(n), fb.resize(n);
	fft (fa, false) , fft(fb, false);
	forn(i,n)
		fa[i] *= fb[i];
	fft(fa, true);
	res = fa;
} 

int main()
{
	vector<tint> a = {1,0,0,1};
	vector<tint> b = {1,0,0,1};
	vector<tint> res;
	multiply(a,b,res);
	for (auto x : res)
		cout << x << " " ;
	cout << endl;
	return 0;
}
