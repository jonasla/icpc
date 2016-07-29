#include <iostream>
#include <vector>
#include <queue>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forsn(i,s,n) for(int (i)=(s);i<(int)n;i++)

using namespace std;

typedef long long int tint;

const tint maxN = 2000000;
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
		bool ganaMolek = false;
		tint ans = -1;
		if (n == 1)
			cout << "Vasha" << endl << 0 << endl;
		else
		{
			if (n < maxN)
			{
				if (!p[n])
					cout << "Vasha" << endl << 0 << endl;
				else // tiene 2 divisores
				{
					for(auto x : primos)
					{
						if (x < n && n % x == 0 && !p[n/x] ) // gana Molek
						{
							cout << "Molek" << endl;
							ganaMolek = true;
							break;
						}
						else if (x*x < n && n % (x*x) == 0)
							ans = x*x;
					}
					if (!ganaMolek)
						cout << "Vasha" << endl << n << "->" <<  ans << endl;
				}
			}
			else
			{
				tint cantidadPrimosDividen = 0;
				for (auto x : primos)
				{
					while (n%x == 0)
					{
						n /= x;
						cantidadPrimosDividen++;
					}
				}
			}
		}
	}
	
}
