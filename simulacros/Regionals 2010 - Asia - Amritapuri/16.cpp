#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (tint)(s); i < (tint)(n); i++)

struct Estado
{
	tint suma,producto,chico;
	Estado(tint ss, tint pp, tint cc)
	{
		suma = ss;
		producto = pp;
		chico = cc;
	}
	Estado()
	{
		suma = 0;
		producto = 1;
		chico = 70;
	}
};

unordered_set<tint> solutions;
set<Estado> visitado;
tint m;

bool operator < (Estado e1, Estado e2)
{
	return make_tuple(e1.suma,e1.producto,e1.chico) < make_tuple(e2.suma,e2.producto,e2.chico);
}

void backTrack(tint s, tint p, tint q)
{
	if (visitado.find(Estado(s,p,q)) == visitado.end())
	{
		visitado.insert(Estado(s,p,q));
		if (s == 0)
			solutions.insert(p);
		else
			forsn(i,1,min(s,q)+1)
				backTrack(s-i,(p*i)%m,i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint t;
	cin >> t;
	forn(caso,t)
	{
		tint n;
		cin >> n >> m;
		solutions.clear();
		visitado.clear();
		backTrack(n,1,n);
		cout << solutions.size() << "\n";
	}
	
	return 0;
}
