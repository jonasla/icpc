
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long tint;
typedef vector<int> vi;
// <nodo, peso>
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define forn(i,n) for(int i=0; i<(int)n; i++)

const int MAXN = 1e5+20;

bool amigos[MAXN];
int subAmigos[MAXN];
int visit[MAXN];

tint suma = 0;
tint masPesada = 0;

int dfsSubAmigos(int s, vector<vii> &arb) {
  subAmigos[s] = amigos[s];
  visit[s] = true;
  for(auto h : arb[s]) {
    if (!visit[h.first]) {
      subAmigos[s] += dfsSubAmigos(h.first, arb);
    }
  }
  return subAmigos[s];
}

void sumaAristas(int s, vector<vii> &arb, tint peso) {
  visit[s] = true;
  if (amigos[s]) masPesada = max(masPesada, peso);
  for(auto h : arb[s]) {
    if (!visit[h.first]) {
      if(subAmigos[h.first] > 0) {
        suma += h.second;
        peso += h.second;
        sumaAristas(h.first, arb, peso);
        peso -= h.second;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tint n,f;
  while (cin >> n >> f) {
    vector<vii> arbol(n);
    forn(i,n-1) {
      int a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      arbol[a].push_back({b,c});
      arbol[b].push_back({a,c});
    }
    ///
    fill(amigos, amigos+MAXN, false);
    forn(i,f) {
      int l; cin >> l;
      l--;
      amigos[l] = 1;
    }
    ///
    fill(subAmigos, subAmigos+MAXN, 0);
    fill(visit, visit+MAXN, 0);
    dfsSubAmigos(0, arbol);
    ///
    suma = 0;
    masPesada = 0;
    fill(visit, visit+MAXN, 0);
    sumaAristas(0, arbol, 0);
    
    cout << suma - masPesada << endl;
  }
};
