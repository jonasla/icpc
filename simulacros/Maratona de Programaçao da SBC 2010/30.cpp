#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  char d; string s;
  while(cin >> d >> s && d != '0') {
    string r = "";
    for(auto c : s) {
      if (c != d) {
        if (c == '0') {
          if (!r.empty()) r.push_back(c);
        } 
        else 
          r.push_back(c);
      }
    }
    if(!r.empty()) cout << r << "\n";
    else cout << "0\n";
  }
  return 0;
}
