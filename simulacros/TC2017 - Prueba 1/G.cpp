#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;
typedef pair<tint, tint> ii;
typedef vector<ii> vii;

#define forn(i,n) for (tint i = 0; i < (tint) n; i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint) n; i++)

const tint maxN = 310;

class UF {
  private:
    vi _p, _rank;
    tint _comps;
    
  public:
    UF() { _comps = 0; }
    
    tint comps() { return _comps; }
    tint findSet(tint i) { return (_p[i] == i) ? i : (_p[i] = findSet(_p[i])); }
    bool sameSet(tint i, tint j) { return findSet(i) == findSet(j); }
    void unionSet(tint i, tint j) {
      if (!sameSet(i,j)) {
        _comps--;
        tint x = findSet(i), y = findSet(j);
        if (_rank[x] > _rank[y]) _p[y] = x;
        else {
          _p[x] = y;
          if (_rank[x] == _rank[y]) _rank[y]++;
        }
      }
    }
    
    tint addNode() {
      tint newNode = _p.size();
      _p.push_back(newNode);
      _rank.push_back(0);
      _comps++;
      return newNode;
    }
};

tint dx[] = {0, 0, 1,-1};
tint dy[] = {1,-1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
	cin.tie(NULL);
  
  tint N, M;
  while(cin >> N >> M) {
    map<tint, vii> byHeight;
    
    forn(i,N)
    forn(j,M) {
      tint h; cin >> h;
      byHeight[h].push_back({i,j});
    }
    ///
    tint T; cin >> T;
    vi years(T); forn(i,T) cin >> years[i];
    reverse(years.begin(), years.end());
    vi sols;
    
    UF uf;
    map<ii, tint> toNode;
        
    auto itH = byHeight.rbegin();
    for(auto y : years) {
      //cout << "anio " << y << endl;
      while(itH->first > y && itH != byHeight.rend()){
        //cout << "agregando altura " << itH->first << endl;
        // primero agrego todas las tierras nuevas
        for (auto pos : itH->second) {
          tint newNode = uf.addNode();
          //cout << "creado nodo " << newNode << endl;
          toNode[pos] = newNode;
        }
        // luego las mergeo
        
        for (auto pos : itH->second) {
          tint node = toNode[pos];
           //ver vecinos
          forn(i,4) {
            ii vec = make_pair(pos.first-dx[i], pos.second-dy[i]);
             //que el vecino ya sea tierra
            if (toNode.find(vec) != toNode.end()) {
              tint vecNode = toNode[vec];
              //cout << "uniendo " << node << " con " << vecNode << endl;
              uf.unionSet(node, vecNode);
            }
          }
        }
        itH++;
      }
      sols.push_back(uf.comps());
      //cout << uf.comps() << " ";
    }
    reverse(sols.begin(), sols.end());
    for(auto s : sols) cout << s << " ";
    cout << endl;
  }
  return 0;
}
