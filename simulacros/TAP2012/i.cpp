#include <iostream>

#define forn(i,n) for (int i = 0; i <(int) (n); i++)

using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n != -1)
	{
		int total = 0;
		int ans = 0;
		forn(i,n)
		{
			int a;
			cin >> a;
			total = (total + a) % 100;
			if (total == 0)
				ans++;
		}
		cout << ans << endl;
		cin >> n;
	}
	return 0;
}
