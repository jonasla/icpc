#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(int)(n); (i)++)

char decode[26];

int main(){

	int N;
	cin >> N;
	string nada; getline(cin, nada);
	forn(i,N){
		string msg, code; 
		getline(cin, msg);
		getline(cin, code);
		
		//cout << msg << endl << code << endl;
		
		string msgpiola;
		forn(i,msg.size()){
			if(msg[i] != ' '){
				//cout << msg[i] << " ";
				//cout << msg[i] - 'A' << " ";
				msgpiola += code[msg[i] - 'A'];
			}else{
				msgpiola += " ";
			}
		}
		cout << i+1 << " " << msgpiola << endl;
	}
	
	return 0;
}
