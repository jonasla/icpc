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

vi S, T, diffS, diffT;

map<char, tint> notas;
map<char, tint> alts;

void fillNotasAlts() {
  notas['C'] = 0;  // b = -1,  # = 1
  notas['D'] = 2;  // b =  1,  # = 3
  notas['E'] = 4;  // b =  3,  # = 5
  notas['F'] = 5;  // b =  4,  # = 6
  notas['G'] = 7;  // b =  6,  # = 8
  notas['A'] = 9;  // b =  8,  # = 10
  notas['B'] = 11; // b = 10,  # = 12

  alts['#'] =  1;
  alts['b'] = -1;
}

const tint SND = 12;
const tint MAXN = 1e5 + 50;

tint kmp_table[MAXN];

void fill_table()
{
  int pos = 2, cnd = 0;
  kmp_table[0] = -1;
  kmp_table[1] = 0;
  while(pos<(int)diffS.size())
  {
    if(diffS[pos-1] == diffS[cnd])
      kmp_table[pos++] = ++cnd;
    else if (cnd>0) 
      cnd = kmp_table[cnd];
    else 
      kmp_table[pos++] = 0;
  }
}

int kmp(){
  fill_table();
  int m=0, i=0;
  while(m+i<(int)diffT.size()) {
    if (diffS[i] == diffT[m+i]) {
      if(i==(int)diffS.size()-1) 
        return m;
      i++;
    } else {
      m = m + i - kmp_table[i];
      if (kmp_table[i] > -1)
        i = kmp_table[i];
      else 
        i = 0;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  fillNotasAlts();

  tint N, M;
  while(cin >> N >> M && N != 0) {
    T.assign(N, 0);
    S.assign(M, 0);
    string str; int r;
    forn(i,N) {
      cin >> str;
      r = notas[str[0]];
      if (str.size()==2) r += alts[str[1]];
      r = (r+SND)%SND;
      T[i] = r;
    }
    forn(i,M) {
      cin >> str;
      r = notas[str[0]];
      if (str.size()==2) r += alts[str[1]];
      r = (r+SND)%SND;
      S[i] = r;
    }
    diffT.assign(N-1, 0);
    diffS.assign(M-1, 0);
    forsn(i,1,N) diffT[i-1] = ((T[i] - T[i-1])+SND)%SND;
    forsn(i,1,M) diffS[i-1] = ((S[i] - S[i-1])+SND)%SND;
    
    //forn(i,N-1) cout << diffT[i] << " ";
    //cout << endl;
    //forn(i,M-1) cout << diffS[i] << " ";
    //cout << endl;
    //
    
    int ans = kmp();
    //cout << ans << endl;
    if (ans == -1) cout << "N\n";
    else cout << "S\n";
  }
  return 0;
}
