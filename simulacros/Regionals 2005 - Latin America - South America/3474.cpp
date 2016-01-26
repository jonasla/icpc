#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long utint;
typedef vector<int> vi;

#define forn(i,n) for(int i = 0; i < (int) (n);i++)
#define pb push_back

vi baseN(utint k, int N, int sec){
	vi res;
	while(k > 0){
		res.pb(k%N);
		k /= N;
	}
	while((int)res.size() < sec){
		res.pb(0);
	}
	reverse(res.begin(), res.end());
	return res;
}

int main(){

	int N, Q; 
	while(cin >> N >> Q && N != 0 && Q != 0){
		vector<string> songs(N);
		forn(i,N) cin >> songs[i];
		
		forn(i,Q){
			utint k; cin >> k;
			int sec = 1;
			utint tamSec = N;
			while(k > tamSec){
				k -= tamSec;
				
				sec++;
				tamSec /= (sec-1);
				tamSec *= N;
				tamSec *= sec;
			}
			/*
			cout << "Size: " << sec << endl;
			cout << "Word: " << (k-1) / (sec) << endl;
			cout << "Song: " << (k-1) % (sec) << endl;
			*/
			vi word = baseN((k-1) / (sec), N, sec);
			/*
			cout << "Palabra: ";
			for(auto &c : word) cout << c << " ";
			cout << endl;
			*/
			cout << songs[word[(k-1) % (sec)]] << endl;
		}
		cout << endl;
	}

	return 0;
}
