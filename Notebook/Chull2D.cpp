#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

typedef long long tint;

#define forsn(i,s,n) for(int i=(tint)s; i<(tint)n; i++) 
#define forn(i,n) forsn(i,0,n) 
#define sqr(x) (x)*(x)

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
		x = 0;
		y = 0;
	}
};

Punto operator - (Punto p1, Punto p2)
{
	return Punto(p1.x-p2.x,p1.y-p2.y);
}

tint operator * (Punto p1, Punto p2)
{
	return p1.x*p2.x + p1.y*p2.y;
}

tint operator ^ (Punto p1, Punto p2)
{
	return p1.x*p2.y - p1.y*p2.x;
}

tint norma2Sqr (Punto p)
{
	return p*p;
}
tint areaTriangulo (Punto p1, Punto p2, Punto p3) // Da el doble, negativo si horario
{
	return (p1-p3)^(p1-p2);
}

bool porX (Punto p1, Punto p2)
{
	return make_pair(p1.x,p1.y) < make_pair(p2.x,p2.y);
}


Punto r;

bool operator < (Punto p1, Punto p2) 
{
	if (areaTriangulo(r,p1,p2) == 0)
		return norma2Sqr(p1-r) < norma2Sqr(p2-r);
	else
		return areaTriangulo(r,p1,p2) > 0;	
}


vector<Punto> chull(vector<Punto> &l) 
{
	vector<Punto> res = l;
	if (l.size() < 3)
		return res;
	r = *(min_element(res.begin(), res.end(), porX));
	sort(res.begin(), res.end());
	vector<Punto> ch = {res[0],res[1]};  
	tint i = 2, k = res.size();
	while(i < k) 
		if (ch.size() >= 2 && areaTriangulo(ch[ch.size()-2],ch[ch.size()-1],res[i])<0) // poner <= para capturar alineados
			ch.pop_back();
		else 
			ch.push_back(res[i++]);
	return ch;
}



