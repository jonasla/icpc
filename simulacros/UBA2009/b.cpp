#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n);i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int) (n);i++)


/*vector<int> lis(vector<int> v)
{
	int n = v.size();
	vector<int> mv (n);
	vector<int> mi (n);
	vector<int> p (n);
	vector<int> l (n);
	int inf = 1000000;
	forn(i,n) mv[i] = inf;
	forn(i,n) mi[i] = -1;
	forn(i,n) p[i] = -1;
	mv[0] = -inf;
	int res = 0;
	forn(i,n)
	{
		int me = mv.lower_bound(v[i]) - mv[i];
		p[i] = mi[me-1];
		mv[me] = v[i];
		mi[me] = i;
		if (me > res) res = me;
	}
	
	for (int a = mi[res], i = res-1; a, != -1; a = p[a], i--)
		l[i] = a;
	return l;	
}
*/

struct Pila
{
	Pila (int top, int tamanho, vector<int> listita)
	{
		tope = top;
		tam = tamanho;
		list = listita;
	}
	int tope, tam;
	vector<int> list;
};


bool operator < (Pila p1,Pila p2)
{
	return p1.tope < p2.tope;
}

vector<int> lis(vector<int> v)
{
	int n = v.size();
	set<Pila> p;
	forn(i,n)
	{
		int elem = v[i];
		vector<int> aux = {i};
		Pila pilaNueva = Pila (elem,1,aux);
		if (!p.empty() && p.lower_bound(pilaNueva) != p.begin() )
		{
			Pila pilaVieja = *(--p.upper_bound(pilaNueva));
			p.erase(pilaVieja);
			pilaVieja.list.push_back(i);
			pilaVieja.tope = elem;
			pilaVieja.tam++;
			pilaNueva = pilaVieja;
			
			//cout << pilaVieja.tope << endl;
		}
		p.insert(pilaNueva);
	}
	vector<int> l;
	for (auto pilita : p)
	{
		int largo = l.size();
		if (pilita.tam > largo)
			l = pilita.list;	
	}
	return l;
	
}


int main()
{
	
	int n;
	cin >> n;
	while (n != -1)
	{
		vector<int> v (n);
		vector<bool> use (n,false);
		int ans = 0;
		
		forn(i,n)
			cin >> v[i];
		vector<int> creciente = lis(v);
		//forn(i,creciente.size())
		//	cout << creciente[i] << " ";
		//cout << endl;
		for(auto indice: creciente)
			use[indice] = true;
		
		vector<int> negativos;
		forn(i,n)
			if (!use[i])
				negativos.push_back(-v[i]);
		int m = negativos.size();
		
		vector<bool> useN (m,false);
		vector<int> decreciente = lis(negativos);
		//forn(i,decreciente.size())
		//	cout << decreciente[i] << " ";
		//cout << endl;
		for(auto indice: decreciente)
			useN[indice] = true;
			
		forn(i,m)
			if (!useN[i])
				ans++;
		cout << ans << endl;
		cin >> n;
	}
	
		
	return 0;
}
