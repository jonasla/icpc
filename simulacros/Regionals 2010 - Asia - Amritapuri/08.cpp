#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <iomanip>
#include <cmath>



using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forsn(i,s,n) for(tint i = (tint)(s) ;  i < (tint)(n); i++)
#define forn(i,n) for(tint i = (tint)(0) ;  i < (tint)(n); i++)

const ldouble epsilon = 1e-10;
const ldouble pi = acos(-1);

struct Punto
{
	ldouble x,y;
	Punto (ldouble xx, ldouble yy)
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

Punto operator - (Punto p1, Punto p2)
{
	return Punto(p1.x-p2.x,p1.y-p2.y);
}

ldouble operator ^ (Punto p1, Punto p2)
{
	return p1.x*p2.y - p1.y*p2.x;
}

ldouble areaTriangulo (Punto p1, Punto p2, Punto p3)
{
	return abs((p1-p3)^(p1-p2))/2.0;
}

ldouble areaPoligono(vector<Punto> &polygon)
{
	ldouble area = 0.0;
	tint n = polygon.size();
	forn(i,n)
		area += polygon[i]^polygon[(i+1)%n];
	return abs(area)/2.0;
}

struct Query
{
	tint batch, left, right,id;
	Query(tint bb, tint ll, tint rr, tint ii)
	{
		batch = bb;
		left = ll;
		right = rr;
		id = ii;
	}
};

bool operator < (Query q1, Query q2)
{
	return make_tuple(q1.batch,q1.right,q1.left,q1.id) < make_tuple(q2.batch,q2.right,q2.left,q2.id);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,q;
	while (cin >> n >> q && n != 0)
	{
		vector<Punto> p (n, Punto(0,0));
		tint r = 1;
		while (r*r < n)
			r++;
		
		forn(i,n)
		{
			ldouble x,y;
			cin >> x >> y;
			p[i] = Punto(x,y);
		}
		ldouble area = areaPoligono(p);
		vector<Query> query (q,Query(0,0,0,0));
		forn(i,q)
		{
			tint a,b;
			cin >> a >> b;
			query[i] = Query(a/r,a,b,i);
		}
		sort(query.begin(),query.end());
		tint i = 0, j = 1;
		ldouble s = 0.0;
		vector<ldouble> ans (q);
		for (auto z : query)
		{
			if (j < z.right)
			{
				while (j < z.right)
				{
					j++;
					s += areaTriangulo(p[j],p[j-1],p[i]);
				}
			} 
			else
			{
				while (j > z.right)
				{
					j--;
					s -= areaTriangulo(p[j],p[j+1],p[i]);
				}
			}
			if (i < z.left)
			{
				while (i < z.left)
				{
					i++;
					s -= areaTriangulo(p[i],p[i-1],p[j]);
				}
			}
			else
			{
				while (i > z.left)
				{
					i--;
					s += areaTriangulo(p[i],p[i+1],p[j]);
				}
			}
			ans[z.id] =  min(s,area-s);
		}
		//~ vector<Punto> aux = {p[0],p[4],p[5],p[6]};
		//~ cout << areaPoligono(aux) << endl;
		forn(h,q)
			cout << fixed << showpoint << setprecision(1) << ans[h] << "\n";
		
	}
	
	return 0;
	
}
