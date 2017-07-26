#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

void f (vector<vector<tint> > &m, tint fila, tint columna, tint h, tint &maxH, tint &suma)
{
	if (m[fila][columna] != 0)
	{
		suma += h;
		maxH = max(maxH,h);
		tint izquierda = 0,derecha = 0, n = m.size();
		for (tint c = columna; columna >= 0; c--)
		{
			if (m[fila][c] != m[fila][columna])
			{
				izquierda = c;
				break;
			}
		}
		for (tint r = fila; r < n; r++)
		{
			if (m[r][columna] != m[fila][columna])
			{
				derecha = r;
				break;
			}
		}	
		f(m,fila,izquierda,h+1,maxH,suma);
		f(m,derecha,columna,h+1,maxH,suma);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n, caso = 1;
	while (cin >> n && n != -1)
	{
		vector<vector<tint> > matrixOfRoots (n, vector<tint> (n));
		forn(i,n)
		forn(j,n)
			cin >> matrixOfRoots[i][j];
			
		tint maxH = 1, suma = 0, h = 1;
		f(matrixOfRoots,0,n-1,h,maxH,suma);
		
		cout << "Case " << caso++ << ":\n";
		cout << "The height of the BST is: " << maxH << "\n";
		cout << "The average of the search in the BST is: " << fixed << showpoint << setprecision(2) << ldouble(suma) / ldouble(n-1) << "\n";
	}
	return 0;
}
