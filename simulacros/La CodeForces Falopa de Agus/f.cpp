#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forsn(i,s,n) for(tint i = (tint)s; i < (tint) (n); i++)
#define forn(i,n) forsn(i,0,n)

struct sofa {
	int x1, y1, x2, y2, id;
	sofa(int i, int xx1, int yy1, int xx2, int yy2) {
		id = i;
		x1 = xx1;
		y1 = yy1;
		x2 = xx2;
		y2 = yy2;
	}
	int left() {
		return min(x1,x2);
	}
	int right() {
		return max(x1,x2);
	}
	int top() {
		return min(y1,y2);
	}
	int bottom() {
		return max(y1,y2);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int d, n, m;
	while(cin >> d >> n >> m) {
		int x1, y1, x2, y2;
		vector<sofa> sofas;
		forn(i,d) {
			cin >> x1 >> y1 >> x2 >> y2;
			//~ x1--; y1--; x2--; y2--;
			sofas.push_back(sofa(i,x1,y1,x2,y2));
		}
		//
		
		int cntl, cntr, cntt, cntb; cin >> cntl >> cntr >> cntt >> cntb;
		
		vi toLeft(n+2,0);
		vi toRight(n+2,0);
		vi toTop(m+2,0);
		vi toBottom(m+2,0);

		forn(i,d) {
			int l = sofas[i].left();
			toLeft[l+1] += 1;
			toLeft[n+1] -= 1;
			
			int r = sofas[i].right();
			toRight[r] -= 1;
			toRight[1] += 1;
			
			int t = sofas[i].top();
			toTop[t+1] += 1;
			toTop[m+1] -= 1;
			
			int b = sofas[i].bottom();
			toBottom[b] -= 1;
			toBottom[1] += 1;
		}
		
		forn(i,n+1) {
			toLeft[i+1] += toLeft[i];
			toRight[i+1] += toRight[i];
		}
		forn(i,m+1) {
			toTop[i+1] += toTop[i];
			toBottom[i+1] += toBottom[i];
		}
		//
		bool find = false;
		forn(i,d) {
			int l, r, t, b;
			l = toLeft[sofas[i].right()] - sofas[i].right() + sofas[i].left();
			r = toRight[sofas[i].left()] - sofas[i].right() + sofas[i].left();
			t = toTop[sofas[i].bottom()] - sofas[i].bottom() + sofas[i].top();
			b = toBottom[sofas[i].top()] - sofas[i].bottom() + sofas[i].top();
			//~ cout << l << " " << r << " " << t << " " << b << endl;
			if (l == cntl && r == cntr && t == cntt && b == cntb) {
				cout << i+1 << "\n";
				find = true;
				break;
			}
		}
		if (!find) cout << -1 << "\n";
	}
	return 0;
}
