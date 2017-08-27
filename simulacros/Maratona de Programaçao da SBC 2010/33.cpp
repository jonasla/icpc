#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forsn(i,s,n) for (tint i = (tint)s; i < (tint)(n); i++)
#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

const tint INF = 1e9;

tint C;

void floyd(vector<vi> &g) {
  int n = g.size();
  forsn(k,C,n)
  forn(i,n)
  forn(j,n)
    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  tint N, M, K;
  while(cin >> N >> M >> C >> K && N != 0) {
    vector<vi> g(N, vi(N, INF));
    forn(i,N) g[i][i] = 0;
    forn(i,M) {
      tint u, v, w; cin >> u >> v >> w;
      //cout << u << " " << v << " " << w << endl;
      g[u][v] = w;
      g[v][u] = w;
    }
    //
    vi cam(C, 0);
    for(int i=C-2; i>=0; i--) {
      cam[i] = cam[i+1] + g[i][i+1];
    }
    //forn(i,C) cout << cam[i] << " ";
    //cout << endl;
    //
    floyd(g);
    //
    tint ANS = INF;
    forn(i,C) {
      //cout << "i: " << i << endl;
      //cout << "dist: " << g[K][i] << " " << cam[i] << endl;
      ANS = min(ANS, g[K][i] + cam[i]);
    }
    cout << ANS << "\n";
  }
  return 0;
}
