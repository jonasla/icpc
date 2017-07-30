#include <utility>
#include <tuple>
#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

typedef int tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)
#define forsn(i,s,n) for (tint i = (s); i < tint (n); i++)

struct Terna
{
	tint a,b,c;
	Terna (tint aa, tint bb, tint cc)
	{
		a = aa;
		b = bb;
		c = cc;
	}
};

bool operator < (Terna t1, Terna t2)
{
	return make_tuple (t1.a,t1.b,t1.c) < make_tuple (t2.a,t2.b,t2.c); 
}

tint f (tint i)
{
	if (i < 0)
		return -1;
	set<Terna> s;
	forsn(a,1,i+1)
	{
		if (i % a == 0)
		{
			forsn(b,1,i+1)
			{
				if (a*b > i)
					break;
				if ( i % b == 0 && (i % (i/(a*b))) == 0)
				{
					tint c = i/(a*b);
					if (a*b*c == i)
					{
						s.insert(Terna(a,b,c));
						s.insert(Terna(a,c,b));
						s.insert(Terna(b,a,c));
						s.insert(Terna(b,c,a));
						s.insert(Terna(c,a,b));
						s.insert(Terna(c,b,a));
					}
				}
			}
		}
	}
	return s.size();
}

tint intPow (tint n, tint k)
{
	tint r = 1;
	forn(i,k)
		r *= n;
	return r;
}

int main()
{
	
		vector<tint> w = {2,3,5,7,11,13,17,23};
		tint q = 1;
		forsn(i,0,5)
		{
			forsn(j,0,5)
			{
				forsn(k,0,5)
				{
					forsn(l,0,5)
					{
						forsn(p,0,5)
						{
							q = intPow(2,i)*intPow(3,j)*intPow(5,k)*intPow(7,l)*intPow(11,p);
							tint x = f(q);
							if (q < 10000 && x > 0)
								cout << "(" << i << " " << j << " " << k << " " << l << " " << p << ") = " << x << endl;
						}
					}
				}
			}
		}
	return 0;
}
