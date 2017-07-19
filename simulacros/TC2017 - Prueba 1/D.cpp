#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint) n; i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint) n; i++)

const tint maxN = 1000500;

tint phi[maxN]; // DAR CHANGUI DE 500 O MAS
			
tint gcd (tint a, tint b)
{
	if (a == 0)
		return b;
	else
		return gcd(b%a,a);
}

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (tint i = 0; i < maxN; i++) 
		phi[i] = i;	
	for (tint i = 1; i < maxN; i++)
		for (tint j = 2 * i; j < maxN; j += i)
			phi[j] -= phi[i];
	tint k;
	while (cin >> k)
	{
		if (k == 1)
			cout << "0/1\n";
		else if (k == 2)
			cout << "1/1\n";
		else
		{
			tint suma = 0, denominador = 2;
			k -= 2;
			forsn(i,2,maxN)
			{
				suma += phi[i];
				if (suma >= k)
				{
					suma -= phi[i];
					denominador = i;
					break;
				}
			}
			tint numerador = 1;
			forsn(i,1,denominador)
			{
				if (gcd(i,denominador) == 1)
					suma++;
				if (suma == k)
				{
					numerador = i;
					break;
				}
			}
			cout << numerador << "/" << denominador << "\n";
		}
		
		
	}
	return 0;
}


