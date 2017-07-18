#include <iostream>
#include <vector>

#define forn(i,n) for (int i = 0; i < (int) (n); i++)

typedef long long tint;

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	while (cin >> n && n != -1)
	{
		
		vector<tint> p (n);
		forn(i,n)
			cin >> p[i];
		forn(k,n*500+1) // INTENTOS
		{
			forn(i,n) // PARA CADA CAJA
			{
				if (p[i] == i+1) // Tiene i piedras (indexando de 1)
				{
					p[i] = 0;
					forn(j,i)
						p[j]++;
					break;
				}
			}
		}
		tint suma = 0;
		forn(i,n)
			suma += p[i];
		if (suma == 0)
			cout << "S\n";
		else
			cout << "N\n";
		
	}
	return 0;
}

