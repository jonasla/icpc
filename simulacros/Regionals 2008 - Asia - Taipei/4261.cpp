#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>

typedef long long tint;
#define forn(i,n) for(tint i=0;i<(int)n;i++)
#define forsn(i,s,n) for(tint i=s;i<(int)n;i++)


using namespace std;

struct Respuesta
{
	tint penalty;
	vector<tint> camino;
	Respuesta (tint pp, vector<tint> cc)
	{
		penalty = pp;
		camino = cc;
	}
};

bool operator < (Respuesta r1, Respuesta r2)
{
	if (r1.penalty < r2.penalty)
		return true;
	else if (r1.penalty == r2.penalty)
	{
		tint l1 = r1.camino.size(), l2 = r2.camino.size();
		if (l1 < l2)
			return true;
		else if (l1 == l2)
			return (r1.camino < r2.camino);
		else 
			return false;
	}
	else
		return false;
}

int main()
{
	#ifdef ACMTUYO
		freopen("61.in","r",stdin);
	#endif
	tint n;
	cin >> n;
	while (n != 0)
	{
		vector<tint> a (n+1); // INDEXO DESDE 1
		vector<tint> b (n+1,0); // INDEXO DESDE 1
		forsn(i,1,n+1)
		{
			cin >> a[i];
			b[i] = b[i-1] + a[i];
		}
		vector<tint> aux = {0};
		Respuesta r = Respuesta(9999999999999,aux);
		vector<Respuesta> dp (n+1,r);
		dp[0] = Respuesta(0,aux);
		forsn(i,1,n+1)
		{
			forn(j,i)
			{ 
				Respuesta r = dp[j];
				vector<tint> newCamino = r.camino;
				newCamino.push_back(i);
				if (Respuesta(r.penalty + (b[i] - b[j] - 100)*(b[i] - b[j] - 100), newCamino) < dp[i])
					dp[i] = Respuesta(r.penalty + (b[i] - b[j] - 100)*(b[i] - b[j] - 100), newCamino);
			}
		}
		cout << "p=" << dp[n].penalty << endl;
		forn(i,dp[n].camino.size())
		{
			if (i % 30 == 0 && i != 0)
				cout << endl;
			cout << " " << dp[n].camino[i];
		}
		cout << endl;
		cin >> n; 
		if (n != 0)
			cout << endl;
	}
	return 0;	
}
