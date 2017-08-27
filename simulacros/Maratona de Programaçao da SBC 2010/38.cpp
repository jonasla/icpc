#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forsn(i,s,n) for (tint i = (tint)s; i < (tint)(n); i++)
#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

const tint INF = 1e9;

void dfsTopo(tint s, vector<vi> &g, vi &visit, vi &ord) {
  visit[s] = true;
  for(auto v : g[s]) {
    if (!visit[v]) dfsTopo(v, g, visit, ord);
  }
  ord.push_back(s);
  //comp.push_back(s);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M; 
  while(cin >> N >> M && N != 0) {
    //cout << "jgkgjdk\n";
    vector<vi> graf(N, vi());
    vector<vi> grafInv(N, vi());
    int u, v, w;
    //cout << "jgdjgdk\n";
    forn(i,M) {
      cin >> u >> v >> w; 
      u--; v--;
      //cout << u << " " << v << " " << w << endl;
      if (w == 2) {
        graf[u].push_back(v);
        graf[v].push_back(u);
        grafInv[u].push_back(v);
        grafInv[v].push_back(u);
      } else {
        graf[u].push_back(v);
        grafInv[v].push_back(u);
      }
    }
    //cout << "jgdjgdk\n";
    //
    vi visit(N, false);
    vi ord;
    vi aux;
    forn(i,N) if(!visit[i]) dfsTopo(i, graf, visit, ord);
    //
    reverse(ord.begin(), ord.end());
    //
    tint COMPS = 0;
    visit.assign(N, false);
    for(auto o : ord) {
      if (!visit[o]) {
        COMPS++;
        dfsTopo(o, grafInv, visit, aux);
      }
    }
    cout << (COMPS==1) << "\n";
  }
  return 0;
}
