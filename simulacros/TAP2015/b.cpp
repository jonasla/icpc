#include <iostream>

using namespace std;

typedef unsigned long long utint;

bool canMin(utint L, utint K, utint C){
	utint am = 0;
	utint secLeft = K;
	bool can = true;
	
	for(utint lvl=0; lvl<L; lvl++){
		am += lvl*2 + 1;
		if(am >= C){
			am = 0;
			secLeft--;
		}
		if(secLeft == 0) break;
		if((L-lvl-1) < secLeft){
			can = false;
			break;
		}
	}
	
	return can;
}

int main(){
	utint L, K;

	while(cin >> L >> K && L != 0){
		if(L == 1){ cout << 1 << endl; continue; }
		
		utint low = 1, high = 0;
		for(utint lvl=0; lvl<L; lvl++) high += lvl*2 + 1;
		
		if(K == 1){ cout << high << endl; continue; }
		
		while(low < high){
			utint mid = low + (high-low+1)/2;
			if(canMin(L, K, mid)){
				low = mid;
			}else{
				high = mid-1;
			}
		}
		
		cout << low << endl;
	}

	return 0;
}
