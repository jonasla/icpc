#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>

using namespace std;

typedef int tint;

#define forsn(i,s,n) for (tint i = (tint)s; i < (tint)(n); i++)
#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)


const tint zero = 1 << 14;
const tint maxF = 1 << 15;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tint n,f;
  while (cin >> n >> f && n != 0 && f != 0)
  {
    string ans (n,'.');
    vector<tint> a (n);
    forn(i,n)
      cin >> a[i];
    
    bitset<maxF> vacio;
    forn(i,n)
    {
      bitset<maxF> positivo1;
      bitset<maxF> negativo1;
      bitset<maxF> positivo2;
      bitset<maxF> negativo2;
      positivo1[zero+a[i]] = 1;
      negativo1[zero-a[i]] = 1;
      forn(j,n)
      {
        if (i != j)
        {
          forn(k,maxF)
          {
            if (positivo1[k] && 0 <= k + a[j] && k + a[j] < maxF)
              positivo2[k+a[j]] = 1;
            if (positivo1[k] && 0 <= k - a[j] && k - a[j] < maxF)
              positivo2[k-a[j]] = 1;
            if (negativo1[k] && 0 <= k + a[j] && k + a[j] < maxF)
              negativo2[k+a[j]] = 1;
            if (negativo1[k] && 0 <= k - a[j] && k - a[j] < maxF)
              negativo2[k-a[j]] = 1;
          }
        }
        cout << positivo2.count() << " " << negativo2.count() << endl;
        positivo1 &= vacio;
        positivo1 |= positivo2;
        negativo1 &= vacio;
        negativo1 |= negativo2;
        positivo2 &= vacio;
        negativo2 &= vacio;
      }
      if (positivo1[zero+f] && negativo1[zero+f])
        ans[i] = '?';
      else if (positivo1[zero+f] && negativo1[zero+f])
        ans[i] = '+';
      else if (positivo1[zero+f] && negativo1[zero+f])
        ans[i] = '-';
      else
      {
        ans = '*';
        break;
      }
    }
    cout << ans << "\n";
  }
}
