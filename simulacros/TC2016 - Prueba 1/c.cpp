#include <iostream>
#include <vector>
#include <queue>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forsn(i,s,n) for(int (i)=(s);i<(int)n;i++)

using namespace std;

typedef long long int tint;

const tint maxN = 4000000;
tint p[maxN];
vector<tint> primos = {2};

void criba()
{
	for (tint i = 4; i < maxN; i += 2)
		p[i] = 2;
	for (tint i = 3; i*i < maxN; i+= 2)
		if (!p[i])
			for(tint j = i*i; j < maxN; j += 2*i)
				p[j] = i;
	forsn(i,3,maxN)
		if(!p[i])
			primos.push_back(i);
		
		
	
}

int main()
{
	criba();
	tint t;
	cin >> t;
	forn(caso,t)
	{
		tint n;
		cin >> n;
		if (n == 1)
			cout << "Vasha" << endl << 0 << endl;
		else
		{
			tint cantidadPrimosDividen = 0, ans = 1, ansPosta = 1;
			tint c = 0;
			for (auto x : primos)
			{	
				while (n%x == 0)
				{
					n/=x;
					cantidadPrimosDividen++;
					if (c < 2)
					{
						ans *= x;
						c++;
					}
				}
				if (ans > 1 && c == 2)
					ansPosta = ans;
				if (n < x)
					break;
			}
			if (n > maxN)
				cantidadPrimosDividen++;
			//cout << "-------\n-----" << endl;
			//cout << "CANTIDAD PRIMOS DIVIDEN = " << cantidadPrimosDividen << endl;
			if (cantidadPrimosDividen == 2)
				cout << "Molek" << endl;
			else if (cantidadPrimosDividen == 1)
				cout << "Vasha" << endl << 0 << endl;
			else
				cout << "Vasha" << endl << ansPosta << endl;
		}
	}
	return 0;
}
