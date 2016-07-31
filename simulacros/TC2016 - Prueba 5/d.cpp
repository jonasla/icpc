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

double areaParalelogramo(Punto a, Punto b, Punto c)
{
	return abs(pcruz(b-a,c-a));
}

int main(){
	double ax,ay,bx,by,cx,cy,dx,dy,ex,ey,fx,fy;
	while(cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy>>ex>>ey>>fx>>fy){
		if(ax==0 && ay==0 && bx==0 && by==0 && cx==0 && cy==0 && dx==0 && dy==0 && ex==0 && ey==0 && fx==0 && fy==0)
			break;
		Punto A = Punto(ax,ay);
		Punto B = Punto(bx,by);
		Punto C = Punto(cx,cy);
		//triagulo
		Punto D = Punto(dx,dy);
		Punto E = Punto(ex,ey);
		Punto F = Punto(fx,fy);
		double area = areaTriangulo(D,E,F);
		
		Punto H = A+(1/abs(pcruz(B-A,C-A)))*(area*(C-A));
		
		Punto G = B+(1/abs(pcruz(B-A,C-A)))*area*(C-A);
		printf("%.3f %.3f %.3f %.3f\n",G.x,G.y,H.x,H.y); 
	}
	return 0;
}
