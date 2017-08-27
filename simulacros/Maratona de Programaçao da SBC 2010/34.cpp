#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tint l,c,r1,r2;
  while (cin >> l >> c >> r1 >> r2 && l != 0 && c != 0 && r1 != 0 && r2 != 0)
  {
    bool sePuede = true;
    sePuede &= (2*r1) <= l;
    sePuede &= (2*r1) <= c;
    sePuede &= (2*r2) <= l;
    sePuede &= (2*r2) <= c;
    //cout << 2*r1 << " " << 2*r2 << " " << l << " " << c << endl;
    pair<tint,tint> o1 = {r1,r1};
    pair<tint,tint> o2 = {c-r2,l-r2};
    //cout << o1.first << " " << o2.first << endl;
    //cout << o1.second << " " << o2.second << endl;
    tint distancia = abs(o1.first-o2.first)*abs(o1.first-o2.first) + abs(o1.second-o2.second)*abs(o1.second-o2.second);
    //cout << distancia << " " << (r1+r2)*(r1+r2) << endl; 
    sePuede &= (distancia >= (r1+r2)*(r1+r2));
    if (sePuede)
      cout << "S\n";
    else
      cout << "N\n";
     
  }
  
  return 0;
}
