#include <iostream>
#include <vector>

#define forn(i,n) for (int i = 0; i < (int) (n); i++)
#define forsn(i,s,n) for (int i = (s); i < (int) (n); i++)

typedef long long tint;

using namespace std;

tint g (tint n, tint c, tint p, tint b, string &l, tint s, bool soyPrimero)
{
	if (n <= 0 or c < 0)
		return 0;
	else if (c == 0)
	{
		tint suma = 0;
		forn(i,b)
			if (l[i] == 'S' && i <= n)
				suma++;
		return suma;
	}
	else if (p*b < n)
	{
		tint r = 1;
		forn(i,c+1)
			r *= s;
		return r;
	}
	else
	{
		tint suma = 0;
		if (soyPrimero)
		{
			forn(i,b)
				if (l[i] == 'S' && i > 0)
					suma += g(n-i*p, c-1, p/b, b,l,s,false);
		}
		else
		{
			forn(i,b)
				if (l[i] == 'S')
					suma += g(n-i*p, c-1, p/b, b,l,s,false);
		}
		return suma;
	}
		
}


tint f(tint n, tint b, string &l, tint s)
{
	tint p = 1, c = 0;
	while(p < n)
	{
		p *= b;
		c++;
	}
	tint suma = 0;
	//~ cout << c << " " << p << endl;
	tint r = 1;
	forn(i,c)
	{
		suma += g(n,i,r,b,l,s,true);
		r *= b;
	}
	return suma;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint d,h,b;
	string l;
	while (cin >> d >> h >> b >> l && d != -1)
	{
		tint s = 0;
		for (auto x : l)
			s += (x == 'S');
		cout << f(h,b,l,s) - f(d-1,b,l,s) << "\n";
	}
	
	return 0;
}
