#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(int)(n); (i)++)
#define forsn(i,s,n) for(int (i)=(s); (i)<(int)(n); (i)++)

int main(){
	int T; cin >> T;
	forn(casito,T){
		string str; cin >> str;
		int OPER=0;
		int cantA=0, cantM=0;
		forn(i,str.size()){
			if(str[i] == 'a'){ cantA++;
			}else if (str[i] == '+'){ cantM++; }
		}
		
		int diff = cantA - cantM - 1;
		
		string nuevostr = "";
		if(diff > 0){	// faltan +
			
			forn(i,str.size()) nuevostr.push_back(str[i]);
			forn(i,diff) nuevostr.push_back('+');
			str = nuevostr;
		}else if(diff < 0){	// faltan A
		
			forn(i,-(diff)) nuevostr.push_back('a');
			forn(i,str.size()) nuevostr.push_back(str[i]);
			str = nuevostr;
		}
		
		OPER += abs(diff);
		
		//cout << str << endl;
		int stack = 0;
		forn(i,str.size()){
			if(str[i] == 'a') stack++;
			else if(str[i] == '+'){
				if(stack >= 2){
					stack--;
				}else{
					int ladiff = 2 - stack;
					//cout << "ladiff " << ladiff << endl;
					int cantaux = 0;
					int idxfin = i;
					///
					forsn(j,i+1,str.size()){
						if(str[j] == 'a') cantaux++;
						else if (str[j] == '+') cantaux--;	
						
						//cout << "cantaux" << " " << cantaux << endl;
						
						if(cantaux == ladiff){
							idxfin = j;
							//cout << "idxfin " << idxfin << endl;
							break;
						} 
					}
					///
					int idxin = i;
					for(int j=i; j<=idxfin; j++){
						if(str[j] == 'a'){
							if(stack == 0){
								OPER += j;
								idxin++;
								stack++;
							}else if(stack == 1){
								OPER += j-idxin;
								idxin+=2;
							}
						}
					}
					i = idxfin;
				}
			}
		}
		cout << "Case " << casito+1 << ": " << OPER << endl;
		
	}
	return 0;
}
