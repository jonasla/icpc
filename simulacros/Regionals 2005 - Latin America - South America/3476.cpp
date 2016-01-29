#include <iostream>
#include <vector>
#include <algorithm>


#define forn(i,n) for(tint i=0;i<(tint)(n);i++)
#define forsn(i,s,n) for(tint i=s;i<(tint)(n);i++)

typedef long long tint;

using namespace std;

vector<tint> mX = {1,-1,0,0};
vector<tint> mY = {0,0,1,-1};

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
	tint iluminan,adj;
	char tipo;
	Casilla (char tt,tint ii, tint aa)
	{
		tipo = tt;
		iluminan = ii;
		adj = aa;
	}
};



// ponerLampara == 0 -> puse la lampara y todo sigue valido, ponerLampara == 1 -> puse la lampara y amenace otra lampara, ponerLampara 2-> puse la lampara y cague la vecindad de una barrera.
// 0 -> actualiza el tablero, 1 y 2 -> dejan el tablero en su estado original
// tablero[i][j].tipo == 'V' antes de llamar a poner lampara, sino estoy mandando alta fruta.

tint ponerLampara(vector<vector<Casilla> > &tablero, tint i, tint j)	// En esta funcion pasa toda la magia
{
	tint n = tablero.size(), m = tablero[0].size(), ans = 0;
	// Colocamos la lampara y chequeamos las barreras en las casillas vecinas
	forn(k,mX.size())
	{
		if (i + mX[k] >= 0 && i + mX[k] < n && j + mY[k] >= 0 && j + mY[k] < m && tablero[i+mX[k]][j+mY[k]].tipo == 'B') // si la casilla vecina esta en el tablero y es barrera. 
		{
			if (tablero[i+mX[k]][j+mY[k]].adj == 0) // Si NO se le puede agregar una lampara vecina
				ans = 2;
			tablero[i+mX[k]][j+mY[k]].adj--;
		}
	}
	if (ans == 2)
	{
		forn(k,mX.size())
		if (i + mX[k] >= 0 && i + mX[k] < n && j + mY[k] >= 0 && j + mY[k] < m && tablero[i+mX[k]][j+mY[k]].tipo == 'B')
			tablero[i+mX[k]][j+mY[k]].adj++;
	}
	// Encendemos la lampara, actualizamos lo que ilumina y lo deshacemos si amenaza otra lampara
	vector<vector<tint> > movimientoAuxiliar = {{1,n,1,0,1,i},{-1,n,-1,0,1,i},{1,m,1,1,1,j},{-1,m,-1,1,1,j},{1,n,1,0,-1,i},{-1,n,-1,0,-1,i},{1,m,1,1,-1,j},{-1,m,-1,1,-1,j}}; // Para abajo, Para arriba, Para la derecha, Para la izquierda. Las primeras 4 encienden, Las segundas 4 apagan
	if (ans == 0)
	{
		tablero[i][j] = Casilla('L',tablero[i][j].iluminan + 1, -1);	
		forn(p,movimientoAuxiliar.size())
		{
			if (p > 3 && ans == 0) // Si encendimos la lampara y no hubo problemas, no la apagues.
				break;
			else if (p == 4 && ans == 1)  // Si hay que quitarla, primero la descolocamos (notar que solo se ejecuta una vez)
			{
				tablero[i][j] = Casilla('V',tablero[i][j].iluminan - 1, -1);
				forn(k,mX.size())
					if (i + mX[k] >= 0 && i + mX[k] < n && j + mY[k] >= 0 && j + mY[k] < m && tablero[i+mX[k]][j+mY[k]].tipo == 'B' )
						tablero[i+mX[k]][j+mY[k]].adj++;	
			}
			vector<tint> x = movimientoAuxiliar[p];
			for (tint k = x[5] +x[0]; 0 <= k && k < x[1]; k += x[2]) 
			{
				if (tablero[i*x[3] + k*(1-x[3])][j*(1-x[3])+k*x[3]].tipo == 'L')
				{
					ans = 1;
					break;
				}
				else if (tablero[i*x[3] + k*(1-x[3])][j*(1-x[3])+k*x[3]].tipo == 'B' )
					break;
				else
					tablero[i*x[3] + k*(1-x[3])][j*(1-x[3])+k*x[3]].iluminan += x[4];
			}
		}
	}
	return ans;
}

