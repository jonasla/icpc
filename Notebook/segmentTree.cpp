#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = tint(0); i < tint (n); i++)

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
	return Nodo(n1.x+n2.x);
}

vector<Nodo> buildSegTree (vector<Nodo> &v )
{
	// Completa el tamanho
	tint k = 4, n = v.size();
	while (k < 2*n)
		k *= 2;
	// Rellena las hojas
	vector<Nodo> seg (k, Nodo(0));
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
		return 0; // Aca va el NEUTRO de la funcion "op"
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




void imprimirVector (vector<Nodo> v)
{
	if (!v.empty())
	{ 
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i].x << ",";
		cout << v[p-1].x << "]" << endl;
	}
	else
		cout << "[]" << endl;
}




int main()
{
	tint n = 15;
	vector<Nodo> v (n, Nodo(0));
	forn(i,n)
		v[i] = Nodo((3*(i+1))% 7 - 9*(i-4)%13);
	vector<Nodo> seg = buildSegTree(v);
	imprimirVector(v);
	cout << query(3,11,seg).x << "\n";
	
	
	return 0;
}
