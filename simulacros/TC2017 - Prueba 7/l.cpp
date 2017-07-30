#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

typedef int tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)


const tint semilla = 38532164;

mt19937 gen(semilla);

const tint NMOD = 1000000000+7;

tint mult(tint a, tint b, tint m)
{
	
	int largestBit = 0;
	while( (b >> largestBit) != 0)
		largestBit++;
	
	
	tint ans = 0;
	for(tint currentBit = largestBit - 1; currentBit >= 0; currentBit--)
	{
		ans = (ans + ans);

		if (ans >= m)
			ans -= m;

		if ( (b >> currentBit) & 1)
		{ 
			ans += a;
			if (ans >= m)
				ans -= m; 
		}
	}
	return ans;
}


tint potLogMod (tint x, tint y, tint nmod) // Calcula: (x^y) mod nmod
{
	tint ans = 1;
	while (y > 0)
	{
		if (y % 2)
			ans = mult(x,ans,nmod);
		x = mult(x,x,nmod);
		y /= 2;
	}
	return ans;
}


bool esPrimoRM (tint n)
{
	if (n <= 1)
		return false;
	else if (n <= 3)
		return true;
	else if (n % 2 == 0)
		return false;
	else
	{
		
		uniform_int_distribution<tint> dis(2, n-2);
		tint kOrig = 0, m = n-1;
		while (m % 2 == 0)
		{
			kOrig++;
			m /= 2;
		}
		bool esPrimo = true;
		vector<tint> testigos = {2,3,5,7,11,13,17,19,23,29,31,37, dis(gen), dis(gen), dis(gen), dis(gen), dis(gen)};
		for (auto a : testigos)
		{
			if (a < n)
			{
				tint b = potLogMod(a,m,n), k = kOrig;
				if (b == 1 or b == n-1)
					continue;
				else
				{
					forn(j,k)
					{
						b = mult(b,b,n);
						if (b == n-1)
							break;
						else if (b == 1)
						{
							esPrimo = false;
							break;
						}
					}
					
					if (b != n-1)
					{
						esPrimo = false;
						break;
					}
				}
			}
		}
		return esPrimo;
	}
}

tint gcd (tint a, tint b)
{
	if (a == 0)
		return b;
	return gcd (b % a, a);
}


void factorizar (tint n, map<tint,tint> &f)
{
	while (n > 1)
	{
		if (esPrimoRM(n))
		{
			f[n]++;
			n /= n;
		}
		else
		{
			
			uniform_int_distribution<tint> dis(1, n-1);
			tint a = dis(gen), b = dis(gen), x = 2, y = 2, d;
			
			do
			{
				x = (mult(x,x,n) + mult(a,x,n) + b) % n;
				y = (mult(y,y,n) + mult(a,y,n) + b) % n;
				y = (mult(y,y,n) + mult(a,y,n) + b) % n;
				d = gcd(abs(x-y),n);
			}
			while (d == 1);
			if (d != n)
			{
				factorizar(d,f);
				n /= d;
			}
				
		}
	}
}


tint potLogMod (tint x, tint y) // Calcula: (x^y) mod nmod
{
	tint ans = 1;
	while (y > 0)
	{
		if (y % 2)
			ans = (x * ans) % NMOD;
		x = (x * x) % NMOD;
		y /= 2;
	}
	return ans;
}

tint invMod(tint a) // Solo funciona si nmod es primo y devuelve un numero b tal que: (a*b) = 1 mod nmod 
{
	return potLogMod(a,NMOD-2);
}

int main() {
	cout << invMod(6) << endl;
	
	tint N; cin >> N;
	
	map<tint, tint> facts;
	factorizar(N, facts);

	tint S = 1;
	for(auto kv : facts) {
		cout << kv.first << " " << kv.second << endl;
		S = (S * (kv.second + 1)) % NMOD;
	}

	cout << S << endl;

	tint ans = (S * S) % NMOD;
	ans = (ans * S) % NMOD;
	ans = (ans - 3*((S*S) % NMOD)) % NMOD;
	ans = (ans + 2*S) % NMOD;
	ans = (ans * invMod(6)) % NMOD;
	
	cout << ans << endl;
	
	return 0;
}
