#include <iostream>
#include <vector>

#define forn(i,n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long tint;

const tint maxN = 101;
vector<tint> a (maxN,0);
vector<tint> b (maxN,0);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	cin >> n;
	forn(ronda,n)
	{
		tint aa, bb;
		cin >> aa >> bb;
		a[aa]++;
		b[bb]++;
		vector<tint> aq = a;
		vector<tint> bq = b;
		tint i = 1, j = maxN-1, maxi = -1;
		while (i < maxN && j >= 0)
		{
			while (aq[i] == 0)
				i++;
			while (bq[j] == 0)
				j--;
			if (i < maxN && j >= 0)
			{
				tint r = min(aq[i],bq[j]);
				aq[i] -= r;
				bq[j] -= r;
				maxi = max(maxi,i+j);
			}
		}
		cout << maxi << "\n";
	}
	return 0;
}

