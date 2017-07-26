#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef long long tint;


#define forsn(i,s,n) for(int i=(tint)s; i<(tint)n; i++) 
#define forn(i,n) forsn(i,0,n) 

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint t;
	cin >> t;
	forn(caso,t)
	{
		tint n, cantidadDeUnos = 0, xorcito = 0;
		cin  >> n;
		forn(i,n)
		{
			tint a;
			cin >> a;
			xorcito ^= a;
			cantidadDeUnos += (a == 1);
		}
		if (cantidadDeUnos == n)
		{
			if (cantidadDeUnos % 2)
				cout << "Brother\n";
			else
				cout << "John\n";
		}
		else
		{
			if (xorcito == 0)
				cout << "Brother\n";
			else
				cout << "John\n";
		}
		
		
	}
	return 0;
}
