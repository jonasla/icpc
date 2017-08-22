#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for(int i=0; i<(int)n; i++)

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tint a,b;
  while (cin >> a >> b)
  {
    string s;
    cin >> s;
    vector<pair<tint,tint> > negras;
    tint blancasPasadas = 0, p = s.size();
    forn(i,p)
    {
      if (s[i] == 'W')
        blancasPasadas++;
      else
        negras.push_back({blancasPasadas,i});
    }
    tint ans = 0, n = negras.size(), blancas = 0;
    pair<tint,tint> vivas = {n-1,0};
    reverse (negras.begin(),negras.end());
    forn(i,n)
    {
      while (vivas.second < p && s[vivas.second] == 'B')
      {
        vivas.second++;
        vivas.first--;
      }
      if (vivas.second < negras[i].second)
      {
        tint r = (negras[i].first-blancas+vivas.first)*(a-b) - a;
        //cout << vivas.first << " " << vivas.second << negras[i].first << endl;
        //cout << r << " " << ans << endl;
        //cout << endl;
        if (r >= 0)
        {
          ans += a; 
          vivas.second++;
          vivas.first--;
          blancas++;
        }
        else
          ans += (negras[i].first-blancas)*(a-b);
      }
      
    }
    cout << ans << "\n";
  }
}
