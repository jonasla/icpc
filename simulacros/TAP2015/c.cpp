#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define forsn(i,s,n) for (int i = (s); i <(int) (n); i++)
#define forn(i,n) for (int i = 0; i <(int) (n); i++)

int main(){
	int N, S, J, D; 
	
	while(cin >> N >> S >> J >> D && N != 0){
		string parts; cin >> parts;
		
		int setA = 0, setB = 0;
		int partA = 0, partB = 0;
		
		forn(i, parts.size()){
			if(parts[i] == 'A'){
				partA++;
			}else if(parts[i] == 'B'){
				partB++;
			}
			
			if(partA >= J && partA >= partB + D){ // gane set a
				setA++;
				
				partA = 0;
				partB = 0;
				
			}else if(partB >= J && partB >= partA + D){
				setB++;
				
				partA = 0;
				partB = 0;
			}
		}
		cout << setA  << " " << setB << endl;
	}
	return 0;
}
