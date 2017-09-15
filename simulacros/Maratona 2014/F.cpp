#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (tint)(s); i < (tint)(n); i++)


int main()
{
	tint n;
	while(cin >> n)
	{
		vector<tint> x (n+1);
		tint suma = 0;
		forn(i,n)
		{
			cin >> x[i+1];
			suma += x[i+1];
			if (i >= 1)
				x[i+1] += x[i];
			 
		}
		
		if (suma % 3 == 0)
		{
			tint lado = suma/3, ans = 0;
			tint i1 = 0,i2 = 1,i3 = 2;
			while (x[i1] - x[0] < lado)
			{
				
				while (x[i2] - x[i1] < lado)
					i2++;
				while (x[i3] - x[i1] < 2*lado)
					i3++;
				ans += (x[i2] - x[i1] == lado && x[i3] - x[i1] == 2*lado);
				i1++;
			}
			cout << ans << endl;
		}
		else
			cout << "0\n";
		
	}
	
	return 0;
}

