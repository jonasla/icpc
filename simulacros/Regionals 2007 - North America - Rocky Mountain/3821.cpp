#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)
#define pb push_back

using namespace std;

typedef vector<int> vi;

int main(){

	string arb;
	int T = 1;
	while(cin >> arb && arb[0] != '#'){
		int S = (int)arb.size();
		int N = S/2;
		
		int maxLvl = 0;
		int maxLvlNew = 0;
		
		vi padres(N, -1);
		vi lvl(N, 0);
		vi lvlNew(N, 0);
		vector<vi> hijos(N, vi());
		
		int currP = 0;
		int currN = 1;
		padres[0] = 0;
		lvl[0] = 0;
		lvlNew[0] = 0;
		
		forn(i,S){
			if(arb[i] == 'd'){
				padres[currN] = currP;
				hijos[currP].pb(currN);
				lvl[currN] = lvl[currP]+1;
				
				if(hijos[currP].size() == 1){
					lvlNew[currN] = lvlNew[currP] + 1;
				}else{
					lvlNew[currN] = lvlNew[ hijos[currP][hijos[currP].size()-2] ] + 1;
				}
				maxLvl = max(maxLvl, lvl[currN]);
				maxLvlNew = max(maxLvlNew, lvlNew[currN]);
				
				currP = currN;
				currN++;
			}else if(arb[i] == 'u'){
				currP = padres[currP];
			}
		}
		
		cout << "Tree " << T << ": " << maxLvl << " => " << maxLvlNew << endl;
		T++;
	}

	return 0;
}
