#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;
#define eps 1e-10
#define feq(a, b) (fabs(a-b)<eps)

#define forn(i,n) for(int i=0; i<(int)(n); i++)

#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)

#define dforn(i,n) for(int i=(int)((n)-1); i>=0; i--)

int main(){
	int k,n,m,c,t,j=0;
	double a,p1,p2,p3,p4;
	cin >> k;
	while(k--){
		j++;
		cin >> m >> n >> t >> c;
		a=m*n*t*t;
		p1 = 4*(t-1.0*c/2)*(t-1.0*c/2);
		p1 += ((n-2)*2+(m-2)*2)*(t-c)*(t-1.0*c/2);
		p1 += (n-2)*(m-2)*(t-c)*(t-c);
		p1 = p1/a;
		p2 = (1/a)* (((m-1)*2+(n-1)*2)*(t-1.0*c/2)*c+((m-2)*(n-1)+(m-1)*(n-2))*(t-c)*c);
		p4 = (m-1)*(n-1)*(1.0*c/2)*(1.0*c/2)*(1/a)*3.14159265;
		p3 = 1 - p1 - p2 - p4; 
		cout << "Case "<<j<<":"<<endl;
		printf("Probability of covering 1 tile = %.4f\n", 100*p1);
		printf("Probability of covering 1 tile = %.4f\n", 100*p2);
		printf("Probability of covering 1 tile = %.4f\n", 100*p3);
		printf("Probability of covering 1 tile = %.4f\n", 100*p4);
	}
	return 0;
}
