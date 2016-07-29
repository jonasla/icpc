#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define forn(i,n) for(long long i=0; i<(long long)n; i++)
#define forsn(i,s,n) for(long long (i)=s; i<(long long)n; i++)

typedef long long tint;
typedef long double ldouble;

vector<tint> base8 (tint x)
{
	vector<tint> ans;
	while (x > 0)
	{
		ans.push_back(x%8);
		x/= 8;
	}
	if (ans.empty())
		return {0};
	else
		return ans;
}


int main()
{
	tint a,b,p;
	while (cin >> a >> b >> p)
	{
		ldouble aa = ldouble(a), bb = ldouble(b), pp = ldouble(p);
		tint ans = 0, aux1 = p, aux2 = p;
		while (aux2 <= b)
		{
			ldouble aux = ldouble(aux2);
			ans += b/aux2;
			if(aux * pp > bb) break;
			aux2 *= p;
			
		}
		while (aux1 <= (a-1))
		{
			ldouble aux = ldouble(aux1);
			ans -= (a-1)/aux1;
			if(aux * pp > aa-1) break;
			aux1 *= p;
			
		}
		vector<tint> ansPosta = base8(ans);
		reverse(ansPosta.begin(), ansPosta.end());
		for (auto x : ansPosta)
			cout << x;
		cout << endl;
	}
}
