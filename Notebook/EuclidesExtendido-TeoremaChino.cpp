#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for(tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)


tint gcd (tint a, tint b, tint &x, tint &y)
{
	if (a == 0) 
	{
		x = 0 ; y = 1 ;
		return b ;
	}
	tint x1, y1 ;
	tint d = gcd ( b % a, a, x1, y1 ) ;
	x = y1 - ( b / a ) * x1 ;
	y = x1 ;
	return d;
} 

// Nota si gcd(a,m) == 1 => 1 = a*x+m*y => 1 = a*x (mod m)
// O sea, que "x" es el inverso :-)

tint modulo (tint n, tint q)
{
	return ((n%q) + q) % q;
}

pair<tint,tint> tcr (vector<tint> &r, vector<tint> &m) // x = r_i (mod m_i)
{
	tint p = 0, q = 1, n = r.size();
	forn(i,n)
	{
		p = modulo(p-r[i],q);
		tint x,y;
		tint d = gcd(m[i],q,x,y);
		if (p % d)
			return {-1,-1}; // sistema incompatible
		q = (q / d)*m[i];
		p = modulo(r[i]+m[i]*x*(p/d), q);
	}
	return {p,q}; // x = p (mod q)
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint t;
	cin  >> t;
	forn(caso,t)
	{
		tint a,n,b,m;
		cin >> a >> n >> b >> m;
		vector<tint> rr = {a,b};
		vector<tint> mm = {n,m};
		pair<tint,tint> p = tcr(rr,mm);
		if (p.first == -1)
			cout << "no solution\n";
		else
			cout << p.first << " " << p.second << "\n";
	}
	
	return 0;
}
