#include <iostream>
#include <cmath>
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define mp make_pair
typedef pair<int,int> pt;

int main(){
	int n;
	while(cin>>n && n!=0){
		if(n<=2){ 
			cout << "Fair";
			int x,y;
			forn(i,n)
				cin >> x >> y;
		}
		else{
			int x1,y1,x2,y2,x3,y3;
			bool fair = true;
			cin >> x1 >> y1 >> x2 >> y2;
			pt p1, p2, p3;
			p1 = mp(x1,y1);
			p2 = mp(x2,y2);
			forn(i,n-2){
				cin >> x3 >> y3;
				p3 = mp(x3,y3);
				
				pt b = p2-p1;
				pt c = p3-p2;
				
				if(acos(b*c/(n(b)*n(c)))<)
					
				p1=p2;
				p2=p3;
			}
			if(fair) cout << "Fair";
			else cout << "Unfair";
		}
	}
	return 0;
}
