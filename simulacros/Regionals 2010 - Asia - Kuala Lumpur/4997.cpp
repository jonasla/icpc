#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <deque>

typedef long long tint;
#define forn(i,n) for(tint i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(tint i=s;i<(int)(n);i++)


using namespace std;

tint maxCruces = 75;

vector<tint> movimientoX = {0,1,-1,0,0};
vector<tint> movimientoY = {0,0,0,1,-1};

vector<tint> distancia2X = {-2,-2,-2,-1,-1,-1,-1,0,0,1,1,1,1,2,2,2};
vector<tint> distancia2Y = {-1,0,1,-2,-1,1,2,-2,2,-2,-1,1,2,-1,0,1};



struct Cruz
{
	tint fila,columna;
	char color;
	Cruz(tint ff, tint cc, char col)
	{
		fila = ff;
		columna = cc;
		color = col;
	}
};

bool operator < (Cruz c1, Cruz c2)
{
	return make_tuple (c1.fila, c1.columna, c1.color) < make_tuple(c2.fila,c2.columna,c2.color);
}

struct Respuesta
{
	vector<Cruz> cruces;
	bool sePuede;
	Respuesta (vector<Cruz> cc, bool ss)
	{
		cruces = cc;
		sePuede = ss;
	}
};

struct Arista
{
	tint c1, c2;
	Arista (tint cc1, tint cc2)
	{
		c1 = cc1;
		c2 = cc2;
	}
};

bool vecinosLibres (vector<string> &wall, tint i, tint j)
{

	bool tutti = true;
	forn(k,movimientoX.size())
		tutti &= wall[i+movimientoX[k]][j+movimientoY[k]] == '.';
	return tutti;	
	
}

void vecinos (vector<string> &wall, tint i, tint j,vector<Arista> &aristas, map<char,tint> &mapita)
{
	tint n = wall.size();
	map<char,bool> visitado = {{'A',true},{'.',true}};
	forn(k,distancia2X.size())
		if (i + distancia2X[k] >= 0 && i + distancia2X[k] < n && j + distancia2Y[k] >= 0 && j + distancia2Y[k] < n && !visitado[wall[i+distancia2X[k]][j+distancia2Y[k]]])
		{
			aristas.push_back(Arista(mapita[wall[i][j]],mapita[wall[i+distancia2X[k]][j+distancia2Y[k]]]));
			visitado[wall[i+distancia2X[k]][j+distancia2Y[k]]] = true;
		}
}

void pintar (vector<string> &wall, tint i, tint j, char color)
{
	forn(k,movimientoX.size())
		wall[i+movimientoX[k]][j+movimientoY[k]] = color;
}

void backTrack (vector<Cruz> &cruces, vector<vector<tint> > &ladj, tint verticesPintados, bool &sePuede, vector<Cruz> &solution) // Si se puede, devuelve True y ademas da un coloreo posible que se guarda en el campo color de cruces. Si no se puede da False.
{
	if (!sePuede)
	{
		tint m = cruces.size();
		if (cruces.empty() or verticesPintados == m)
		{
			solution = cruces;
			sePuede = true;
		}
		else
		{
			vector<char> colores = {'B','C','D'};
			forn(k,3)
			{
				bool flag = false;
				for (auto vecino : ladj[verticesPintados])
					if (colores[k] == cruces[vecino].color)
					{
						flag = true;
						break;
					}
				if (!flag)
				{
					cruces[verticesPintados].color = colores[k];
					verticesPintados++;
					backTrack(cruces,ladj,verticesPintados,sePuede,solution);
					verticesPintados--;
					cruces[verticesPintados].color = 'x';
				}
			}
		}
	}
}


int main()
{
	#ifdef ACMTUYO
	if (!freopen("entrada.in", "r", stdin))
		return 1;
	#endif
	map<char, tint> mapita;
	map<char, bool> prohibido = {{'.',true},{'A',true},{'B',true},{'C',true},{'D',true}};
	tint indy = 0;
	forn(k,maxCruces)
		if (!prohibido['0' + k])
		{
			mapita['0' + k] = indy;
			indy++;
		}
	tint tt;
	cin >> tt;
	forsn(test,1,tt+1)
	{
		tint n;
		cin >> n;
		vector<string> wall (n);
		forn(i,n)
			cin >> wall[i];
		
		vector<Cruz> cruces;
		vector<Arista> aristas;
		char cruzIndice = '0';
		forsn(i,1,n-1)
		forsn(j,1,n-1)
			if (vecinosLibres(wall,i,j))
			{
				while (prohibido[cruzIndice])
					cruzIndice++;
				pintar(wall,i,j,cruzIndice);
				cruces.push_back(Cruz(i,j,cruzIndice));
				vecinos(wall,i,j,aristas,mapita);
				cruzIndice++;
			}
		
		bool libreDePuntos = true;
		forn(i,n)
		forn(j,n)
			libreDePuntos &= (wall[i][j] != '.');
		vector<vector<tint> > ladj (cruces.size());
		for (auto a : aristas)
		{
			ladj[a.c1].push_back(a.c2);
			ladj[a.c2].push_back(a.c1);
		}
		forn(i,cruces.size())
			cruces[i].color = 'x';
		bool sePuede = false;
		vector<Cruz> solution;
		backTrack(cruces,ladj,0,sePuede,solution);
		if (sePuede && libreDePuntos)		
		{
			for (auto cruz : solution)
				pintar(wall,cruz.fila,cruz.columna,cruz.color);
				
			cout << "Case " << test << ":" << endl;
			forn(i,n)
				cout << wall[i] << endl;
		}
		else
			cout << "Case " << test << ": Not Possible!" << endl;
	}
	return 0;
}

