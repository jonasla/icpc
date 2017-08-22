#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forsn(i,s,n) for(tint i=(tint)s; i<(tint)n; i++)
#define forn(i,n) forsn(i,0,n)

tint LIS(vi& v) {
  if (v.empty()) return 0;
  
  tint l = 0;             // ultimo lugar de tails hasta ahora
  vi tails(v.size(), 0);  // candidatos de final de sub secuencias
  tails[l] = v[0];
  
  forsn(i,1,v.size()) {
    // con upper_bound es no-decreciente
    tint me = lower_bound(tails.begin(), tails.begin() + l + 1, v[i]) - tails.begin();
    tails[me] = v[i];
    if (me > l) l = me;
  }
  return l + 1;
}

int main() {
  vi v;
  v = vi{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
  cout << LIS(v) << endl;
  v = vi{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  cout << LIS(v) << endl;
  v = vi{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  cout << LIS(v) << endl;
  v = vi{ 1, 1, 3, 4, 5, 6, 7, 8, 9};
  cout << LIS(v) << endl;
  
  return 0;
}
