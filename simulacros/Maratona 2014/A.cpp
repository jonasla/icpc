#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

int main()
{
	tint a,b,c;
	while (cin >> a >> b >> c)
	{
		if (a+b+c == 1)
		{
			if (a == 1)
				cout << "A\n";
			else if (b == 1)
				cout << "B\n";
			else 
				cout << "C\n";
		}
		else if (a+b+c == 2)
		{
			if (a == 0)
				cout << "A\n";
			else if (b == 0)
				cout << "B\n";
			else 
				cout << "C\n";
		}
		else 
			cout << "*\n";
	}
	return 0;
}
