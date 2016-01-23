#include <iostream>

using namespace std;

int main(){ 

	string s;
	int T = 1;
	while(cin >> s && s != "#"){
		
		if(s == "HELLO") cout << "Case " << T << ": ENGLISH\n";
		else if(s == "HOLA") cout << "Case " << T << ": SPANISH\n";
		else if(s == "HALLO") cout << "Case " << T << ": GERMAN\n";
		else if(s == "BONJOUR") cout << "Case " << T << ": FRENCH\n";
		else if(s == "CIAO") cout << "Case " << T << ": ITALIAN\n";
		else if(s == "ZDRAVSTVUJTE") cout << "Case " << T << ": RUSSIAN\n";
		else cout << "Case " << T << ": UNKNOWN\n";
		
		T++;
	}
	
	return 0;
	
}
