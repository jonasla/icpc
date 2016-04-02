#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define forn(i,n) for(int (i)=0; i<(int)(n); (i)++)
#define forsn(i,s,n) for(int (i)=(s); i<(int)(n); (i)++)

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pt;

bool f(pt p1, pt p2){
	return mp(p1.se,p1.fi)<mp(p2.se,p1.fi);
}

void limpio(vector<pt> &v){
	sort(v.begin(),v.end(),f);
	int d = 0;
	int n = v.size();
	forn(i,n-1){
		v[i+1].se-=d;
		if(v[i].se<v[i+1].se-1){
			d+=v[i+1].se-v[i].se-1;
			v[i+1].se-=v[i+1].se-v[i].se-1;;
		}
	}
	
	sort(v.begin(),v.end());
	d = 0;
	forn(i,n-1){
		v[i+1].fi-=d;
		if(v[i].se<v[i+1].fi-1){
			d+=v[i+1].fi-v[i].fi-1;
			v[i+1].fi-=v[i+1].fi-v[i].fi-1;;
		}
	}
}

int main(){
	int n,m;
	int x,y;
	while(cin>>n){
		vector<pt> p1(n);
		forn(i,n){
			cin >> x >> y; p1[i]=mp(x,y);
		}
		limpio(p1);
		cin >> m;
		vector<pt> p2(n);
		forn(i,m){
			cin >> x >> y; p2[i]=mp(x,y);
		}
		limpio(p2);
		bool exito = false;
		
		n = p1.size();
		m = p2.size();
		
		int k = p1[n-1].fi;
		
		if(n==m){
			
			int j = 0;
			for(j=0;j<n;j++)
				if(p1[j]!=p2[j])
					break;
			if(j==n)
				exito = true;
			else{
				forn(i,n)
					p1[i] = mp(p1[i].se,k-p1[i].fi);
				for(j=0;j<n;j++)
					if(p1[j]!=p2[j])
						break;
				if(j==n)
					exito = true;
				else{
					forn(i,n)
						p1[i] = mp(p1[i].se,k-p1[i].fi);
					
					for(j=0;j<n;j++)
						if(p1[j]!=p2[j])
							break;
					if(j==n)
						exito = true;
					else{
						forn(i,n)
							p1[i] = mp(p1[j].se,k-p1[j].fi);
						for(j=0;j<n;j++)
							if(p1[j]!=p2[j])
								break;
						if(j==n)
							exito = true;
					}
				}
			}
		}
		if(exito)
			cout << "yes"<<endl;
		else
			cout << "no"<<endl;
	}
	return 0;
}
