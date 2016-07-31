#include <iostream>

typedef long long tint;

#define forn(i,n) for(int i  = 0; i < int(n); i++)

using namespace std;

bool esPrimo(tint p)
{
	tint i = 2;
	while (i*i <= p)
	{
		if (p % i == 0)
			return false;
		i++;
	}
	return true;
}



int main()
{
	tint n;
	cin >> n;
	forn(caso,n)
	{
		tint a;
		cin >> a;
		if (a == 0 or a  == 1)
			cout << 2 << endl;
		else
		{
			while (!esPrimo(a))
				a++;
			cout << a << endl;
		}
	}
	return 0;
}
