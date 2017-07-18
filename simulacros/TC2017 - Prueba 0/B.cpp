#include <iostream>
#include <vector>

#define forn(i,n) for (int i = 0; i < (int) (n); i++)
#define forsn(i,s,n) for (int i = (s); i < (int) (n); i++)

typedef long long tint;

using namespace std;

int main()
{
	tint n;
	while (cin >> n && n != -1)
	{
		tint ans = 0;
		forsn(a,1,n+1)
		{
			tint b = 1;
			while (b <= a && b*b <= n)
			{
				if (((n-a*b) % (a+b) == 0) && (n-a*b >= 0) && ((n-a*b)/(a+b) <= b))
					ans++ ;
				b++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
