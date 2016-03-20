#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cmath>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(n); (i)++)
#define forsn(i,s,n) for(int (i)=s; (i)<(n); (i)++)

typedef long double ld;
typedef pair<ld,ld> pt;

ld pcruz (pt pt1, pt pt2)
{
	return (pt1.first*pt2.second - pt1.second*pt2.first);
}

ld norm (pt p)
{
	return sqrt(p.first*p.first + p.second*p.second);
}

pt operator - (pt pt1, pt pt2)
{
	return make_pair(pt1.first - pt2.first, pt1.second - pt2.second);
}

ld eps = 1e-14;

int main()
{
	int casos;
	cin >> casos;
	forn(casito,casos)
	{
		ld W,H,x,xe,ye,u;
		cin >> W >> H >> x >> xe >> ye >> u;
		ld hinf = 0,hsup = H + 1.0;
		pt E = make_pair(xe,ye);
		while (abs(hinf - hsup) > eps)
		{
			ld h = (hinf + hsup)/2.0;
			ld tp = (h-ye)/(H-ye);
			pt p = make_pair((W-xe)*tp + xe,h), m = make_pair((W-xe)*tp + xe,2*h), n = make_pair((W-xe)*tp + xe,0.0);
			ld senogama = abs(pcruz((m-p),(E-p)))/(norm(m-p)*norm(E-p));
			ld beta = asin(senogama/u);
			if ( (n.first - tan(beta)*h) >= x)
				hsup = h;
			else
				hinf = h;
		}
		double  ans = double(hinf + hsup)/2.0;
		if (ans <= H)
			printf("%.4f\n", ans);
		else
			cout << "Impossible" << endl;
		
	}
	
	
	
	return 0;
}
