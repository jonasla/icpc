#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define forsn(i,s,n) for(int i=(int)s; i<(int)n; i++)
#define forn(i,n) forsn(i,0,n)

typedef vector<int> vi;


bool ganaOrden(vi &bueno, vi &malo) {
  int ganadas = 0;
  forn(i,3) {
    if (bueno[i] > malo[i]) ganadas++;
  }
  return ganadas >= 2;
}

bool ganaSiempre(vi &bueno, vi &malo) {
  bool gana = true;
  sort(bueno.begin(), bueno.end());
  sort(malo.begin(), malo.end());
  
  while(next_permutation(bueno.begin(),bueno.end())){
    while(next_permutation(malo.begin(),malo.end())){
      gana &= ganaOrden(bueno, malo);
    }
  }
  return gana;
}

int main() {
  int a, b, c, x, y;
  while(cin >> a >> b >> c >> x >> y && x > 0) {
    set<int> usadas;
    usadas.insert(a);
    usadas.insert(b);
    usadas.insert(c);
    usadas.insert(x);
    usadas.insert(y);
    
    bool gano = false;
    for(int i=1;i<=52;i++) {
      if (usadas.find(i) == usadas.end()) {
        vi malo = {a,b,c};
        vi bueno = {x,y,i};
        
        if (ganaSiempre(bueno,malo)) {
          cout << i << endl;
          gano = true;
          break;
        }
        
      }
    }
    if (!gano) cout << -1 << endl;
  }
  return 0;
}
