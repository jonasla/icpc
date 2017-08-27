#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

map<char,tint> letra = {{'N',0},{'L',1},{'S',2},{'O',3}};

vector<pair<tint,tint> > movi = {{-1,0},{0,1},{1,0},{0,-1}};

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tint n,m,s;
  while (cin >> n >> m >> s && n != 0 && m != 0 && s != 0)
  {
    vector<string> tablero (n);
    pair<tint,tint> pos = {-1,-1}, movimientoActual = {-1,-1};
    tint indice = 0;
    forn(i,n)
    {
      cin >> tablero[i];
      forn(j,m)
      {
        if (tablero[i][j] == 'N' or tablero[i][j] == 'L' or tablero[i][j] == 'S' or tablero[i][j] == 'O')
        {
          pos = {i,j};
          indice = letra[tablero[i][j]];
          movimientoActual = movi[indice];
        }
      }
    }
    string s;
    cin >> s;
    tint cantidad = 0;
    for (auto x : s)
    {
      
      if (x == 'D')
        indice = (indice + 1) % 4;
      else if (x == 'E')
        indice = (indice + 3) % 4;
      else
      {
        movimientoActual = movi[indice];
        tint x = pos.first + movimientoActual.first;
        tint y = pos.second + movimientoActual.second;
        if (0 <= x && x < n && 0 <= y && y < m && tablero[x][y] != '#')
        {
          pos = {x,y};
          if (tablero[x][y] == '*')
          {
            cantidad++;
            tablero[x][y] = '.';
          }
        }
      }
    }
    cout << cantidad << "\n";
    
  }
}
