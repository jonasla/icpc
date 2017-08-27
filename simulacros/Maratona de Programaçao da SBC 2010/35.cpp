#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forsn(i,s,n) for (tint i = (tint)s; i < (tint)(n); i++)
#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);

  tint G, Q;
  while(cin >> G >> Q && G != 0) {
    vector<vi> ordenes(G, vi(Q));
    forn(i,G)
    forn(j,Q) {
      cin >> ordenes[i][j]; 
      //ordenes[i][j]--;
    }
    //
    tint S; cin >> S;
    vector<vi> puntajes(S);
    tint K;
    tint p; 
    forn(i,S) {
      cin >> K;
      puntajes[i] = vi(K);
      forn(j,K) {
        cin >> p; 
        puntajes[i][j] = p;
      }
    }
    //
    //
    for(auto punts : puntajes) {
      vi puntos(Q, 0);
      for(auto ord : ordenes) {
        forn(i,ord.size()) {
          if (ord[i] <= (tint)punts.size()) {
            puntos[i] += punts[ord[i]-1];
          }
        }
      }
      tint MAXP = *max_element(puntos.begin(), puntos.end());
      set<pair<tint,tint> > elset;
      forn(i,Q) elset.insert(make_pair(puntos[i], i));
      auto it = elset.rbegin();
      vi winners;
      while(it != elset.rend() && it->first == MAXP) {
        winners.push_back(it->second+1);
        it++;
      }
      sort(winners.begin(), winners.end());
      forn(i,winners.size()) {
        if (i) cout << " ";
        cout << winners[i];
      }
      cout << "\n";
    }
  }
  return 0;
}
