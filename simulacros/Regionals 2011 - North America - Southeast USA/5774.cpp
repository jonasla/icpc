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

struct Estado
{
	tint i,j,d; 
	bool moving;
	Estado (tint ii, tint jj, tint dd, bool mm)
	{
		i = ii;
		j = jj;
		d = dd;
		moving = mm;
	}
};

bool operator < (Estado e1, Estado e2)
{
	return make_tuple(e1.i,e1.j,e1.d) < make_tuple(e2.i,e2.j,e2.d);
}

map<char,tint> derecho = {{'N',0},{'S',1},{'W',2},{'E',3}};

vector<vector<tint> > movi = {{-1,0},{1,0},{0,-1},{0,1}}; // Arriba, abajo, izquierda, derecha

vector<vector<tint> > vecinos = {{0,2,3},{1,2,3},{0,1,2},{0,1,3}};

const tint INFINITO = 1e9;

tint dfs (vector<vector<vector<set<Estado> > > > &ladj, vector<vector<vector<tint> > > &ways, Estado actual)
{
	if (ways[actual.i][actual.j][actual.d] == 0)
		for (auto v : ladj[actual.i][actual.j][actual.d])
			ways[actual.i][actual.j][actual.d] += dfs(ladj,ways,v);
	return ways[actual.i][actual.j][actual.d];
}

int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint n,m;
	while (cin >> n >> m && n != 0)
	{
		vector<string> mapita (n);
		forn(i,n)
			cin >> mapita[i];
		Estado inicio = Estado(0,0,0,false);
		Estado endy = Estado(0,0,0,false);
		forn(i,n)
		forn(j,m)
		{
			if (mapita[i][j] != 'X' && mapita[i][j] != '.' && mapita[i][j] != '*')
				inicio = Estado(i,j,derecho[mapita[i][j]],false);
			else if (mapita[i][j] == 'X')
				endy = Estado(i,j,123,false);
		}
		
		
		vector<vector<vector<tint> > > distancia(n, vector<vector<tint> > (m, vector<tint> (4,INFINITO)));
		vector<vector<vector<set<Estado> > > > ladj(n, vector<vector<set<Estado> > > (m, vector<set<Estado> > (4)));
		
	
		deque<Estado> q = {inicio};
		deque<Estado> newQ;
		distancia[inicio.i][inicio.j][inicio.d] = 0;
		
		
		
		
		while (!q.empty())
		{
			Estado actual = q.front();
			q.pop_front();
			for (auto v : vecinos[actual.d])
			{
				Estado vecino = Estado(0,0,0,false);
				if (v == actual.d)
					vecino = Estado(actual.i+movi[v][0],actual.j+movi[v][1],v,true);
				else
					vecino = Estado(actual.i,actual.j,v,false);
				if (0 <= vecino.i && vecino.i < n && 0 <= vecino.j && vecino.j < m && mapita[vecino.i][vecino.j] != '*')
				{
					if (vecino.d == actual.d && actual.moving && distancia[actual.i][actual.j][actual.d] <= distancia[vecino.i][vecino.j][vecino.d])
					{
						q.push_front(vecino);
						distancia[vecino.i][vecino.j][vecino.d] = distancia[actual.i][actual.j][actual.d];
						if (vecino.d == actual.d && actual.moving && distancia[actual.i][actual.j][actual.d] < distancia[vecino.i][vecino.j][vecino.d])
							ladj[vecino.i][vecino.j][vecino.d] = {actual};
						else
							ladj[vecino.i][vecino.j][vecino.d].insert(actual);
					}	
					if (distancia[actual.i][actual.j][actual.d] + 1 <= distancia[vecino.i][vecino.j][vecino.d])
					{
						
						distancia[vecino.i][vecino.j][vecino.d] = distancia[actual.i][actual.j][actual.d] + 1;
						newQ.push_back(vecino);
						if (distancia[actual.i][actual.j][actual.d] + 1 == distancia[vecino.i][vecino.j][vecino.d])
							ladj[vecino.i][vecino.j][vecino.d].insert(actual);
						else
							ladj[vecino.i][vecino.j][vecino.d] = {actual};
					}
						
				}
			}
			if (q.empty())
			{
				q = newQ;
				newQ = {};
			}
		}
		
		tint ans = INFINITO;
		vector<tint> dir;
		forn(k,4)
		{
			if (distancia[endy.i][endy.j][k] < ans)
			{
				dir = {k};
				ans = distancia[endy.i][endy.j][k];
			}
			else if (ans == distancia[endy.i][endy.j][k])
				dir.push_back(k);
		}
		if (ans == INFINITO)
			cout << "0 0\n";
		else
		{
			vector<vector<vector<tint> > >	ways(n, vector<vector<tint> > (m, vector<tint> (4,0)));
			ways[inicio.i][inicio.j][inicio.d] = 1;
			tint num = 0;
			for (auto r : dir)
			{
				endy.d = r;
				num += dfs(ladj,ways,endy);
			}
			cout << ans << " " << num << "\n";
		}
	
		
		
		
		
		
		
		
				
	}
	return 0;
}



