#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n);i++)

int main()
{
	int T;
	cin >> T;
	
	for(int C=1; C<=T; C++){
		string wS, wE, mS, mE;
		
		cin >> wS >> wE >> mS >> mE;
		
		int wifeS=0, wifeE=0, meetS=0, meetE=0;
		
		wifeS = stoi(wS.substr(3,4)) + 60*stoi(wS.substr(0,2));
		wifeE = stoi(wE.substr(3,4)) + 60*stoi(wE.substr(0,2));
		meetS = stoi(mS.substr(3,4)) + 60*stoi(mS.substr(0,2));
		meetE = stoi(mE.substr(3,4)) + 60*stoi(mE.substr(0,2));
		
		bool canMeet = true;
		if(wifeS <= meetS && meetS <= wifeE) canMeet = false;
		
		if(meetS <= wifeS && wifeS <= meetE) canMeet = false;
		
		if(meetS <= wifeS && wifeE <= meetE) canMeet = false;
		
		if(wifeS <= meetS && meetE <= wifeE) canMeet = false;
		
		cout << "Case " << C << ": ";
		if(canMeet){
			cout << "Hits Meeting\n";
		}else{
			cout << "Mrs Meeting\n";
		}
	}
	
	return 0;
}
