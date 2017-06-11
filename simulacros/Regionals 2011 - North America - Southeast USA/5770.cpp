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

typedef long long tint;
typedef unsigned long long utint;
typedef long double ldouble; 


#define forn(i,n) for(tint i=0;i<(tint)(n); i++)
#define forsn(i,s,n) for(tint i=(s);i<(tint)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl



using namespace std;



void imprimirVector (vector<ldouble> v)
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

struct Trecho
{
	char tipo;
	ldouble largo;
	Trecho (char tt, ldouble ll)
	{
		tipo = tt;
		largo = ll;
	}
};

const ldouble INFINITO = 1e18;
const ldouble pi = acos(-1);

ldouble f(vector<Trecho> &v, tint tramoSalida, tint carrilSalida, tint carrilLlegada)
{
	if (v[tramoSalida].largo >= 100.0 * ldouble(abs(carrilSalida-carrilLlegada)))
		return sqrt(v[tramoSalida].largo*v[tramoSalida].largo + ldouble(abs(carrilSalida-carrilLlegada)*abs(carrilSalida-carrilLlegada))*100.0);
	else
		return INFINITO;	
}

ldouble best(vector<vector<ldouble> > &d, vector<Trecho> &v, tint tramo, tint carril, char last, bool sentido)
{
	tint m = d[0].size();
	if (d[tramo][carril] == INFINITO)
	{
		
		if (last == 'L' && v[tramo].tipo == 'R')
		{
			last = 'R';
			sentido = !sentido;
		}
		else if (last == 'R' && v[tramo].tipo == 'L')
		{
			last = 'L';
			sentido = !sentido;
		}
		
		if (v[tramo].tipo == 'S')		
			forn(i,m)
				d[tramo][carril] = min(d[tramo][carril], best(d,v,tramo-1,i,last,sentido) + f(v,tramo,carril,i));
		else if (sentido)
			d[tramo][carril] = best(d,v,tramo-1,carril,last,sentido) + pi/2.0*((v[tramo].largo+5.0) + 10.0*ldouble(carril));
		else
			d[tramo][carril] = best(d,v,tramo-1,carril,last,sentido) + pi/2.0*((v[tramo].largo+5.0) + 10.0*ldouble(m-carril-1));
		
	}
	return d[tramo][carril];
}


int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	tint n,m;
	while (cin >> n >> m && n != 0)
	{
		
		vector<Trecho> v (n+2,Trecho('S',0.0));
		char last = 'L';
		forn(i,n)
		{
			char t;
			ldouble k;
			cin >> t >> k;
			if (t != 'S')
				last = t;
			v[i+1] = Trecho(t,k);
		}
		bool sentido = true;
		vector<vector<ldouble> > d (n+2, vector<ldouble> (m,INFINITO));
		forn(i,m)
			d[0][i] = 0;
		ldouble ans = INFINITO;
		forn(i,m)
			ans = min(ans,best(d,v,n+1,i,last,sentido));
			
		double ansPosta = double(ans);
		printf("%.2f\n", ansPosta);
	}
	return 0;
}



