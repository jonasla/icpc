#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(n); (i)++)

typedef vector<int> vi; 
typedef vector<char> vc; 


int main(){
	int T; cin >> T;
	while(T--){
		string str; cin >> str;
		//cout << str << endl;
		
		/// indices del conjunto i
		vector<vi> letras(26, vi());
		forn(i,str.size()){
			if(str[i] != '_'){
				int ci = str[i] - 'A';
				//cout << i << " " << ci << endl;
				letras[ci].push_back(i);
			}
		}
		
		/// letras del conjunto i
		vc posletras(26);
		forn(i,26){
			posletras[i] = 'A' + i;
		}
		
		/// ops
		int R; cin >> R;
		forn(j,R){
			char ci, cj; cin >> ci >> cj;
			forn(i,26){
				if(posletras[i] == cj){
					posletras[i] = ci;
				}
			}
		}
		
		/// 
		forn(i,26){
			for(auto &li : letras[i]){
				str[li] = posletras[i];
			}
		}
		
		cout << str << endl;
		
	}
	
	return 0;
}
