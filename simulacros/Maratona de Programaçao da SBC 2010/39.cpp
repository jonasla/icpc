#include <iostream>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tint n;
  while (cin >> n && n != 0)
  {
    forn(respuestas,n)
    {
      tint cantidad = 0, aparicion = -1;
      forn(i,5)
      {
        tint a;
        cin >> a;
        if (a <= 127)
        {
          cantidad ++;
          aparicion = i;
        }
      }
      if (cantidad == 1)
        cout << char('A'+aparicion) << "\n";
      else
        cout << "*\n";
    }
    
  }
  
}
