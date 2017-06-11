#include <iostream>
#include <vector>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)

typedef vector<int> vi;

int main() {
  int N, B;
  while(cin >> N >> B && N > 0) {
    vi nums(B);
    forn(i,B) cin >> nums[i];

    vi pos(N+1, 0);
    forn(i,B)
    forn(j,B){
      int p = abs(nums[i] - nums[j]);
      if (p >= 0 || p <= N)
        pos[p]++;
    }

    //for (auto c : pos) cout << c << " ";
    //cout << endl;

    bool possible = true;
    forn(i,N+1) possible &= (pos[i]>0);
    
    if (possible) 
      cout << "Y\n";
    else 
      cout << "N\n";

  }
  return 0;
}
