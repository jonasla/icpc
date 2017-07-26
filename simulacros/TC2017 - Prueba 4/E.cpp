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

struct Intervalo
{
	tint start,end;
	Intervalo (tint ss, tint ee)
	{
		start = ss;
		end = ee;
	}
};

bool operator < (Intervalo i1, Intervalo i2)
{
	return make_pair(i1.end,i1.start) < make_pair(i2.end,i2.start);
}

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
		vector<Intervalo> v (m,Intervalo(0,0));
		forn(i,m)
		{
			tint s,e;
			cin >> s >> e;
			v[i] = Intervalo(s,e);
		}
		sort(v.begin(),v.end());

		vector<Nodo> bestEndingAt(m,Nodo(INFINITO));
		vector<Nodo> seg = buildSegTree(bestEndingAt);
		
		forn(i,m)
		{
			if (v[i].start > 1)
			{
				tint a = 0, b = i; // b cumple v[b].end >= v[i].start
				if (v[a].end >= v[i].start)
					b = a;
				while (b-a > 1)
				{
					tint c = (a+b)/2;
					if (v[c].end >= v[i].start)
						b = c;
					else
						a = c;
				}	
				update(i,Nodo(1+query(b,i+1,seg).x),seg);
			}		
			else
				update(i,Nodo(1),seg);
		}
		tint ans = INFINITO;
		tint p = 1;
		while (p < m)
			p *= 2;
		forn(i,m)
			if (v[i].end == n)
				ans = min(ans,seg[p+i].x);
		cout << ans << "\n";
		
			
	}
	return 0;
}
