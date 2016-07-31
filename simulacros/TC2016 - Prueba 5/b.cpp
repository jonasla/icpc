#include <iostream>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forsn(i,s,n) for(int i=s;i<(int)n;i++)

using namespace std;

typedef long long tint;
typedef long double ldouble;

struct Punto
{
	double x,y;
	Punto (double xx, double yy)
	{
		x = xx;
		y = yy;
	}
};

Punto operator + (Punto p1, Punto p2)
{
	return Punto(p1.x+p2.x, p1.y+p2.y);
}

Punto operator - (Punto p1, Punto p2)
{
	return Punto(p1.x-p2.x, p1.y-p2.y);
}

Punto operator * (ldouble k, Punto p)
{
	return Punto(k*p.x, k*p.y);
}

double operator * (Punto p1, Punto p2)
{
	return p1.x*p2.x + p1.y*p2.y;
}

double norma(Punto p)
{
	return sqrt(p*p);
}

double pcruz (Punto p1, Punto p2)
{
	return p1.x*p2.y - p2.x*p1.y;
}

double areaTriangulo(Punto a, Punto b, Punto c)
{
	return abs(pcruz(b-a,c-a))/2.0;
}



int main()
{
	tint n;
	cin >> n;
	//cout << "AREA = " << areaTriangulo(Punto(-1,0), Punto(1,0), Punto(0,1)) << endl;
	forn(caso, n)
	{
		vector<double> aux (3);
		cin >> aux[0] >> aux[1] >> aux[2];
		sort(aux.begin(),aux.end());
		double x = aux[0], y = aux[1], z = aux[2];
		
		
		double b = (y*y + x*x -z*z)/(2*x*y);
		double a = (x - b*y)/z;
		//cout << "a = " << a << endl;
		double tita = acos(a);
		//cout << "TITA = " << acos(3.0/5.0) << endl;
		//cout << "tita = " << tita << endl;
		Punto B = Punto(x,0);
		Punto C = Punto(cos(tita)*z, sin(tita)*z);
		Punto P = Punto(2*x,0);
		Punto Q = 2*C-B;
		Punto R = (-1)*C;
		//cout << "B = (" << B.x << ", " << B.y << ")" << endl;
		//cout << "C = (" << C.x << ", " << C.y << ")" << endl;
		//cout << "P = (" << P.x << ", " << P.y << ")" << endl;
		//cout << "Q = (" << Q.x << ", " << Q.y << ")" << endl;
		//cout << "R = (" << R.x << ", " << R.y << ")" << endl;
		
		double ans = areaTriangulo(P,Q,R);
		printf("%.1f\n", ans);
	}
	return 0;
}
