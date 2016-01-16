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

void rotar (vector<string> &origi)
{
	string aux = "xxxxxxxxxx";
	vector<string> rotado (10,aux);
	tint comienzo = 0, final = 9;
	while (comienzo < final)
	{
		forsn(i,comienzo,final)
		{
			rotado[i][final] = origi[comienzo][i];
			rotado[final][final - i] = origi[i][final];
			rotado[final-i][comienzo] = origi[final][final - i];
			rotado[comienzo][i] = origi[final - i][comienzo];
		}
		comienzo--;
		final--;
	}
}


int main()
{
	#ifdef ACMTUYO
		freopen("61.in","r",stdin);
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
					if (r <= misses && input[x.first] < inpu)
					{
						inpu = input[x.first];
						misses = r;
						ans = x.first;
					}
					if (i < 3)
						rotar(imagen);
				}
				cout << ans;
			}
		}
		cout << endl;
	}
	return 0;
}
	
