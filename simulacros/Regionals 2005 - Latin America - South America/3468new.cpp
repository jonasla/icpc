#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <valarray>

typedef long long tint;
#define forn(i,n) for(tint i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(tint i=s;i<(int)(n);i++)

using namespace std;

int main()
{
	tint n;
	while (cin >> n && n != 0)
	{
		valarray<bool> post (n);
		tint q = 0, ans = 0, suma = 0;
		forn(i,n)
		{
			cin >> post[i];
			suma += post[i];
		}
		forn(i,n)
			if (post[i])
				{
					post = post.cshift(i);
					break;
				}
		if (suma == 0)
			cout << (n+1)/2 << endl;
		else
		{
			for(auto p : post)
			{
				if (!p)
					q++;
				else
				{
					ans += q/2;
					q = 0;
				}
			}
			cout << ans + q/2 << endl;
		}
	}
	return 0;
}

