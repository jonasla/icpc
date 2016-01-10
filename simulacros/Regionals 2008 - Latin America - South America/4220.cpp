#include <iostream>
#include <vector>
#include <algorithm>


#define forn(i,n) for(int (i) = 0; (i) < (int)(n); i++ )
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)


typedef long long tint;
using namespace std;

tint primerBolsa(tint comienzo, tint lado, vector<tint> &arco)
{
	tint n = arco.size();
	tint ultimo = comienzo;
	tint bolsa = 0;
	while(bolsa < lado)
	{
		bolsa += arco[ultimo];
		ultimo = (ultimo + 1) % n;
	}
	if (bolsa == lado)
		return ((ultimo - 1) + n) % n;
	else
		return ((ultimo - 2) + n) % n;
}

bool sePuede (tint comienzo, tint lado, vector<tint> &arco)
{
	tint n = arco.size();
	tint usados = 0;
	tint bolsa = 0;
	tint i = comienzo;
	while(usados < n && bolsa <= lado)
	{
		if (bolsa == lado)
			bolsa = 0;
		bolsa += arco[i];
		i = (i+1) % n;
		usados++;
	}
	return (usados == n);
}

int main()
{
	tint n;
	while(cin >> n && n != 0)
	{
		tint suma = 0;
		vector<tint> arco (n);
		forn(i,n)
		{
			cin >> arco[i];
			suma += arco[i];
		}
		bool gane = false;
		tint qarcos = n+1;
		while (qarcos--){
			if(qarcos < 3 || (suma % qarcos) != 0) {
				continue;
			}
			tint lado = suma/qarcos, comienzo = 0;
			tint bolsaInicial = primerBolsa(comienzo,lado,arco);
			while ((bolsaInicial < comienzo) or (comienzo == 0 && comienzo <= bolsaInicial))
			{
				if (sePuede(comienzo,lado,arco))
				{
					gane = true;
					break;
				}
				else
					comienzo = (((comienzo - 1) % n) + n ) % n;
				bolsaInicial = primerBolsa(comienzo,lado,arco);
			}
			
			if (gane)
			{
				cout << n-qarcos << endl;
				break;
			}
		}
		if (!gane)
			cout << -1 << endl;
	}
	return 0;
}
