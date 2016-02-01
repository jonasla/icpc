#include <iostream>
#include <vector>
#include <algorithm>


#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=s;i<(int)(n);i++)

using namespace std;

int mX[4] = {1,-1,0,0};
int mY[4] = {0,0,1,-1};

int aux[2][5] = {{'L',1,-1,0,1},{'V',-1,1,1,-1}}; // coloca y descoloca.

int ap[2][2] = {{1,1},{-1,0}}; // enciendo, apago.
int mA[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; // abajo, arriba, derecha, izquierda.

// Tipo:
// 'L' -> Lampara
// 'B' -> Barrera
// 'V' -> Casilla Vacia

// iluminan -> cantidad de lamparas que iluminan la casilla
// 		{ -1 -> Cualquier cantidad de lamparas vecinas esta bien
// adj 	{  0 -> No debe tener lamparas vecinas.
//		{ ...
//		{  4 -> Debe tener 4 lamparas vecinas.

struct Casilla
{
	int iluminan,adj;
	char tipo;
	Casilla (char tt,int ii, int aa)
	{
		tipo = tt;
		iluminan = ii;
		adj = aa;
	}
};



bool colocarLampara(vector<vector<Casilla> > &tablero, int i, int j, int &luces, int &completas, int d)	// si d = 0 coloca, si d = 1 descoloca.
{
	int n = tablero.size(), m = tablero[0].size();
	bool noArruinaAdyacencia = true;
	tablero[i][j].tipo = aux[d][0];
	luces+= aux[d][1];
	forn(k,4)
	{
		int x = i + mX[k], y = j + mY[k];
		if (x >= 0 && x < n && y >= 0 && y < m) // si la casilla vecina esta en el tablero
		{
			tablero[x][y].adj+= aux[d][2];
			if (tablero[x][y].adj == -1)
				noArruinaAdyacencia = false;
			if ( tablero[x][y].tipo == 'B' && tablero[x][y].adj == aux[d][3]) 
				completas+= aux[d][4];
		}
	}
	return noArruinaAdyacencia;
	
}


bool enciendeLampara(vector<vector<Casilla> > &tablero, int i, int j, int &iluminadas, int a)	 // si a = 0 enciende, si a = 1 apaga.
{
	// Encendemos la lampara, actualizamos lo que ilumina y lo deshacemos si amenaza otra lampara
	int n = tablero.size(), m = tablero[0].size();
	bool noAmenazaLampara = true;

	tablero[i][j].iluminan += ap[a][0];
	if (tablero[i][j].iluminan == ap[a][1])
		iluminadas += ap[a][0];
	forn(p,4)
	{
		int d = 1;
		int x = i + mA[p][0]*d, y = j + mA[p][1]*d;
		while (x >= 0 && x < n && y >= 0 && y < m && tablero[x][y].tipo != 'B')
		{
			if (tablero[x][y].tipo == 'L')
				noAmenazaLampara = false;
			tablero[x][y].iluminan += ap[a][0];
			if (tablero[x][y].iluminan == ap[a][1])
				iluminadas += ap[a][0];
			d++;
			x = i + mA[p][0]*d;
			y = j + mA[p][1]*d;
		}
	}
	return noAmenazaLampara;
}

void backTrack (vector<vector<Casilla> > &tablero, int &luces, int &vacias, int &iluminadas, int &completas, int desdeI, int desdeJ, int &bestAnswer)
{
	int n = tablero.size(), m = tablero[0].size();
	
	if (luces < bestAnswer)
	{
		forsn(i,desdeI,n)
		forsn(j,desdeJ,m)
		{
			if (j == m-1)
				desdeJ = 0;
			if (tablero[i][j].tipo == 'V' && tablero[i][j].iluminan == 0) 
			{
				if (colocarLampara(tablero,i,j,luces,completas,0) && luces < bestAnswer)
				{
					if (enciendeLampara(tablero,i,j,iluminadas,0))
					{
						if (iluminadas != vacias or completas != (n*m - vacias))  // b = n*m-vacias, porque vacias = (n*m-b)
							backTrack(tablero,luces,vacias,iluminadas,completas,i,j,bestAnswer);
						else 
							bestAnswer = luces;
					}
					enciendeLampara(tablero,i,j,iluminadas,1);
				}
				colocarLampara(tablero,i,j,luces,completas,1);
			}
		}
	}
		
		
}

// Esto imprime el tablero en la posicion actual, util si hay que debuguear
//forn(i,n)
//{
//	forn(j,m)
//		cout << "(" << tablero[i][j].tipo << ", " << tablero[i][j].iluminan << ", " << tablero[i][j].adj << ") ";
//	cout << endl;
//}
//cout <<  "---------------------" << endl;


int main()
{
	#ifdef ACMTUYO
	if (!freopen("entrada.in", "r", stdin))
		return 1;
	#endif
	int n,m;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		int b,completas = 0; 
		cin >> b;
		vector<vector<Casilla> > tablero (n, vector<Casilla> (m,Casilla('V',0,-1))); // Al principio esta todo el tablero vacio
		forn(i,b)
		{
			int r,c,k;
			cin >> r >> c >> k;
			tablero[r-1][c-1] = Casilla('B',0,k);
			if (k <= 0)
				completas++;
		}
		int luces = 0, vacias = n*m-b,iluminadas = 0, bestAnswer = 50;
		backTrack(tablero,luces,vacias,iluminadas,completas,0,0,bestAnswer); // Encuentra todas las soluciones que usan al menos una lampara
		if (completas == n*m)
			cout << 0 << endl;
		else if (bestAnswer == 50)
			cout << "No solution" << endl;
		else
			cout << bestAnswer << endl;
	}
	return 0;
}
