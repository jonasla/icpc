#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//usa: algorithm, vector, sqr
double pcruz(double x1,double y1,double x2,double y2){return x1*y2-x2*y1;}

#define sqr(x) (x)*(x)

struct pto {
	double x,y;
	double n2(pto &p2)const{
		return sqr(x-p2.x)+sqr(y-p2.y);
	}
} r;

double area3(pto a, pto b, pto c){
	return pcruz(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}

bool men2(const pto &p1, const pto &p2){
	return (p1.y==p2.y)?(p1.x<p2.x):(p1.y<p2.y);
}

bool operator<(const pto &p1,const pto &p2){
	double ar = area3(r,p1,p2);
	return(ar==0)?(p1.n2(r)<p2.n2(r)):ar>0;
	//< clockwise, >counterclockwise
}

typedef vector<pto> VP;
typedef long long tint;

VP chull(VP & l){
	VP res = l; if(l.size()<3) return res;
	r = *(min_element(res.begin(),res.end(),men2));
	sort(res.begin(),res.end());
	tint i=0;
	VP ch;
	ch.push_back(res[i++]);
	ch.push_back(res[i++]);
	
	while((unsigned)i<res.size()) // area3 > clockwise, < counterclockwise
		if(ch.size()>1 && area3(ch[ch.size()-2],ch[ch.size()-1],res[i])<=0)
			ch.pop_back();
		else
			ch.push_back(res[i++]);
		return ch;
}

int main(){

	int N;
	cin >> N;
	while(N != -1){
		VP pts;
		for(int i=0; i<N; i++){
			double x, y;
			cin >> x >> y;
			pto p;
			p.x = x;
			p.y = y;
			pts.push_back(p);
		}
		
		// chull
		VP lachull = chull(pts);
		
		// max diago O(n^2)
		double maxDiag = -1;
		int d1 = -1;
		int d2 = -1;
		for(unsigned int i=0; i<lachull.size(); i++){
			for(unsigned int j=i+1; j<lachull.size(); j++){
				double diag = lachull[i].n2(lachull[j]);
				if(diag > maxDiag){
					//cout << "act diag\n";
					maxDiag = diag;
					d1 = i;
					d2 = j;
				}
			}
		}
		
		//cout << d1 << " " << d2 << endl;
		
		// triangs
		pto& pd1 = lachull[d1];
		pto& pd2 = lachull[d2];
		
		
		double a = sqrt(maxDiag);
		
		double areaT1 = 0;
		for(int i=d1+1; i<d2; i++){
			double b = sqrt(pd1.n2(lachull[i]));
			double c = sqrt(pd2.n2(lachull[i]));
			double s = (a + b + c) / 2;
			double ar = sqrt((s-a)*(s-b)*(s-c));
			//cout << ar << endl;
			areaT1 = max(areaT1, ar);
		}
		
		unsigned int i = (d2+1);
		double areaT2 = 0;
		while(i < d1+(lachull.size())){
			double b = sqrt(pd1.n2(lachull[i % (lachull.size())]));
			double c = sqrt(pd2.n2(lachull[i % (lachull.size())]));
			double s = (a + b + c) / 2;
			double ar = sqrt((s-a)*(s-b)*(s-c));
			//cout << ar << endl;
			//cout << "hooaa\n";
			areaT2 = max(areaT2, ar);
			
			i++;
			//i = i % (lachull.size());
		}
		cout << (areaT1 + areaT2) << endl;
		
		//
		cin >> N;
	}

	return 0;
}
