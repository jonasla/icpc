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
#include <random>
#include <iomanip>


typedef long long tint;
typedef unsigned long long utint;
typedef long double ldouble; 


#define forn(i,n) for(tint i=0;i<(tint)(n); i++)
#define forsn(i,s,n) for(tint i=(s);i<(tint)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl



using namespace std;



void imprimirVector (vector<tint> v)
{
	if (!v.empty())
	{ 
		tint p = tint(v.size());
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
	if ( ! (istringstream(s) >> Number) )
		Number = 0; // el string vacio lo manda al cero
	return Number;
}

string toString (tint number)
{    
    ostringstream ostr;
    ostr << number;
    return  ostr.str();
}

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

Punto operator + (Punto p1, Punto p2)
{
	return Punto(p1.x+p2.x,p1.y+p2.y);
}

Punto operator - (Punto p1, Punto p2)
{
	return Punto(p1.x-p2.x,p1.y-p2.y);
}

Punto operator * (ldouble lambda, Punto p)
{
	return Punto(lambda*p.x, lambda*p.y);
}

ldouble operator * (Punto p1, Punto p2)
{
	return p1.x*p2.x+p1.y*p2.y;
}

ldouble operator ^ (Punto p1, Punto p2)
{
	return p1.x*p2.y - p1.y*p2.x;
}

Punto operator ~ (Punto p)
{
	return Punto(-p.y,p.x);
}

ldouble norma (Punto p)
{
	return sqrt(p.x*p.x+p.y*p.y);
}

bool operator < (Punto p1, Punto p2)
{
	return make_pair(p1.x,p1.y) < make_pair(p2.x,p2.y);
}

bool operator == (Punto p1, Punto p2)
{
	return ((abs(p1.x-p2.x) < epsilon) && (abs(p1.y-p2.y) < epsilon));
}

struct Segmento
{
	Punto start,end,dir;
	Segmento (Punto ss, Punto ee)
	{
		start = ss;
		end = ee;
		dir = ee-ss;
	}
};

pair<Punto,tint> interSeg (Segmento s1, Segmento s2, bool otroExtremo ) // Si estan sobre la misma linea e intersecan, da el punto medio. Si no intersecan avisa
{
	
	if ((abs(s1.dir ^ s2.dir)) < epsilon) // son colineales
	{
		vector<pair<Punto,tint> > aux = {{s1.start - epsilon*s1.dir,1},
										 {s1.end   + epsilon*s1.dir,1},
										 {s2.start - epsilon*s2.dir,2},
										 {s2.end   + epsilon*s2.dir,2}};
		sort(aux.begin(),aux.end());
		if (aux[0].second != aux[1].second)
			return make_pair(aux[1+otroExtremo].first,2);
		else
			return make_pair(Punto(),0);
	}
	else
	{
		ldouble alfa = ((s2.start-s1.start)^s2.dir) / (s1.dir^s2.dir);
		if (0 <= alfa && alfa <= 1)
			return make_pair(s1.start+alfa*s1.dir,1);
		else
			return make_pair(Punto(),0);
	}
}


ldouble angEntre (Punto p1, Punto p2, Punto p3) // P1^P2P3
{
	ldouble a = norma(p2-p3);
	ldouble b = norma(p1-p3);
	ldouble c = norma(p2-p1);
	return acos((a*a+c*c-b*b)/(2*a*c));
}

ldouble dPuntoSeg (Punto p, Segmento s)
{
	if (angEntre(p,s.start,s.end) > pi/2 or angEntre(p,s.end,s.start) > pi/2)
		return min(norma(p-s.start),norma(p-(s.end)));
	else
		return abs( ((s.start-p)^(s.end-p)) / (norma(s.dir)) );
}

ldouble dEntreSeg(Segmento s1, Segmento s2)
{
	ldouble a = min(dPuntoSeg(s1.start,s2),dPuntoSeg(s1.end,s2));
	ldouble b = min(dPuntoSeg(s2.start,s1),dPuntoSeg(s2.end,s1));
	return (interSeg(s1,s2,false).second == 0) * min(a,b);
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

bool adentroPoligono(vector<Punto> &polygon, Punto p) // EN EL SENTIDO DE LAS AGUJAS
{
	bool adentro = true;
	tint n = polygon.size();
	forn(i,n)
		adentro &= (((p-polygon[i])^(p-polygon[(i+1)%n])) < 0);
	return adentro;
}


int main()
{
	
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout << dPuntoSeg(Punto(2,0),Segmento(Punto(0,0), Punto(1,-1))) << endl;
	pair<Punto,tint> inter = interSeg(Segmento(Punto(0,0),Punto(0,5)),Segmento(Punto(0,3),Punto(0,4)),1);
	cout << inter.second << "\n";
	cout << fixed << showpoint << setprecision(16) << inter.first.x << " " << inter.first.y << "\n";
	return 0;
}
