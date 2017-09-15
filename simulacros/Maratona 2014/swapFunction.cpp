#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (tint)(s); i < (tint)(n); i++)

tint p (vector<tint> &s)
{
	tint n = s.size();
	forn(i,n)
		if (s[i] == 0)
			s[i] = n;
	tint ans = 0;
	forn(i,n)
	{
		forsn(j,i,n)
		{
			if (s[j] == i+1)
			{
				if (j != i)
				{
					swap(s[i],s[j]);
					ans++;
				}
				break;
			}
		}
	}
	return ans;
}


int main()
{
	vector<tint> v = {4,2,3,1,5,6,7,8};
	cout << p(v) << endl;
	return 0;
}

