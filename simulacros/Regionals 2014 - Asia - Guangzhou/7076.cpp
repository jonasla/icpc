#include <iostream>
#include <cmath>
using namespace std;

#define debug(a) cout<<a<<endl

struct Vector{
	int x;
	int y;
	Vector(int,int);
};

Vector::Vector(int a,int b){x=a;y=b;}
double norm2(Vector v){return sqrt(v.x*v.x+v.y*v.y);}

Vector menos(Vector &v, Vector &w){Vector t(v.x-w.x,v.y-w.y);return t;}
Vector proyest(double r, double a){
	double x = 2*r*r/(a*(1+r*r/(a*a)));
	double y = r-r*x/a;
	Vector v(x,y);
	return v;
}
int main(){
	int d,t,i=0;
	double v0,v1;
	while(true){
		long double area = 0;
		i++;
		cin >> v0 >> v1 >> d >> t;
		double r = t*v0;
		double a = -r*t*v1/(d-r);
		double x = 2*r*r/(a*(1+r*r/(a*a)));
		double y = r-r*x/a;
		double e = r*t*v1/(d+r);
		Vector v(x,y);
		Vector tmp = proyest(r,e);
		Vector w(tmp.x,-tmp.y);
		Vector q((t-d/v0)*v1,d);
		double tita = acos((v.x*w.x+v.y*w.y)/(norm2(v)*norm2(w)));
		cout << (v.x*w.x+v.y*w.y)<<endl;
		cout << (norm2(v)*norm2(w))<<endl;
		debug(tita);
		double s1 = 1.0*(norm2(v)+norm2(w)+norm2(menos(w,v)))/2;
		debug(s1);
		double s2 = 1.0*(norm2(menos(w,v))+norm2(menos(q,v))+norm2(menos(q,w)))/2;
		debug(s2);
		double area1=sqrt(s1*(s1-norm2(v))*(s1-norm2(w))*(s1-norm2(menos(w,v))));
		debug(area1);
		double area2=sqrt(s2*(s2-norm2(menos(q,v)))*(s2-norm2(menos(q,w)))*(s2-norm2(menos(w,v))));
		debug(area2);
		area = area1+area2+r*r*acos(-1)-tita*r*r/2;
		cout <<"Case "<< i <<": "<< area<<endl;
	}
	return 0;
}
