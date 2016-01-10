#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef vector<bool> Vec;
typedef vector<Vec> Mat;
#define eps 1e-10
#define feq(a, b) (fabs(a-b)<eps)

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)

int dameHab(Mat &hot, int ini, int fin, int &hab){
	int maxD = 0;
	int maxH = -1;
	
	forn(j, hot[0].size()){
		//cout << "\ncol: " << j << endl;
		int lib = 0;
		forsn(i, ini, fin){
			//cout << hot[i][j] << " ";
			if(!hot[i][j]){
				lib++;
				//cout << "lib+ "  << lib << " ";
			}else{
				if(lib > maxD){
					maxD = lib; maxH = j;
					//cout << "max: " << maxD << endl;
				}
				break;
			}
			if(lib > maxD){
				maxD = lib; maxH = j;
				//cout << "max: " << maxD << endl;
			}
		}
	}
	hab = maxH;
	return maxD;
}


int main(){
	
	int M, N;
	cin >> M >> N;
	
	int caso = 1;
	
	while(M && N){
		Mat hotel;
		
		forn(i,M){
			string str;
			cin >> str;
			Vec aux;
			forn(i,str.length()){
				if(str[i] == 'X'){
					aux.push_back(true);
				}else if(str[i] == 'O'){
					aux.push_back(false);
				}
			}
			hotel.push_back(aux);
			
		}
		
		forn(i,M){
			forn(j,N){
				cout << hotel[i][j] << " ";
			}
			cout << endl;
		}
		
		int ini, fin;
		cin >> ini >> fin;
		ini--;
		fin--;
		
		cout << "Case " << caso << ":\n\n";
		
		vector<pair < int , pair < int,  int > > > sol;
		bool haySol = true;
		
		while(ini != fin){
			int hab;
			int dias = dameHab(hotel, ini, fin, hab);

			if(dias == 0){
				cout << "Not available\n";
				haySol = false;
				break;
			}
			sol.push_back(make_pair(hab, make_pair(ini, ini+dias)));
			ini += dias;
		}
		
		if(haySol){
			forn(i,sol.size()){
				cout << (char)('A'+sol[i].first) << ": " << (sol[i].second.first+1) << "-" << (sol[i].second.second+1) << endl;
			}
		}
		
		cin >> M >> N;
		caso++;
	}
	
	return 0;
}
