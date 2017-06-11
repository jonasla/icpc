#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)

vector<int> desarrollo (int n)
{
  vector<int> aux;
  while (n > 0)
  {
    aux.push_back(n % 10);
    n /= 10;
  }
  reverse(aux.begin(),aux.end());
  return aux;
}


int g (vector<int> &des, int d, int k)
{
  int izq = 0, p = 1, maxK = des.size();
  forn(j,k)
  {
    izq += p*des[k-j-1];
    p *= 10;
  }
  p = 1;
  int der = 0;
  forn(j,maxK-k-1)
  {
    der += p*des[maxK-j-1];
    p *= 10;
  }
  if (d > 0)
    return izq*p + p*(d < des[k]) + (der+1) * (d == des[k]);
  else
    return (izq-1)*p + p*(d < des[k]) + (der+1) * (d == des[k]);
  
  
}

int f (vector<int> &des, int d)
{
  int maxK = int(des.size()), ans = 0;
  forn(k,maxK)
      ans += g(des,d,k);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a,b;
  while (cin >> a >> b && a != 0)
  {
    forn(d,10)
    {
      if (d)
        cout << " ";
      vector<int> db = desarrollo(b), da = desarrollo(a-1);
      
      cout << f(db,d) - f(da,d);
    }
    cout << "\n";
    
  }
  return 0;
}
