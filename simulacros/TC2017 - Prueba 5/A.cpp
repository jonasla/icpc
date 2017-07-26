#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forsn(i,s,n) for(int i=(tint)s; i<(tint)n; i++) 
#define forn(i,n) forsn(i,0,n) 

const tint INFINITO = 2e18;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint c,n;
	while (cin >> c >> n)
	{
		vector<vector<tint> > m (n, vector<tint> (n));
		forn(i,n)
		forn(j,n-i)
		{
			cin >> m[i][j+i];
			//~ m[i][j] += c;
		}
		vector<tint> best(n,INFINITO);
		vector<tint> best_idx(n,-1);
		best[0] = m[0][0] + c;
		best_idx[0] = 0;
		forsn(i,1,n) {
			forn(j,i) {
				if (best[j] - m[best_idx[j]][j] + m[best_idx[j]][i] < best[i]) {
					//~ cout << "conservo pc\n";
					//~ cout << m[best_idx[j]][j] << endl;
					//~ cout << m[best_idx[j]][i] << endl;
					best[i] = best[j] - m[best_idx[j]][j] + m[best_idx[j]][i];
					best_idx[i] = best_idx[j];  
				}
				if (best[j] + c + m[j+1][i] < best[i]) {
					//~ cout << "nueva pc\n";
					//~ cout << j << endl;
					//~ cout << m[j+1][i] << endl;
					best[i] = best[j] + c + m[j+1][i];
					best_idx[i] = j;
				}
			}
		}
		//~ for (auto x : best)
			//~ cout << x << " ";
		//~ cout << endl;
		cout << best[n-1] << "\n";
	}
	
	
	return 0;
}
