#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef int tint;

#define forn(i,n) for (tint  i = 0; i < (tint) (n); i++)
#define forsn(i,s,n) for (tint  i = (tint)(s); i < (tint) (n); i++)

const tint maxN = 1024;
const tint maxM = 11;

tint p[maxN];
tint r[maxN][maxM][maxN];

tint s = 0;

#define mod(q) ((((q) % maxM) + maxM) % maxM)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint t;
	cin >> t;
	forn(caso,t)
	{
		s = 0;
		forn(i,9)
		{
			tint d;
			cin >> d;
			forn(kk,d)
				p[s++] = i+1;
		}
		forn(i,s+1)
		forn(m,maxM)
		forn(k,s+1)
			r[i][m][k] = 0;
			
		r[0][0][0] = 1;
		// r[i][m][k] = 1 <=> usando p en el [0,i), logro formar usando k '+' la suma m (mod 11)
		forn(i,s)
		forn(m,maxM)
		forn(k,i+1)
		{
			if (r[i][m][k])
			{
				r[i+1][mod(m+p[i])][k+1] = 1;
				r[i+1][mod(m-p[i])][k] = 1;
			}
		}
		tint mini = 1000*s;
		forn(k,s+1)
			if (r[s][0][k])
				mini = min(mini,max(2*k-1, 2*(s-k)) - s);
		if (mini == 1000*s)
			cout << "-1\n";
		else
			cout << s+mini << "\n";
		
		
		
	}
	
	return 0;
}


