#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef unsigned int uint;

#define MAXN 3628900
vi graf[MAXN];

string inv(string actual, int i, int j){
	string::iterator it1 = actual.begin() + i;
	string::iterator it2 = actual.begin() + j + 1;
	reverse(it1, it2);
	
	return actual;
}

vi bfs(int s){
	vi dist(MAXN, -1);
	
	dist[s] = 0;
	
	queue<int> Q; Q.push(s);
	
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		for(auto& ady : graf[u]){
			if(dist[ady] == -1){
				dist[ady] = dist[u] + 1;
				Q.push(ady);
			}
		}
	}
	
	return dist;
}

uint factr(uint f){
	uint ret = 1;
	while(f>0){
		ret *= f;
		f--;
	}
	return ret;
}

void printVi(vi& v){
	for(auto&a : v) cout << a << " ";
}

uint ordPerm(string str){
	uint sz = str.size();
	
	uint fact = sz - 1;
	uint factorial = factr(fact);
	
	uint ord = 0;
	
	vi _rank(sz);
	for(uint i=0; i<sz; i++) _rank[i] = i;
	
	for(uint c=0; c<sz; c++){
		//printVi(_rank);
		//cout << endl;
		uint act = str[c] - 'a';
		
		ord += (_rank[act])*factorial;
		
		if(fact > 0)
			factorial /= fact;
		
		fact--;
		
		for(uint d=act+1; d<sz; d++) _rank[d]--;
	}
	
	return ord;
}

int main(){
	string init = "abcdefghij";
	/*
	cout << ordPerm("cabd") << endl;
	cout << ordPerm("cadb") << endl;
	cout << ordPerm("cbab") << endl;
	cout << ordPerm("cbda") << endl;
	cout << ordPerm("cdab") << endl;
	cout << ordPerm("cdba") << endl;
	
	return 0;
	*/
	//string init = "abcdefghij";
	/*
	cout << factr(0) << endl;
	cout << factr(1) << endl;
	cout << factr(2) << endl;
	cout << factr(3) << endl;
	cout << factr(4) << endl;
	cout << factr(5) << endl;
	*/
	
	uint ordenI = 0;
	do{
		//cout << init << "\t";
		//cout << ordenI << endl;;
		/*
		for(unsigned int i=0; i<init.size(); i++){
			for(unsigned int j=i+1; j<init.size(); j++){
				string leInv = inv(init, i, j);
				uint ordenAdy = ordPerm(leInv);
				
				graf[ordenI].push_back(ordenAdy);
				
				//cout << "\t" << leInv << "\t" << ordenAdy << endl;
			}
		}
		*/
		if(ordenI == 445012) { cout << init << endl; return 0; }
		
		ordenI++;
	}while(next_permutation(init.begin(), init.end()));
	
	cout << "Fin Grafo!\n";
	
	vi dists = bfs(0);
	auto it = max_element(dists.begin(), dists.end());
	cout << "Max distancia " << *it << " " << (it - dists.begin()) << endl;
	
	return 0;
}
