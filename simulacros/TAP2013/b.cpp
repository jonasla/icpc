#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <functional>
#include <string>
#include <tuple>

#include <iostream>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl

typedef long long tint;
typedef unsigned long long utint;

using namespace std;

void imprimirVector (vector<int> &v){
	if (!v.empty()){
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}else
		cout << "[]" << endl;
}

void imprimirVector (vector<double> &v){
	if (!v.empty()){
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}else
		cout << "[]" << endl;
}

int main(){
	
	int N; cin >> N;
	int totalVotes = 0;
	vector<int> votes;
	vector<double> porc;
	
	forn(i,N){
		int e; cin >> e; 
		totalVotes += e;
		votes.push_back(e);
	}

	forn(i,N){
		double p = ((double)votes[i] / (double)totalVotes) * 100.0;
		porc.push_back(p);
	}
	
	//imprimirVector(votes);
	//imprimirVector(porc);
	
	forn(i,N){
		
		bool puedeganar = true;
		forn(j,N){
			if(j != i && votes[i] <= votes[j]){
				puedeganar = false;
				break;
			}
		}
		
		if(!puedeganar){
			//cout << "lala" << endl;
			continue;
		}
		
		if(porc[i] >= 45.0){
			//bool gana = true;
			//forn(j,N){
				//if(j != i && porc[j] >= 45.0){
					//gana = false;
					//break;
				//}
			//}
			//if(gana){
				cout << 1 << endl;
				return 0;
			//}
		}
	
		if(porc[i] >= 40.0){
			bool gana = true;
			forn(j,N){
				if((j != i) && (porc[i] < (porc[j] + 10.0))){
					gana = false;
					break;
				}
			}
			if(gana){
				cout << 1 << endl;
				return 0;
			}
		}
		
	}
	
	cout << 2 << endl;
	return 0;
}
