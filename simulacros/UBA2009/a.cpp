#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

#define eps 0.000001

int main(){

	double propC = (double)1000/(double)37;
	
	int I, W;
	cin >> I >> W;
	
	
	while(I != -1){
		int g = gcd(I, W);
		I /= g;
		W /= g;
			
		double miC = (double)I / (double)W;
	
		if(abs(propC - miC) > eps){
			cout << "N\n";
		}else{
			cout << "Y\n";
		}
	
		//
		cin >> I >> W;
	}
	
	return 0;
}
