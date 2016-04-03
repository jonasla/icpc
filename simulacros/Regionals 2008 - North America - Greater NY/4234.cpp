#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(int)(n); (i)++)

string bin(int x){
	string res;
	forn(i,6){
		int r = x%2;
		x /= 2;
		res = to_string(r) + res;
	}
	return res;
}

int main(){

	int N;
	cin >> N;
	forn(i,N){
		string letime; cin >> letime;
		//cout << time << endl;
		string hora, min, sec;
		hora = letime[0];
		hora += letime[1];
		min = letime[3];
		min += letime[4];
		sec = letime[6];
		sec += letime[7];
		//cout << hora << endl;
		//cout << min << endl;
		//cout << sec << endl;
		int ihora, imin, isec;
		ihora = stoi(hora);
		imin = stoi(min);
		isec = stoi(sec);
		string shora, smin, ssec;
		shora = bin(ihora);
		smin = bin(imin);
		ssec = bin(isec);
		
		string vtime, htime;
		htime = shora + smin + ssec;
		for(int j=0; j<6; j++){
			vtime += shora[j];
			vtime += smin[j];
			vtime += ssec[j];
		}
		
		cout << i+1 << " " << vtime << " " << htime << endl;
	}
	
	return 0;
}
