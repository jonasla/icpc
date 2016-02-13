#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <utility>

using namespace std;

#define forsn(i,s,n) for (int i = (s); i <(int) (n); i++)
#define forn(i,n) for (int i = 0; i <(int) (n); i++)

struct Casilla
{
	int num,flecha,comodin;
	Casilla(int nn, int ff, int cc)
	{
		num = nn;
		flecha = ff;
		comodin = cc;
	}
};

const int aux[2][4] = {{0,-1,0,0},{1,0,-1,1}};
const int cota = 2000;

int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in","r",stdin));
	#endif
	int n;
	while (cin >> n)
	{
		map<char,char> conjugado = {{'o','o'},{'v','v'},{'w','w'},{'x','x'},{'p','q'},{'q','p'},{'d','b'},{'b','d'}};
		vector<string> s (3, string (n,'.')); // s[0] = string original, s[1] = string mutado, s[2] = string buscado
		cin >> s[0] >> s[2];
		forn(i,n)
			s[1][i] = conjugado[s[0][n-i-1]]; 
		vector<vector<Casilla> > dp (n+1,vector<Casilla> (n+1,Casilla(cota,1,0))); // cota hace de infinito, pues es cota superior de la solucion. 0 es flecha para abajo, 1 es flecha para la derecha. El comodin esta apagado
		dp[0][0] = Casilla(0,0,0);
		forsn(k,1,n+1) // por cada diagonal (si k es la diagonal, k-1 indica el indice de la posicion de la respuesta que deseamos)
		{
			int i = 0, j = k;
			while (j >= 0)
			{
				forn(p,2) // miramos los dos vecinos anteriores (arriba e izquierda si existen) 
				{
					int sp = aux[p][0], cp = i*(1-p)+j*p, ip = aux[p][1], jp = aux[p][2], fp = aux[p][3]; // string que tocamos, indice en dicho string, movimiento en i, movimiento en j, flechita buena
					if (cp > 0 && s[2][k-1] == s[sp][cp-1]) // Si no me fui de rango y me sirve para armar la palabra
					{
						Casilla ant = dp[i+ip][j+jp];
						dp[i][j] = Casilla(min(dp[i][j].num,ant.num + min(int(ant.flecha != fp), 1-ant.comodin)), fp, dp[i][j].comodin + (dp[i][j].num == ant.num)); // Magia negra de la China
					}
				}
				dp[i][j].comodin = int(dp[i][j].comodin >= 2); // Magia negra de la India
				i++;j--;
			}
		}
		int ans = cota, i = 0, j = n;
		while (j >= 0)
		{
			ans = min(ans,dp[i][j].num);
			i++;j--;
		}
		if (ans == cota)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
