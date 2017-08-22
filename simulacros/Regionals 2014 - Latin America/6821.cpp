#include <iostream>

using namespace std;

int main() {
  bool c11, c12, c13, c14, c15, c21, c22, c23, c24, c25;
  while(cin >> c11 >> c12 >> c13 >> c14 >> c15 >> c21 >> c22 >> c23 >> c24 >> c25) {
    if (c11^c21 && c12^c22 && c13^c23 && c14^c24 && c15^c25) {
      cout << "Y\n";
    } else {
      cout << "N\n";
    }
  }
}
