#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int impares = 0,pares = 0,suma = 0;
		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			impares += (a % 2);
			pares += (1-(a%2));
			suma += a;
		}
		if (suma % 2)
			cout << impares << endl;
		else
			cout << pares << endl;
	}
	return 0;
}
