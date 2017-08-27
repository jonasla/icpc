#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef long long tint;

#define forn(i,n) for(tint i = 0; i < (tint) (n); i++)


const tint maxK = 2048;
const tint zero = 1024;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n,k;
	while (cin >> n >> k)
	{
		bitset<maxK> used;
		vector<tint> w; 
		forn(i,k)
		{
			tint a;
			cin >> a;
			if (!used[n-a + zero])
			{
				used[n-a + zero] = 1;
				w.push_back(n-a);
			}
		}
		
		bitset<maxK> visitado;
		vector<tint> vecinos = {zero}, nuevosVecinos = {};
		tint ans = -1, d = 1;
		while (!vecinos.empty())
		{
			tint actual = vecinos.back();
			vecinos.pop_back();
			for (auto x : w)
			{
				if ((0 <= actual + x && actual + x < maxK) && !visitado[actual+x])
				{
					visitado[actual+x] = true;
					nuevosVecinos.push_back(actual+x);
				}
			}
			
			if (vecinos.empty())
			{
				if (visitado[zero])
				{
					ans = d;
					break;
				}
				d++;
				vecinos = nuevosVecinos;
				nuevosVecinos = {};
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
