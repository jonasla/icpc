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

const tint maxN = 1024;
const tint INFINITO = 1e15;
string s1,s2;

tint dist[maxN][maxN];

// INSERTAR, REMOVER, MODIFICAR, SWAPS ADYACENTES

tint f(tint i, tint j)
{
	if (i == -1 or j == -1) // Si un string es vacio, hay que borrar todo el otro
		return max(i,j)+1;
	if (dist[i][j] == INFINITO)
	{
		tint mini = INFINITO;		
		mini = min(mini,min(f(i-1,j)+1,f(i,j-1)+1)); // Lo mejor de borrar el i-esimo de s1 o insertar al final de s1 a s2[j]
		if (s1[i] == s2[j])
			mini = min(mini,f(i-1,j-1)); // Si coinciden, dejo como esta y resuelvo lo anterior
		else
			mini = min(mini,f(i-1,j-1)+1); // Modificar s1[i] a s2[j] y resolver lo anterior
			
		forn(k,i) // Borramos los intermedios y swapeamos los ultimos 2 si funciona, lo hago y resuelvo lo anterior
		{
			if (i >= 1 && j >= 1 && s1[i] == s2[j-1] && s1[i-k-1] == s2[j])
				mini = min(mini,f(i-k-2,j-2)+k+1);
		}
		dist[i][j] = mini;
	}
	return dist[i][j];
}

int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	while (cin >> s1 >> s2 && s1 != "*" && s2 != "*")
	{
		tint n = s1.size(), m = s2.size();
		forn(i,n)
		forn(j,m)
			dist[i][j] = INFINITO;
		cout << f(n-1,m-1) << "\n";
	}
	return 0;
}




