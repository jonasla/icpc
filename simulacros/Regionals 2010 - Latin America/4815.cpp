#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

#define forsn(i,s,n) for(tint i=(tint)s; i<(tint)n; i++)
#define forn(i,n) forsn(i,0,n)

typedef long long tint;
typedef vector<tint> vi;
typedef pair<tint, tint> ii;
typedef vector<ii> vii;

tint K, W;

void addAdj(unordered_map<tint, unordered_set<tint> > &g, tint u, tint v) {
  g[u].insert(v);
}

int main() {
  while(cin >> K >> W && K > 0) {
    unordered_map<tint, unordered_set<tint> > graf;
    forn(i,W) {
      tint u, v; cin >> u >> v;
      addAdj(graf, u, v);
      addAdj(graf, v, u);
    }
    ///
    bool possible = true;
    for (auto v : graf) {
      possible &= (v.second.size() <= 2);
    }
    if (!possible) {
      cout << "N\n";
      continue;
    }
    /// bfs
    unordered_map<tint, tint> preds;
    unordered_set<tint> visit;
    queue<tint> Q;
    
    for (auto &i : graf) {
      if (visit.find(i.first) != visit.end()) continue;
      
      tint size_ciclo = 0;
      bool ciclo = false;
      Q.push(i.first);
      preds[i.first] = -1;
      visit.insert(i.first);
      size_ciclo++;
      while(!Q.empty()) {
        tint v = Q.front(); Q.pop();
        for (auto ady : graf[v]) {
          // nuevo nodo
          if (visit.find(ady) == visit.end()) {
           Q.push(ady);
           preds[ady] = v;
           visit.insert(ady);
           size_ciclo++;
          // ciclo !
          } else if (ady != preds[v]) {
            ciclo = true;
          }
        }
      }
      if (ciclo && size_ciclo != K) possible = false;
    }
    
    if (possible)
      cout << "Y\n";
    else 
      cout << "N\n";
    
  }
  return 0;
}
