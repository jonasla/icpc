#include <iostream>

using namespace std;

int main(){
	string s; 
	cin >> s;
	for(auto c : s){
		if(c=='i') {
			cout << "N\n"; return 0;
		}
	}
cout << "S\n"; return 0;
}
