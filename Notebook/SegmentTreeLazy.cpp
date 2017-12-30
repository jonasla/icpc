#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long tint;

#define forn(i,n) for(tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)

/// UPDATE : SUMAR X AL RANGO [L,R)
/// QUERY  : LA SUMA EN EL RANGO [L,R)


struct Nodo
{
	tint value;
	Nodo(tint vv)
	{
		value = vv;
	}
	Nodo () // NEUTRO
	{
		value = 0;
	}
};

const tint maxN = 524288;
Nodo segTree[2*maxN]; // Nodo del segment tree
tint lazy[2*maxN];    // Valores lazy que se van agregando a los updates


Nodo operation (Nodo n1, Nodo n2)
{
	return Nodo(n1.value+n2.value);
}

void updateNode (tint k,tint start, tint end, tint upd)
{
	segTree[k].value = segTree[k].value + (end - start) * upd;
}

void propagate(tint updatePadre, tint &updateHijo)
{
	updateHijo = updateHijo + updatePadre;
}

// k es el nodo actual, y representa el intervalo [start,end) en v
// Al comenzar, llamar con (1,0,n,v)
void buildSegTree (tint k, tint start, tint end, const vector<Nodo> &v)
{
	if (start == end-1)
		segTree[k] = v[start];
	else
	{
		tint mid = (start + end) / 2;
		buildSegTree(2*k,start,mid,v);   // izquierda
		buildSegTree(2*k+1,mid,end,v); // derecha
		segTree[k] = operation(segTree[2*k],segTree[2*k+1]);
	}
}


void lazyUpdate(tint k, tint start, tint end, tint upd)
{
	updateNode(k,start,end,upd);
	if (start != end-1)
	{
		propagate(upd,lazy[2*k]);
		propagate(upd,lazy[2*k+1]);
	}
	lazy[k] = 0;
}

// Hace el update especificado en [l,r), llamar con (1,0,n,l,r,upd)
void updateRange(tint k, tint start, tint end, tint l, tint r, tint upd)
{
	if (lazy[k] != 0)
			lazyUpdate(k,start,end,lazy[k]);
	if (start < r && l < end) // si interseca lo buscado
	{
		if (l <= start && end <= r) // totalmente contenido
			lazyUpdate(k,start,end,upd);
		else
		{
			tint mid = (start + end) / 2;
			updateRange(2*k,start,mid,l,r,upd);
			updateRange(2*k+1,mid,end,l,r,upd);
			segTree[k] = operation(segTree[2*k],segTree[2*k+1]);
		}
	}
}

// Responde la query en [l,r), llamar con (1,0,n,l,r)
Nodo queryRange(tint k, tint start, tint end, tint l, tint r)
{
	if (start >= r || end <= l)
		return Nodo();
	if (lazy[k] != 0)
		lazyUpdate(k,start,end,lazy[k]);
	if (l <= start && end <= r)
		return segTree[k];
	else
	{
		tint mid = (start + end) / 2;
		return operation(queryRange(2*k,start,mid,l,r),queryRange(2*k+1,mid,end,l,r));
	}
}

// La diferencia con el 3 es que este trabaja [l,r)
int main()
{
	vector<Nodo> v = {Nodo(1),Nodo(3),Nodo(5),Nodo(7),Nodo(9),Nodo(11)}; 
	tint n = v.size();
	buildSegTree(1,0,n-1,v);
	forn(q,16)
		cout << q << " : " << segTree[q].value << endl;
	updateRange(1,0,n-1,1,5,3);
	updateRange(1,0,n-1,2,3,2);
	updateRange(1,0,n-1,0,3,1);
	cout << queryRange(1,0,n-1,0,5).value << endl;
	return 0;
}
