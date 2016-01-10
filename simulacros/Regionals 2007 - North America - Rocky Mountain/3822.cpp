#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int T;
	cin >> T;
	while(T--){
		
		string str;
		cin >> str;
		
		int count = 1;
		char last = str[0];
		for(unsigned int i=1; i<str.length(); i++){
			if(str[i] == last){
				count++;
			}else{
				cout << count << last ;
				
				last = str[i];
				count = 1;
			}
		}
		cout << count << last ;
		cout << endl;
		
		
		
	}
	
	return 0;
}
