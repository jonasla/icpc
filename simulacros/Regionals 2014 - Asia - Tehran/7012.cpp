#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int a, b, c, d;
	while(cin >> a >> b >> c >> d && !(a == 0 && b == 0 && c == 0 && d == 0)){
		cout << (c-b) << " " << (d-a) << endl;
	}
	return 0;
}
