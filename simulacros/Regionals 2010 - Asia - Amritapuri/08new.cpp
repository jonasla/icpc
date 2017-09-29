#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forsn(i,s,n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)

struct Punto
{
	tint x,y;
	Punto (tint xx, tint yy)
	{
		x = xx;
		y = yy;
	}
	Punto()
	{
		x = 0.0;
		y = 0.0;
	}
};


tint operator ^ (Punto p1, Punto p2)
{
	return p1.x*p2.y - p1.y*p2.x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,q;
	bool first = true;
	while (cin >> n >> q && n != 0)
	{
		if (!first)
			cout << "\n";
		vector<Punto> p (n);
		
		forn(i,n)
		{
			tint x,y;
			cin >> x >> y;
			p[i] = Punto(x,y);
		}
		vector<tint> r (n+1);
		forn(i,n)
			r[i+1] += r[i] + (p[i]^p[(i+1)%n]);
		
		forn(kk,q)
		{
			tint a,b;
			cin >> a >> b;
			tint area = abs((p[a]^p[b])+r[n]-r[b]+r[a]);
			tint ans = min(abs(r[n])-area,area);
			cout << ans/2 << "." << 5*(ans%2) << "\n";
		}
		first = false;
	}
	return 0;
}
