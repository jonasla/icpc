#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)

typedef long long tint;

class UF {
private: vector<int> p, rank; int comps;
public: 
  UF(int N) {
    rank.assign(N, 0); comps = N;
    p.assign(N, 0); forn(i,N) p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool sameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!sameSet(i,j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) p[y] = x;
      else { 
        p[x] = y; 
        if (rank[x] == rank[y]) rank[y]++;
      }
      comps--;
    }
  }
  int components() { return comps; }
};

struct Arista {
  tint peso, start, end;
  Arista(tint s, tint e, tint p) : peso(p), start(s), end(e) {}
  bool operator<(const Arista& o) const {
    return make_tuple(peso, start, end) < make_tuple(o.peso, o.start, o.end);
  }
};

// Devuelve el peso del AGM, y en 'agm' deja las aristas del mismo. 
tint kruskal(vector<Arista> &ars, tint size, vector<Arista> &agm) {
  sort(ars.begin(), ars.end());
  tint min_peso = 0;
  UF uf(size);
  for(auto &a : ars) {
    if (!uf.sameSet(a.start, a.end)) {
      min_peso += a.peso;
      uf.unionSet(a.start, a.end);
      agm.push_back(a);
      // Esto es que el AGM ya tiene V-1 aristas. 
      if ((tint)agm.size() == size-1) break;
    }
  }
  return min_peso;
}

int main() {
  return 0;
}
