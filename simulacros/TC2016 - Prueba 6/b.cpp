#include <iostream>
#include <string>

using namespace std;

int cant[27];

#define forn(i,n) for(int i=0; i<(int)n; i++)

int main(){
	cant[0] = 1;
	cant[1] = 2;
	cant[2] = 0;
	cant[3] = 1;
	cant[4] = 0;
	cant[5] = 0;
	cant[6] = 0;
	cant[7] = 0;
	cant[8] = 0;
	cant[9] = 0;
	cant[10] = 0;
	cant[11] = 0;
	cant[12] = 0;
	cant[13] = 0;
	cant[14] = 1;
	cant[15] = 1;
	cant[16] = 1;
	cant[17] = 1;
	cant[18] = 0;
	cant[19] = 0;
	cant[20] = 0;
	cant[21] = 0;
	cant[22] = 0;
	cant[23] = 0;
	cant[24] = 0;
	cant[25] = 0;

	string s; cin >> s;
	int res = 0;
	forn(i,s.size()) res += cant[s[i]-'A'];
	cout << res << endl;
	
	return 0;
}
