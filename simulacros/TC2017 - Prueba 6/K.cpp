#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

struct Catapulta
{
	ldouble x,y,f;
	Catapulta (ldouble xx, ldouble yy, ldouble ff)
	{
		x = xx;
		y = yy;
		f = ff;
	}
};

const ldouble INFINITO = 2e16;

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,px,py,lx,ly;
	while (cin >> n >> px >> py >> lx >> ly)
	{
		vector<Catapulta> c (n+2,Catapulta(0,0,0));
		c[0] = Catapulta(ldouble(px),ldouble(py),0.0);
		c[n+1] = Catapulta(ldouble(lx),ldouble(ly),0.0);
		forn(i,n)
		{
			ldouble xx,yy,ff;
			cin >> xx >> yy >> ff;
			c[i+1] = Catapulta(xx,yy,ff);
		}
		vector<vector<ldouble> > d (n+2, vector<ldouble> (n+2,INFINITO));
		
		forn(i,n+2)
		forn(j,n+2)
		{
			ldouble distancia = sqrt((c[i].x-c[j].x) * (c[i].x-c[j].x) + (c[i].y-c[j].y) * (c[i].y-c[j].y));
			d[i][j] = min(distancia, abs(distancia - c[i].f));
		}
		forn(i,n+2)
			d[i][i] = 0.0;
		forn(k,n+2)
		forn(i,n+2)
		forn(j,n+2)
			d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			
		cout << fixed << showpoint << setprecision(2) << d[0][n+1] << "\n";
		
		
	}
}
