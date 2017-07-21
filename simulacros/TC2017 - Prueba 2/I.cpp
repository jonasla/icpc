#include <iostream>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)

const tint INFINITO = 1e10;
const tint maxB = 1 << 17;
tint best[maxB];


int main()
{
	ios:: sync_with_stdio(false);
	cin.tie(NULL);
	tint k,n;
	while (cin >> k >> n)
	{
		
		vector<tint> x (n), y (n);
		forn(i,n)
			cin >> x[i] >> y[i];
		forn(b,1<<n)
		{
			tint maxX = -1, minX = INFINITO, maxY = -1, minY = INFINITO;
			forn(i,n)
			{
				if (b & (1 << i))
				{
					maxX = max(maxX,x[i]);
					maxY = max(maxY,y[i]);
					minX = min(minX,x[i]);
					minY = min(minY,y[i]);
				}
			}
			tint dx = abs(maxX - minX), dy = abs(maxY - minY);
			best[b] = 2*(dx + dy + 4*k);
				
		}
		forn(i,n)
			best[1<<i] = 8*k;
		forsn(t,2,n+1)
		{
			forn(b,1<<n)
			{
				if (__builtin_popcount(b) == t)
				{
					tint r = 0;
					do
					{
						best[b] = min(best[b],best[r] + best[b & (~r)]);
					}
					while (r = ((r-b) & b));
				}
			}
		}
		cout << best[(1<<n)-1] << "\n";
	}
	
	return 0;
}
