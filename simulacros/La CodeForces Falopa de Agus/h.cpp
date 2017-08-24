#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forsn(i,s,n) for(tint i = (tint)s; i < (tint) (n); i++)
#define forn(i,n) forsn(i,0,n)

struct Raton
{
	ldouble rx,ry,vx,vy,tinX,tinY,toutX,toutY;
	Raton (ldouble rxx, ldouble ryy, ldouble vxx, ldouble vyy)
	{
		rx = rxx;
		ry = ryy;
		vx = vxx;
		vy = vyy;
	}
};

const ldouble INFINITO = 1e200;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	ldouble x1,y1,x2,y2;
	while (cin >> n >> x1 >> y1 >> x2 >> y2)
	{
		vector<Raton> raton (n,Raton(0,0,0,0));
		forn(i,n)
		{
			ldouble rx, ry, vx, vy;
			cin >> rx >> ry >> vx >> vy;
			raton[i] = Raton(rx,ry,vx,vy);
		}
		ldouble tMaxStart = -1.0, tMinEnd = INFINITO;
		bool posible = true;
		forn(i,n)
		{
			ldouble tx1 = (x1 - raton[i].rx) / raton[i].vx;
			ldouble tx2 = (x2 - raton[i].rx) / raton[i].vx;
			if ((fabs(raton[i].vx) < 0.5)) // ESTA QUIETO
			{
				if (( x1 < raton[i].rx ) && ( raton[i].rx < x2 )) // ESTA ADENTRO
				{
					raton[i].tinX = 0;
					raton[i].toutX = INFINITO;
				}
				else // ESTA AFUERA
				{
					posible = false;
					break;
				}
			} 
			else // NO ESTA QUIETO
			{
				if (tx1 < 0 && tx2 < 0) // YA ME PASE
				{
					posible = false;
					break;
				}
				else // EN ALGUN MOMENTO ENTRO
				{
					raton[i].tinX = max(ldouble(0),min(tx1,tx2));
					raton[i].toutX = max(tx1,tx2);
				}
			}
			
			
			ldouble ty1 = (y1 - raton[i].ry) / raton[i].vy;
			ldouble ty2 = (y2 - raton[i].ry) / raton[i].vy;
			if ((fabs(raton[i].vy) < 0.5)) // ESTA QUIETO
			{
				if (( y1 < raton[i].ry ) && ( raton[i].ry < y2 )) // ESTA ADENTRO
				{
					raton[i].tinY = 0;
					raton[i].toutY = INFINITO;
				}
				else // ESTA AFUERA
				{
					posible = false;
					break;
				}
			} 
			else // NO ESTA QUIETO
			{
				if (ty1 < 0 && ty2 < 0) // YA ME PASE
				{
					posible = false;
					break;
				}
				else // EN ALGUN MOMENTO ENTRO
				{
					raton[i].tinY = max(ldouble(0),min(ty1,ty2));
					raton[i].toutY = max(ty1,ty2);
				}
			}
			
			//~ ldouble ty1 = (y1 - raton[i].ry) / raton[i].vy;
			//~ ldouble ty2 = (y2 - raton[i].ry) / raton[i].vy;
			//~ if (ty1 < 0 && ty2 < 0)
			//~ {
				//~ posible = false;
				//~ break;
			//~ }
			//~ else
			//~ {
				//~ raton[i].tinY = max(ldouble(0),min(ty1,ty2));
				//~ raton[i].toutY = max(ty1,ty2);
			//~ }
			tMaxStart = max(tMaxStart,max(raton[i].tinX,raton[i].tinY));
			tMinEnd = min(tMinEnd,min(raton[i].toutX,raton[i].toutY));
		}
		if (!posible || tMaxStart >= tMinEnd)
			cout << "-1\n";
		else
			cout << fixed << showpoint << setprecision(20) << tMaxStart << "\n";
		
		
	}
	
	
}
