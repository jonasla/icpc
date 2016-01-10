#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

void floyd(vector<vector<double> >  &matr){
	int n = matr.size();
	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		matr[i][j] = min(matr[i][j], matr[i][k] + matr[k][j]);
}

struct cat{
	long long xx;
	long long yy;
	long long ff;
	
	
};

double distEuc(cat c1, cat c2){
	return sqrt((c2.xx - c1.xx)*(c2.xx - c1.xx) + (c2.yy - c1.yy)*(c2.yy - c1.yy));
}

//cuanto hay que caminar desde c1 hasta c2
double distCat(cat c1, cat c2){
	return min( distEuc(c1,c2) , abs(distEuc(c1,c2) - c1.ff) );
}


int main(){

	long long  n, px, py, lx, ly;
	cin >> n >> px >> py >> lx >> ly;
	
	while(n != -1){
		
		vector<cat> catap;
		
		cat pini;
		pini.xx = px;
		pini.yy = py;
		pini.ff = 0;
		
		cat pfin;
		pfin.xx = lx;
		pfin.yy = ly;
		pfin.ff = 0;
		
		
		catap.push_back(pini);
		
		for(int i=0; i<n; i++){
			long long cx, cy, fi;
			cin >> cx >> cy >> fi;
			
			cat c;
			c.xx = cx;
			c.yy = cy;
			c.ff = fi;
			
			catap.push_back(c);
		}
		
		catap.push_back(pfin);
		
		vector< vector < double > > matr(n+2, vector<double>(n+2, 0));
		for(int i=0; i<n+2; i++)
		for(int j=0; j<n+2; j++)
			matr[i][j] = distCat(catap[i], catap[j]);
			
		floyd(matr);
		
		double distFinal = matr[0][n+1];
		//cout << distFinal << endl;
		printf("%.2f\n", distFinal);
		
		cin >> n >> px >> py >> lx >> ly;
	}
	
	return 0;
}
