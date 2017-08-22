#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for(int i=0; i<(int)n; i++)

tint distancia (tint i, tint j)
{
  return min(abs(i-j), 24 - abs(i-j));
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tint n;
  while (cin >> n && n != 0)
  {
    vector<tint> t (n);
    forn(i,n)
      cin >> t[i];
    sort(t.begin(),t.end());
    tint ans = 1e15;
    forn(k,2)
    {
      tint r = 0;
      forn(i,n/2)
        r += distancia(t[(2*i+k)%n],t[(2*i+k+1)%n]);
      ans = min(ans,r);
    }
    cout << ans << "\n";
  }

}
