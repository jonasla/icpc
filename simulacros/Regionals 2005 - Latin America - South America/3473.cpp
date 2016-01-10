#include <iostream>
#include <cmath>
using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n);i++)


class par{
public:
	int i,j;
};

int permutar(int a,int i, int j){
	double m = 1.0*(i+j)/2;
	int d = ceil(abs(m - a));
	if(a>m)
		return ceil(m-d);
	else if(a<m)
		return floor(m+d);
	else
		return a;
}

int main(){
	int n,r,q,count=0;
	cin >> n;
	while(n!=0){
		count++;
		cin >> r;
		par swaps[r];
		forn(i,r){
			cin >> swaps[i].i;
			cin >> swaps[i].j;
		}
		cin >> q;
		int a[q];
		forn(i,q){
			cin >> a[i];
			forn(j,r)
				if(a[i]<=swaps[j].j && a[i]>=swaps[j].i)
					a[i] = permutar(a[i],swaps[j].i,swaps[j].j);
		}
		cout << "Genome "<<count<<endl;
		forn(i,q) cout << a[i] << endl;
		cin >> n;
	}
	return 0;
}
