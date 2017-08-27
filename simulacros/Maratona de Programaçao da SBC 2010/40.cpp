#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

typedef long long tint;

#define forsn(i,s,n) for (tint i = (tint)s; i < (tint)(n); i++)
#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tint n;
  while (cin >> n && n != 0)
  {
    string s;
    cin >> s;
    tint last = 0, i = 0;
    bool empiezaEnCruz = (s[0] == 'X'), terminaEnCruz = (s[n-1] == 'X');
    vector<tint> espacios;
    bool ganaPrimero = true, termino = false;
    while (i < n && s[last] == s[i])
    {
      tint avance = 0;
      while (last < n && s[last] == 'X')
      {
        last++;
        avance++;
      }
      termino |= avance >= 2;
      i = last;
      while (i < n && s[i] == '.')
        i++;
      espacios.push_back(i-last);
      if (i-last <= 1 && last > 0 && i != n)
        termino = true;
      last = i;
    }
    //cout << empiezaEnCruz << " " << terminaEnCruz << endl;
    //cout << termino << " " << ganaPrimero << endl;
    for (auto x : espacios)
      cout << x << endl;
    tint m = espacios.size(), espaciosGanadores = 0;
    if (m == 1 && !empiezaEnCruz && !terminaEnCruz)
      espaciosGanadores += (espacios[0] != 6);
    else
    {
      forn(j,m)
      {
        if ((j == 0 && empiezaEnCruz) || (j == m-1 && terminaEnCruz))
        {
          if (j == 0 && empiezaEnCruz)
            espaciosGanadores += ((espacios[j] != 8) && (espacios[j] != 2) && (espacios[j] != 1));
          if (j == m-1 && terminaEnCruz)
            espaciosGanadores += ((espacios[j] != 8) && (espacios[j] != 2) && (espacios[j] != 1));
        }
        else
          espaciosGanadores += ((espacios[j] != 2) && (espacios[j] != 3) && (espacios[j] != 4) && (espacios[j] != 10));
      }
    }
    
    ganaPrimero &= (termino || (espaciosGanadores % 2));

    if (ganaPrimero)
      cout << "S\n";
    else
      cout << "N\n";
    //cout << "-----" << endl;  

    
  }
  return 0;
}
  
