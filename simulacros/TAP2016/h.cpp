#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)


typedef long long tint;
typedef long double ldouble;

struct Terna
{
	ldouble x,y,n;
	Terna(ldouble aa, ldouble bb, ldouble cc)
	{
		x = aa;
		y = bb;
		n = cc;
	}
	
};

bool operator < (Terna t1, Terna t2)
{
	return make_tuple(t1.x,t1.y,t1.n) < make_tuple(t2.x,t2.y,t2.n);
}

map<Terna,ldouble> h;

ldouble p (ldouble x, ldouble y, ldouble n)
{
	//cout << x << " " << y << " " << n << endl;
	ldouble r = 0.0;
	if (h.find(Terna(x,y,n)) != h.end())
		return h[Terna(x,y,n)];
	else
	{
		if (x > n + 0.5)
			return 0.0;
		if (y <= 1.5 && x >= 1.5)
			r = 4*(1/n)*(x-1)/(n-1);
		else if (y <= 1.5)
			r = ldouble((n <= 1.5));
		else if (n >= 1.5)
		{
			
			if (n - x >= 1.5)
				r += p(x,y-1.0,n-1.0)*(n-x)*(n-x-1.0)/n/(n-1.0);
			if (x >= 2.5)
				r += p(x-1.0,y-1.0,n-1.0) * (x-2.0)*(x-1.0)/n/(n-1.0);
			if ( n - x >= 0.5)
				r += p(x,y-1.0,n-1.0)*1.0/n*(n-x)/(n-1.0);
			if (n - x >= 0.5 && x >= 1.5)
				r += p(x,y-1.0,n-1.0)*(x-1.0)*(n-x)/n/(n-1.0);
		}
		else 
			r = 1;
		//cout << r << endl;
		h[Terna(x,y,n)] = r;
		return r;
	}
	
}

int main()
{
	ldouble n,x,y;
	cin >> n >> x >> y;
	if (x == y && x == 1)
		printf("%.4Lf\n",ldouble(1.0));
	else if (x == y && y == n)
		printf("%.4Lf\n",p(x,n-y,n)/2.0);
	else
		printf("%.4Lf\n",p(x,n-y,n));
}

