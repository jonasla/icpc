#include <iostream>
#include <vector>

#define forn(i,n) for (int i = 0; i < (int) (n); i++)
#define forsn(i,s,n) for (int i = (s); i < (int) (n); i++)

typedef long long tint;

using namespace std;

 
tint g (tint n, tint i, tint r, tint b, string &l, tint soyPrimero)
{
	if (n < 0 or i < 0)
		return 0;
	else if (i == 0)
	{
		tint suma = 0;
		forsn(j,soyPrimero,b)
			if (j <= n && l[j] == 'S')
				suma++;
		return suma;
	}
	else if (r*b <= n && soyPrimero == 0) 
	{
		tint p = 0;
		forn(j,b)
			if (l[j] == 'S')
				p++;
		tint ans = 1;
		forn(j,i+1)
			ans *= p;
		return ans;
	}
	else
	{
		tint suma = 0;
		forsn(j,soyPrimero,b)
			if (l[j] == 'S')
				suma += g(n-j*r, i-1, r/b, b, l, 0);
		return suma;
	}
			
		
}

tint f (tint n, tint b, string &l)
{
	tint suma = 0, r = 1, p = 1,c = 0;
	while (p < n)
	{
		p *= b;
		c++;
	}
	
	forn(i,c+1)
	{
		suma += g(n,i,r,b,l,1);
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
		cout << f(h,b,l) - f(d-1,b,l) << endl;
	return 0;
}
