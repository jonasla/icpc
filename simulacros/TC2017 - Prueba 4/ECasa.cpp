#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;

typedef int tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

const tint INFINITO = 2e9;

// Nodo del segment tree
struct Nodo
{
	tint x;
	Nodo (tint xx)
	{
		x = xx;
	}
};


// Operacion del segment tree : tiene que ser ASOCIATIVA
Nodo op (Nodo n1, Nodo n2)
{
	return Nodo(min(n1.x,n2.x));
}

vector<Nodo> buildSegTree (vector<Nodo> &v )
{
	// Completa el tamanho
	tint k = 4, n = v.size();
	while (k < 2*n)
		k *= 2;
	// Rellena las hojas con el NEUTRO
	vector<Nodo> seg (k, Nodo(INFINITO));
	forn(i,n)
		seg[k/2+i] = v[i];
	// Completa los padres
	while (k > 0)
	{
		seg[(k-1)/2] = op(seg[k-1],seg[k-2]);
		k -= 2;
	}
		
	return seg; 
}

// i es el indice de [0,n) en el arreglo original
// Nodo es lo que queremos poner ahora como hoja
void update(tint i, Nodo nodo,vector<Nodo> &seg)
{
	tint k = seg.size()/2 + i;
	seg[k] = nodo;
	while (k > 0)
	{
		seg[k >> 1] = op(seg[k],seg[k^1]);
		k /= 2;
	}
}


Nodo queryAux(tint k, tint l, tint r, tint i, tint j, vector<Nodo> &seg)
{
	
	if (i <= l && r <= j)
		return seg[k];
	if (r <= i or l >= j)
		return Nodo(INFINITO); // Aca va el NEUTRO de la funcion "op"
	Nodo a = queryAux(2*k,l,(l+r)/2,i,j,seg);
	Nodo b = queryAux(2*k+1,(l+r)/2,r,i,j,seg);
	return op(a,b);
	
}


// i,j son los indices del arreglo del que se hace la query
// la query se hace en [i,j)
Nodo query(tint i, tint j, vector<Nodo> &seg)
{
	return queryAux(1,0,seg.size()/2,i,j,seg);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint casos;
	cin >> casos;
	forn(caso,casos)
	{
		if (caso)
			cout << "\n";
		tint n,m;
		cin >> n >> m;
		vector<Nodo> bestEndingAt (n,INFINITO);
		vector<Nodo> seg = buildSegTree(bestEndingAt);
		tint p = 1;
		while (p < n)
			p *= 2;
		update(0,Nodo(0),seg);
		forn(i,m)
		{
			tint s,e;
			cin >> s >> e;
			s--;
			e--;
			tint best = query(s,e,seg).x;
			if (best != INFINITO)
				update(e, min(seg[p+e].x,best+1),seg);
		}
		cout << seg[p+n-1].x << "\n";
		
		
			
	}
	return 0;
}


