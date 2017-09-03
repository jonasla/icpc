#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,k;
	while (cin >> n >> k)
	{
		vector<tint> a (n);
		forn(i,n)
			cin >> a[i];
		tint j = 0, suma = 0;
		tint l = -1, r = -1;
		forn(i,n)
		{
			if (i > 0)
				suma -= a[i-1];
			//~ cout << i << " " << j << " " << suma << endl;
			while (j < n && suma + a[j] <= k)
			{
				suma += a[j];
				j++;
			}
			if (suma == k)
			{
				l = i+1;
				r = j;
				break;
			}
		}
		if (l < 0 or r < 0)
			cout << "-1\n";
		else
			cout << l << " " << r << "\n";
	}
	return 0;
}
