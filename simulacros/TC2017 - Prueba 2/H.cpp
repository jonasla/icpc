#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <tuple>


using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)


struct Vaca
{
	tint precio,cupon,diferencia,indice;
	Vaca (tint pp, tint cc, tint dd, tint ii)
	{
		precio = pp;
		cupon = cc;
		diferencia = dd;
		indice = ii;
	}
};

bool porCupon (Vaca v1, Vaca v2)
{
	return make_tuple(v1.cupon, v1.diferencia, v1.precio, v1.indice) < make_tuple(v2.cupon, v2.diferencia, v2.precio, v2.indice);
}

bool porPrecio (Vaca v1, Vaca v2)
{
	return make_tuple(v1.precio, v1.cupon, v1.diferencia, v1.indice) < make_tuple(v2.precio, v2.cupon, v2.diferencia, v2.indice);
}

bool porDiferencia (Vaca v1, Vaca v2)
{
	return make_tuple(v2.diferencia, v1.cupon, v1.precio, v1.indice) < make_tuple(v1.diferencia, v2.cupon, v2.precio, v2.indice);
}

tint f (vector<Vaca> &vCupon, vector<Vaca> &vPrecio, tint m, tint r, tint k)
{
	tint n = vCupon.size();
	tint ans = 0;
	vector<tint> usado (n,0);
	forn(i,min(k,r))
	{
		if (m - vCupon[i].cupon >= 0)
		{
			ans++;
			m -= vCupon[i].cupon;
			usado[vCupon[i].indice] = 1;
		}
	}
	forn(i,n)
	{
		if ( (!usado[vPrecio[i].indice]) && (m - vPrecio[i].precio >= 0) )
		{
			ans++;
			m -= vPrecio[i].precio;
		}
	}
	return ans;
	
	
}

pair<tint,tint> ternary (vector<Vaca> &v1, vector<Vaca> &v2, tint m, tint k)
{
	tint a = 0, b = v1.size()+1;
	while (b - a > 5)
	{
		tint c1 = (2*a+b)/3, c2 = (a+2*b)/3;
		if (f(v1,v2,m,c1,k) < f(v1,v2,m,c2,k))
			a = c1;
		else
			b = c2;
	}
	return {a,b};
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,k,m;
	while (cin >> n >> k >> m)
	{
		
		vector<Vaca> vCupon (n, Vaca(0,0,0,0)),vPrecio (n, Vaca(0,0,0,0)), vDiferencia (n, Vaca(0,0,0,0));
		forn(i,n)
		{
			tint p,c;
			cin >> p >> c;
			vCupon[i] = Vaca(p,c,p-c,i);
			vPrecio[i] = Vaca(p,c,p-c,i);
			vDiferencia[i] = Vaca(p,c,p-c,i);
		}
		// ESTO ES ESTA MAL. LOS CASOS SON DEBILES SI DA AC
		sort(vCupon.begin(),vCupon.end(),porCupon);
		sort(vPrecio.begin(),vPrecio.end(),porPrecio);
		sort(vDiferencia.begin(),vDiferencia.end(),porDiferencia);
		pair<tint,tint> p1 = ternary(vDiferencia,vPrecio,m,k);
		pair<tint,tint> p2 = ternary(vCupon,vPrecio,m,k);
		tint ans = 0;
		forsn(r,p1.first,p1.second+1)
			ans = max(ans,f(vDiferencia,vPrecio,m,r,k));
		forsn(r,p2.first,p2.second+1)
			ans = max(ans,f(vCupon,vPrecio,m,r,k));
		cout << ans << "\n";
	
	}
	return 0;
}
