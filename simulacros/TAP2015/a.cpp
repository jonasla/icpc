#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <tuple>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stdio.h>
#include <valarray>



#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl

typedef long long tint;
typedef unsigned long long utint;
typedef long double ldouble; 

using namespace std;



void imprimirVector (vector<tint> v)
{
	if (!v.empty())
	{ 
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}
	else
		cout << "[]" << endl;
}

tint toNumber (string s)
{
	tint Number;
	if ( ! (istringstream(s) >> Number) ) Number = 0; // el string vacio lo manda al cero
	return Number;
}

string toString (tint number)
{    
    ostringstream ostr;
    ostr << number;
    return  ostr.str();
}

struct Punto // Vector
{
	ldouble x,y;
	Punto (ldouble xx, ldouble yy)
	{
		x = xx;
		y = yy;
	}
	Punto()
	{
		x = 0;
		y = 0;
	}
	Punto operator + (Punto p)
		{return Punto(x+p.x,y+p.y);}
	Punto operator - (Punto p)
		{return Punto(x-p.x,y-p.y);}
	Punto operator * (ldouble c)
		{return Punto(c*x,c*y);}

	//ldouble cosComp(Punto p)
	//	{return pEscalar(Punto(x,y),Punto(p.x,p.y))}
	
};

Punto ort (Punto p)
	{return Punto(-p.y,p.x);}

ldouble pCruz (Punto p1, Punto p2)
	{return p1.x*p2.y - p1.y*p2.x;}
	
ldouble pEscalar (Punto p1, Punto p2)
	{return p1.x*p2.x + p1.y*p2.y;}
	
ldouble norma (Punto p)
	{return sqrt(p.x*p.x + p.y*p.y);}
	
ldouble normaSqr (Punto p)
	{return p.x*p.x + p.y*p.y;}
	
ldouble areaTriangulo (Punto p1, Punto p2, Punto p3)
	{return pCruz(Punto(p2-p1),Punto(p3-p1));}
	
ldouble cosComp (Punto p1, Punto p2)
	{return pEscalar(p1,p2)/norma(p1)/norma(p2);}

ldouble sinComp (Punto p1, Punto p2)
	{return abs(pCruz(p1,p2))/norma(p1)/norma(p2);}
	
	

struct Circulo
{
	Punto centro;
	ldouble r;
	Circulo (Punto cc, ldouble rr)
	{
		centro = cc;
		r = rr;
	}
	Circulo()
	{
		centro = Punto();
		r = 0;
	}
};

bool operator < (Punto p1, Punto p2)
{
	return make_pair(p1.x, p1.y) < make_pair(p2.x,p2.y);
}

int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	tint n;
	while (cin >> n)
	{
		vector<Circulo> c (n);
		set<Punto> evento;
		forn(i,n)
		{
			ldouble xx,yy,rr;
			cin >> xx >> yy >> rr;
			c[i] = Circulo(Punto(xx,yy),rr);
			evento.insert(c[i].centro);
		}
		
		forn(i,n)
		forsn(j,i+1,n)
			if (c[i].r + c[j].r >= norma(c[i].centro-c[j].centro))
			{
				Punto v = c[j].centro - c[i].centro;
				ldouble p = norma(v), a = (p*p + c[i].r*c[i].r - c[j].r*c[j].r)/(2*p), b = sqrt(c[i].r*c[i].r - a*a); // dos pitagoras
				evento.insert(c[i].centro + v*(a/p) + ort(v)*(b/p));
				evento.insert(c[i].centro + v*(a/p) - ort(v)*(b/p));
			}
		tint ans = 0;
		for (auto p : evento)
		{
			tint contador = 0;
			forn(i,n)
				if (norma(Punto(p.x,p.y)-c[i].centro) <= c[i].r)
					contador++;
			ans = max(ans,contador);
		}
		cout << ans << endl;
		
	}
	return 0;
}



