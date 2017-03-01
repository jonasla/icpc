#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define sqr(x) (x)*(x)
#define pb push_back

typedef long long tint;
typedef vector<int> vi;

int R=0, D=0, RD=0, DR=0;

void count(string s){
	string res = "";
	bool colapse = false;
	for(auto c : s){
		if(c == 'D' && res.size()==0) res.pb('D');
		else if(c == 'D' && res.size()>0 && res[res.size()-1]=='R') res.pb('D');
		else if(c == 'R' && res.size()==0 && !colapse) res.pb('R');
		else if(c == 'R' && res.size()>0 && res[res.size()-1]=='D') { res.pop_back(); DR++; colapse = true; }
	}
	//~ cerr << res << endl;
	if(res == "D") D++;
	else if(res == "RD") RD++;
	else if(res == "R") R++;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int F; cin >> F;
	forn(i,F){
		string s; cin >> s;
		count(s);
	}
	if(RD==0){
		cout << DR+min(D,R) << endl;
	}else if(D==0 && R==0){
		cout << DR+RD-1 << endl;
	}else{
		cout << DR+RD+min(R,D) << endl;
	}

	return 0;
}
