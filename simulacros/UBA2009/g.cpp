#include <iostream>
using namespace std;

int main()
{
	int r,c;
	cin >> r >> c;
	while (r != -1)
	{
		if (r == 1)
			cout << 52 + 13 * c + 38 * (c-1) * 2 << endl;
		else if (c == 1)
			cout << 52 + 13 * r + 38 * (r-1) * 2 << endl;
		else if (r % 2 == 1 && c % 2 == 1)
			cout << (90 + 51 * r *c) << endl;
		else
			cout << 52 + 51*r*c << endl;
		cin >> r >> c;
	}
	return 0;
}
