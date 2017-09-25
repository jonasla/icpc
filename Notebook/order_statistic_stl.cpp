#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> ordered_set;

int main() {
  ordered_set X;
  X.insert(1); X.insert(2); X.insert(4); X.insert(8); X.insert(16);

  // find_by_order(i): iterador al lugar donde se encuentra el i-esimo
  cout << *X.find_by_order(1) << endl; // 2
  cout << *X.find_by_order(2) << endl; // 4
  cout << *X.find_by_order(4) << endl; // 16
  cout << (X.end() == X.find_by_order(6)) << endl; // true

  // order_of_key(x): orden donde iria el elemento x
  cout << X.order_of_key(-5) << endl;  // 0
  cout << X.order_of_key(1) << endl;   // 0
  cout << X.order_of_key(3) << endl;   // 2
  cout << X.order_of_key(4) << endl;   // 2
  cout << X.order_of_key(400) << endl; // 5
  return 0;
}