void sacarLampara(vector<vector<Casilla> > &tablero, tint i, tint j)	// Al llamarla ya tiene que existir lampara en (i,j), sino la cagamos.
{
	tint n = tablero.size(), m = tablero[0].size();
	// Sacamos la lampara y actualizmos la adyacencia a vecinos
	tablero[i][j] = Casilla('V',tablero[i][j].iluminan - 1, -1);	
	forn(k,mX.size())
		if (i + mX[k] >= 0 && i + mX[k] < n && j + mY[k] >= 0 && j + mY[k] < m && tablero[i+mX[k]][j+mY[k]].tipo == 'B' )
			tablero[i+mX[k]][j+mY[k]].adj++;
	
	// Apagamos la lampara, actualizamos lo que deja de iluminar
	vector<vector<tint> > movimientoAuxiliar = {{1,n,1,0,-1,i},{-1,n,-1,0,-1,i},{1,m,1,1,-1,j},{-1,m,-1,1,-1,j}}; // Para abajo, Para arriba, Para la derecha, Para la izquierda. Ahora las 4 apagan
	
	forn(p,movimientoAuxiliar.size())
	{
		vector<tint> x = movimientoAuxiliar[p];
		for (tint k = x[5] +x[0]; 0 <= k && k < x[1]; k += x[2]) 
		{
			if (tablero[i*x[3] + k*(1-x[3])][j*(1-x[3])+k*x[3]].tipo == 'B' )
				break;
			else
				tablero[i*x[3] + k*(1-x[3])][j*(1-x[3])+k*x[3]].iluminan += x[4];
		}
	}
}

bool chequeo (vector<vector<Casilla> > &tablero, vector<tint> &ans)
{
	tint n = tablero.size(), m = tablero[0].size(), q = 0;
	//forn(i,n)
	//{
	//	forn(j,m)
	//		cout << "(" << tablero[i][j].tipo << ", " << tablero[i][j].iluminan << ", " << tablero[i][j].adj << ") ";
	//	cout << endl;
	//}
	//cout <<  "---------------------" << endl;
	bool risposta = true;
	forn(i,n)
	forn(j,m)
	{
		if (tablero[i][j].tipo == 'V')
			risposta &= (tablero[i][j].iluminan > 0);
		else if (tablero[i][j].tipo == 'L')
		{
			risposta &= (tablero[i][j].iluminan > 0);
			q++;
		}
		else // if (tablero[i][j] == 'B')
			risposta &= (tablero[i][j].adj <= 0);		
	}
	//if (q == 8)
	//	cout << "#######################" << endl;
	if (risposta)
		ans.push_back(q);
	return risposta;
}

void backTrack (vector<vector<Casilla> > &tablero, vector<tint> &ans)
{
	tint n = tablero.size(), m = tablero[0].size();
	forn(i,n)
	forn(j,m)
		if (tablero[i][j].tipo == 'V' && tablero[i][j].iluminan == 0 && ponerLampara(tablero,i,j) == 0)
		{
			if (!chequeo(tablero,ans))
				backTrack(tablero,ans);
			sacarLampara(tablero,i,j);
		}
		
		
}

int main()
{
	#ifdef ACMTUYO
	if (!freopen("entrada.in", "r", stdin))
		return 1;
	#endif
	tint n,m;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		tint b; 
		cin >> b;
		vector<vector<Casilla> > tablero (n, vector<Casilla> (m,Casilla('V',0,-1))); // Al principio esta todo el tablero vacio
		forn(i,b)
		{
			tint r,c,k;
			cin >> r >> c >> k;
			tablero[r-1][c-1] = Casilla('B',0,k);
		}
		vector<tint> ans;
		chequeo(tablero,ans);
		backTrack(tablero,ans);
		if (ans.empty())
			cout << "No solution" << endl;
		else
			cout << *min_element(ans.begin(),ans.end()) << endl;
		
	}
	return 0;
}
