#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stdio.h>

typedef long long tint;
#define forn(i,n) for(tint i=0;i<(int)n;i++)
#define forsn(i,s,n) for(tint i=s;i<(int)n;i++)


using namespace std;

tint comparar (vector<string> imagen1, vector<string> imagen2)
{
	tint ans = 0;
	forn(i,10)
	forn(j,10)
		if (imagen1[i][j] != imagen2[i][j])
			ans++;
	return ans;
} 

void rotar (vector<string> &origi) // Rota una matriz de (n X n) 90° en sentido horario.
{
	tint n = origi.size();
	string aux (n,'x');
	vector<string> rotado (n,aux);
	tint comienzo = 0, fin = n-1;
	while (comienzo <= fin)
	{
		forsn(i,comienzo,fin+1)
		{
			rotado[i][fin] = origi[comienzo][i];
			rotado[fin][fin - i + comienzo] = origi[i][fin];
			rotado[fin - i + comienzo][comienzo] = origi[fin][fin-i + comienzo];
			rotado[comienzo][i] = origi[fin-i+comienzo][comienzo];
		}
		comienzo++;
		fin--;
	}
	origi = rotado;
}

void rotarFacil (vector<string> &origi) // Rota una matriz de (n X n) 90° en sentido horario.
{
	tint n = origi.size();
	string aux (n,'x');
	vector<string> rotado (n,aux);
	forn(i,n)
	forn(j,n)
		rotado[j][n-i-1] = origi[i][j];
	origi = rotado;
}


int main()
{
	#ifdef ACMTUYO
	if (!freopen("64.in","r",stdin))
		return 1;
	#endif
	tint n,m;
	while(cin >> m)
	{
		map<char, vector<string> >libreria;
		map<char,tint> input;
		forn(l,m)
		{
			char letra;
			cin >> letra;
			input[letra] = l;
			vector<string> imagen(10);
			forn(i,10)
				cin >> imagen[i];
			libreria[letra] = imagen;
		}
		cin >> n;
		
		forn(l,n)
		{
			tint inpu = 101;
			char ans = 'x';
			tint misses = 200;
			vector<string> imagen (10);
			forn(i,10)
				cin >> imagen[i];
			
			for (auto x : libreria)
			{
				
				forn(i,4)
				{
					tint r = comparar(imagen,x.second);
					if (r < misses or (r == misses && input[x.first] < inpu))
					{
						inpu = input[x.first];
						misses = r;
						ans = x.first;
					}	
					if (i < 3)
						rotarFacil(imagen);
				}
			}
			cout << ans;
			
		}
		cout << endl;
	}
	return 0;
}
	
