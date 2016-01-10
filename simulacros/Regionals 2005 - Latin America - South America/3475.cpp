#include <iostream>
#include <deque>
#include <vector>
#include <set>

#define forn(i,n) for(int i = 0; i < (int) (n);i++)

using namespace std;

int main(){
	int n,tmp,strokes;
	cin >> n;
	int strokes = 0;
	set<int> a;
	int b[n],v[n];
	forn(i,n){
		cin >> tmp;
		a.insert(tmp);
		cin >> b[i];
	} 
	if(a.count() < n){
		cout << "No solution";
	}else{
		strokes = 0;
		while(strokes < 4*n*n){
			forn(i,n) v[i]=abs(b[i]-i);
			
		}
	}
	return 0;
}
