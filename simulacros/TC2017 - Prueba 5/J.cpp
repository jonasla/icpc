#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long tint;
typedef vector<tint> vi;
typedef tint tipo;

#define forsn(i,s,n) for(int i=(tint)s; i<(tint)n; i++) 
#define forn(i,n) forsn(i,0,n) 
#define sqr(x) (x)*(x)

tipo pcruz(tipo x1, tipo y1, tipo x2, tipo y2) {return x1*y2 - x2*y1; }
struct pto {
	tipo x, y;
	tipo n2(pto &p2) const {
		return sqr(x-p2.x)+sqr(y-p2.y);
	}
} r;

tipo area3(pto a, pto b, pto c) {
	return pcruz(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
bool men2(const pto &p1, const pto &p2) {
	return (p1.y == p2.y) ? (p1.x < p2.x) : (p1.y < p2.y);
}

bool operator<(const pto&p1, const pto&p2) {
	tipo ar = area3(r,p1,p2);
	return (ar==0) ? (p1.n2(r) < p2.n2(r)) : (ar > 0);
}

typedef vector<pto> VP;

VP chull(VP &l) {
	VP res = l;
	if (l.size() < 3) return res;
	r = *(min_element(res.begin(), res.end(), men2));
	sort(res.begin(), res.end());
	tint i = 0; VP ch; ch.push_back(res[i++]); ch.push_back(res[i++]); 
	while(i<(tint)res.size()) 
		if (ch.size() > 1 && area3(ch[ch.size()-2],ch[ch.size()-1],res[i])<0)
			ch.pop_back();
		else 
			ch.push_back(res[i++]);
	return ch;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	tint N;
	while(cin >> N && N != 0) {
		VP ptos(N);
		forn(i,N) {
			cin >> ptos[i].x >> ptos[i].y;
		}
		//
		tint usados = 0;
		tint cant = 0;
		
		VP quedan = ptos;
		while(usados < N) {
			
			
			VP ch = chull(quedan);
			if (ch.size() < 3) 
				break;
			else if (area3(ch[0],ch[1],ch[ch.size()-1]) == 0)
				break;
			usados += ch.size();
			set<pto> chh(ch.begin(), ch.end());
			//~ cout << ch.size() << endl;
			cant++;
			VP nuevos;
			for (auto p : quedan) {
				if (chh.find(p) == chh.end()) {
					nuevos.push_back(p);
				}
			}
			quedan = nuevos;
		}
		//~ cout << cant << endl;
		if (cant % 2) {
			cout << "Take this onion to the lab!\n";
		} else {
			cout << "Do not take this onion to the lab!\n";
		}
	}
	return 0;
}
