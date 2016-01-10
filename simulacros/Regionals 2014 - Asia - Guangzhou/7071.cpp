#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

struct Trie
{
	bool def; 
	map<char, Trie> hijos;
};

void insert(Trie &T, string str, long long &cantPref){
	if(str == ""){
		if(T.def == false) cantPref+=1;
		T.def = true;
	}else{
		if(T.def == false){
			cantPref+=1;
		}else{
			cout << str << " ya estaba" << endl;
		}
		T.def = true;
		insert(T.hijos[str[0]], str.substr(1), cantPref);
	}
}

void matarTrie(Trie &T){
	T.def = false;
}

int main(){

	int N;
	cin >> N;
	
	while(N){
		
		Trie eltrie;
		
		long long cantPref = 0;
		
		for(int i=0; i<N; i++){
			string elstr;
			cin >> elstr;
			
			insert(eltrie, elstr, cantPref);
		}
		
		cantPref-=1;
		cout << (cantPref)*(cantPref) << endl;
		
		
		
		cin >> N;
	}

	return 0;
}
