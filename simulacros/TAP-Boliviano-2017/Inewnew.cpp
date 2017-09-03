#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)
#define forsn(i,s,n) for (tint i = tint(s); i < tint (n); i++)

const tint maxD = 64;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint m,k;
	while (cin >> m >> k)
	{
		deque<tint> desarrollo;
		tint mOrig = m;
		while (m > 0)
		{
			desarrollo.push_front(m%2);
			m /= 2;
		}
		tint ansPosta = 4611686018427387904;
		tint s = desarrollo.size();
		forn(d,2)
		{
			tint l = 0, r = 0, maxDigitos = 0;
			while (l < s)
			{
				if (desarrollo[l] == d)
				{
					tint c = 0;
					while (r < s && desarrollo[r] == d)
					{
						c++;
						r++;
					}
					maxDigitos = max(maxDigitos,c);
				}
				else
					r++;
				l = r;
			}
			if (maxDigitos >= k)
				ansPosta = min(ansPosta,mOrig);
		}
		forn(i,64-s)
			desarrollo.push_front(0);
		tint j = maxD-1;
		forn(i,k)
			desarrollo[j--] = 1;
		tint cantidadDeDigito = 0, p = maxD-1;
		while (desarrollo[p] == 1)
		{
			p--;
			cantidadDeDigito++;
		}
		tint w = maxD-1;
		forn(i,cantidadDeDigito-k)
			desarrollo[w--] = 0;
		tint ans = 0;
		forn(i,maxD)
			ans += desarrollo[i]*(1 << (maxD-i-1));
		cout << ans << endl;
		if (ans >= mOrig)
			ansPosta = min(ansPosta,ans);
		if (mOrig == 0)
			cout << "0\n";
		else
			cout << ansPosta << "\n";
		
	}
	return 0;
}

