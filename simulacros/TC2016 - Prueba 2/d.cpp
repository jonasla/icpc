#include <iostream>

using namespace std;

#define forn(i,n) for(long long i=0; i<(long long)n; i++)

int main(){
	string tor; cin >> tor; 
	long long plays; cin >> plays;
	
	cout << "Tournament: " << tor << endl;
	cout << "Number of players: " << plays << endl;
	cout << "New ratings: " << endl;
	
	long double media = 0;
	
	forn(i,plays){
		string name; cin >> name;
		long double ra; cin >> ra; 
		long double w, we; cin >> w >> we;
		long double k; cin >> k;
		
		long double R = (ra + (k*(w-we)));
		media += ra;
		
		//cout << name << " " << (int)R << endl;
		printf("%s %.0Lf\n", name.c_str(), R);
	}
	
	//cout << "Media elo: " << (int)(media/plays) << endl;
	printf("Media Elo: %.0Lf\n", (media/plays));
	return 0;
}
