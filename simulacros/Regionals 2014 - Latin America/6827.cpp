#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long tint;
typedef vector<tint> vi;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define sqr(x) (x)*(x)

struct pto {
  tint x, y;
  pto() {x=-1; y=-1;}
  pto(tint xx, tint yy) { x = xx; y = yy; }
};

tint d2(pto &p1, pto &p2) {
  return sqr(p1.x-p2.x) + sqr(p1.y-p2.y);
}

bool incomp(pto &p1, pto &p2) {
  return d2(p1,p2) <= 25;
}

const tint MAXN = 5*10e4+10;
pto ptos[MAXN];
vi graf[MAXN];
tint color[MAXN];
tint c[2];
queue<tint> Q;

bool operator<(pto &p1, pto &p2) {
  if (p1.x != p2.x) return p1.x < p2.x;
  else return p1.y < p2.y;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tint N, x, y; 
  while(cin >> N) {
   
   //vector<pto> ptos;
   forn(i,N){
     cin >> x >> y;
     ptos[i] = pto(x,y);
   }
   sort(ptos, ptos+N);
   // armo grafoo
   //vector<vi > graf(N, vi());
   forn(i,N) graf[i].clear();
   forn(i,N) {
     //forn(j,i) {
     for(int j=i-1; j>=0; j--) {
       if (incomp(ptos[i], ptos[j])) {
         graf[i].push_back(j);
         graf[j].push_back(i);
       } else if(abs(ptos[i].x - ptos[j].x) > 5) {
         break;
       }
     }
   }
   //el grafo es bipartito
   //vi color(N, 2);
   fill(color, color+MAXN, 2);
   // 2 no color
   tint ans = 0;
   forn(i,N) {
     if (color[i] == 2) {
       // bfs
       fill(c,c+2,0);
       Q.push(i);
       color[i] = 0;
       c[0]++;
       while(!Q.empty()) {
        tint v = Q.front(); Q.pop();
        for(auto ad : graf[v]) {
          if (color[ad] == 2) {
            Q.push(ad);
            color[ad] = 1-color[v];
            c[color[ad]]++;
          }
        }
       }
       ans += max(c[1], c[0]);
     }
    }
   cout << N-ans << endl;
  }
  return 0;
  
}
