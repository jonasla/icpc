#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for(int i=0; i<(int)n; i++)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string S; 
  while (cin >> S) {
    vector<string> ss;
    string cS;
    for(auto c : S) {
      if (c >= 'a' && c <= 'z') {
        if (!cS.empty()) {
          ss.push_back(cS);
          cS.clear();
        }
      } else if (c >= '0' && c <= '9') {
        cS.push_back(c);
      }
    }
    if (!cS.empty()) ss.push_back(cS);
    ///
    tint ans = 0;
    for (auto s : ss) {
      vector<int> p = {0,1,2};
      vector<tint> c = {0,0,0};
      tint sum = 0;
      for(auto ch : s) {
        sum += (ch-'0');
        sum = sum % 3;
        c[sum]++;
      }
      
      for(auto ch : s) {
        //cout << "cants: " << c[p[0]] << " " << c[p[1]] << " " << c[p[2]] << endl;
        //cout << "inds: " << p[0] << " " << p[1] << " " << p[2] << endl;
        
        sum = (ch-'0') % 3;
        //cout << sum << endl;
        ans += c[p[0]];
        c[p[sum]]--;
        
        forn(i,3) {
          p[i] = (p[i] + sum + 3) % 3;
        }
      }
      
    }
    cout << ans << endl;
  }
  return 0;
}
