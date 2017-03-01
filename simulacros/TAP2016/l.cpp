#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; i++)
#define forsn(i,s,n) for(int i=int(s); i<(int)n; i++)
#define sqr(x) (x)*(x)
#define pb push_back

typedef long long tint;

int main()
{
	tint n,k;
	while (cin >> n >> k)
	{
		vector<tint> v (k);
		forn(i,k)
			cin >> v[i];
		tint max = 0, maxInd = -1;
		forn(i,k)
		{
			if (max < v[i])
			{
				max = v[i];
				maxInd = i;
			}
		}
		tint pasoAdelante = -1;
		bool todoAbajo = true;
		forsn(i,maxInd+1,k)
		{
			if (maxInd+1 == i)
				pasoAdelante = max - v[i];
			if (v[i-1] == 2 && v[i] == 1)
				todoAbajo = false;
			todoAbajo &= ((v[i-1] - v[i] == 1) or (v[i-1] - v[i] == 2));
		}
		for (tint i = maxInd-1; i >= 0; i--)
		{
			if (i == maxInd-1 && pasoAdelante == v[i+1] - v[i])
				todoAbajo = false;
			if (v[i+1] == 2 && v[i] == 1)
				todoAbajo = false;
			todoAbajo &= ((v[i+1] - v[i] == 1) or (v[i+1] - v[i] == 2));
		}
		if (todoAbajo)
			cout << "S\n";
		else
			cout << "N\n";
	}
}
