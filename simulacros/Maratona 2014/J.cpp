#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <bitset>
#include <cassert>

using namespace std;

typedef int tint;

#define forn(i,n) for (tint  i = 0; i < (tint) (n) ; i++)
#define forsn(i,s,n) for (tint  i = (tint)(s); i < (tint) (n) ; i++)

const tint maxN = 32768;
const tint maxK = 16;
const tint INFINITO = 1e8;

vector<tint> caminito;

tint representante[maxN];
tint tamanho[maxN];
tint d[maxN];
pair<tint,tint> p[maxN][maxK]; // ancestro a distancia 2**k, minima arista entre los 2**k ancestros



void inicializar (tint n)
{
	forn(i,n)
	{
		representante[i] = i;
		tamanho[i] = 1;
		forn(k,maxK)
			p[i][k] = {-1,INFINITO};
	}
}



tint find (tint x)
{
	caminito = {};
	while (x != representante[x])
	{
		caminito.push_back(x);
		x = representante[x];	
	}
	for (auto z : caminito)
		representante[z] = x;
	return x;
}

bool same (tint a, tint b)
{
	return (find(a) == find(b));
}

void unite (tint a, tint b)
{
	a = find(a);
	b = find(b);
	if (tamanho[a] < tamanho[b])
		swap(a,b);
	tamanho[a] += tamanho[b];
	representante[b] = a;	
}

struct Arista
{
	tint a,b,peso;
	Arista (tint aa, tint bb, tint pp)
	{
		a = aa;
		b = bb;
		peso = pp;
	}
};

bool operator < (Arista a1, Arista a2)
{
	return make_tuple(a1.peso,a1.a,a1.b) > make_tuple(a2.peso,a2.a,a2.b);
}

void dfs(tint actual, vector<vector<pair<tint,tint> > > &ladj, tint padre)
{
	d[actual] = d[padre]+1;
	for (auto x : ladj[actual])
		if (x.first != padre)
		{
			p[x.first][0] = {actual,x.second};
			dfs(x.first,ladj,actual);
		}
	
}

tint subir(tint a, tint c, tint &ans, bool tomaMinimo)
{
	tint k = 0;
	while (c > 0)
	{
		if (c % 2)
		{
			if (tomaMinimo)
				ans = min(ans,p[a][k].second);
			a = p[a][k].first;
		}
		k++;
		c /= 2;
	}
	return a;
}

tint answer (tint a, tint b)
{
	if (d[a] < d[b])
		swap(a,b);
	
	tint w = d[a] - d[b], ans = INFINITO;
	a = subir(a,w,ans,true);
	//~ cout << ans << endl;
	assert(d[a] == d[b]);
	tint cInf = 0, cSup = maxN; // subiendo n se encuentran seguro, siguiendo 0 no se encuentran, porque a != b
	while (cSup - cInf > 1)
	{
		//~ cout << cInf << " " << cSup << endl;
		tint ra = a, rb = b;
		tint c = (cSup+cInf)/2;
		ra = subir(ra,c,ans,false);
		rb = subir(rb,c,ans,false);
		if (ra == rb)
			cSup = c;
		else
			cInf = c;
	}
	cSup *= (a != b);
	//~ cout << "*** " << cSup << endl;
	//~ cout << a << " " << b << endl;
	a = subir(a,cSup,ans,true);
	b = subir(b,cSup,ans,true);
	
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//holis
	tint n,m,s;
	while (cin >> n >> m >> s)
	{
		inicializar(n);
		
		vector<Arista> e (m,Arista(0,0,0));
		forn(i,m)
		{
			tint aa,bb,pp;
			cin >> aa >> bb >> pp;
			e[i] = Arista (aa-1,bb-1,pp);
		}
		sort(e.begin(),e.end());
		vector<vector<pair<tint,tint> > > ladj(n);
		forn(i,m)
		{
			if (find(e[i].a) != find(e[i].b))
			{
				unite(e[i].a,e[i].b);
				ladj[e[i].a].push_back({e[i].b,e[i].peso});
				ladj[e[i].b].push_back({e[i].a,e[i].peso});
			}
		}
		
		d[0] = -1;
		dfs(0,ladj,0);
		forsn(k,1,maxK)	
			forn(i,n)
			{
				tint ancestro = p[i][k-1].first;
				if (ancestro >= 0)
					p[i][k] = {p[ancestro][k-1].first, min(p[i][k-1].second,p[ancestro][k-1].second) };
			}
		
		forn(k,s)
		{
			tint l,h;
			cin >> l >> h;
			cout << answer(l-1,h-1) << "\n";
		}
		
	}
	
	return 0;
}

