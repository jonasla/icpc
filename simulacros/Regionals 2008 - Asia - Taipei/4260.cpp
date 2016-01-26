#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <algorithm>

typedef long long tint;
#define forn(i,n) for(tint i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(tint i=s;i<(int)(n);i++)


using namespace std;

struct Carta // Notar que colapso cartas distintas, no tengo en cuenta el "Next Fortune Number", eso lo uso para definir las aristas.
{
	tint num;
	char sym;
	Carta(tint nn, char ss)
	{
		num = nn;
		sym = ss;
	}
	Carta() // Esto es solo para que compile.
	{
	}
};

struct Nodo
{
	Carta carta;
	tint pos; // Indica la posicion en el hechizo en la que se encuentra.
	Nodo (Carta cc, tint pp)
	{
		carta = cc;
		pos = pp;
	}
};

bool operator < (Carta c1, Carta c2) // Lo uso para poder meterlos en un map y laburar mas comodo.
{
	return make_tuple(c1.num,c1.sym) < make_tuple(c2.num,c2.sym);
}

bool operator < (Nodo n1, Nodo n2)
{
	return make_tuple(n1.carta,n1.pos) < make_tuple(n2.carta,n2.pos);
}

int main()
{
	tint n;
	cin >> n;
	forn(test,n)
	{
		tint c;
		cin >> c;
		map<Carta,vector<tint> > nextNumbers; // Para cada carta me voy a guardar a que numeros puedo llegar usandola.
		forn(i,c)
		{
			tint num,next;
			char sym;
			cin >> num >> sym >> next;
			nextNumbers[Carta(num,sym)].push_back(next);
		}
		string spell;
		cin >> spell;
		tint k = spell.size();
		// Inicializo la dinamica
		char symbol = spell[0];
		map<Nodo, tint> dp; // En cada Nodo guarda la mejor forma de llegar a ese nodo
		dp[Nodo(Carta(1,symbol),0)] = 0;
		set<Nodo> anteriores = {Nodo(Carta(1,symbol),0)};
		forsn(i,1,k)
		{
			set<Nodo> newAnteriores;
			symbol = spell[i];
			for(auto nodo : anteriores)
			for(auto proximo : nextNumbers[nodo.carta])
			{
				Nodo proximoNodo = Nodo(Carta(proximo,symbol),i);
				if (dp[proximoNodo] == 0)
					dp[proximoNodo] = proximo + dp[nodo];
				else
					dp[proximoNodo] = max(dp[proximoNodo],proximo + dp[nodo]);
				newAnteriores.insert(proximoNodo);
			}
			anteriores = newAnteriores;
		}
		vector<tint> ans;
		for(auto x : dp)
			if (x.first.pos == k-1 && !nextNumbers[x.first.carta].empty())
				ans.push_back(x.second + *max_element(nextNumbers[x.first.carta].begin(),nextNumbers[x.first.carta].end()));
		
		cout << *max_element(ans.begin(),ans.end()) << endl;
	}
	
	return 0;
}

