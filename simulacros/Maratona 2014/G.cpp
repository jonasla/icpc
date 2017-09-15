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
	tint l,c;
	while (cin >> l >> c)
	{
		
		vector<vector<tint> > r (l, vector<tint> (c));
		vector<tint> fila (l);
		forn(i,l)
		forn(j,c)
		{
			tint x;
			cin >> x;
			fila[i] = ((x-1) / c) + 1;
			r[i][j] = x;
		}
		
		bool sePuede = true;
		forn(i,l)
		{
			tint maxi = *max_element(r[i].begin(),r[i].end());
			tint mini = *min_element(r[i].begin(),r[i].end());
			sePuede &= (maxi - mini == c-1);
		}
		if (sePuede)
		{
			forn(i,l)
			forn(j,c)
				r[i][j] %= c;
			forsn(i,1,l)
			{
				bool soyIgual = true;
				forn(j,c)
					soyIgual &= (r[0][j] == r[i][j]);
				sePuede &= soyIgual;
			}
		}
		if (sePuede)
			cout << p(r[0]) + p(fila) << "\n";
		else 
			cout << "*\n";
		
		
		
	}
	
	return 0;
}
