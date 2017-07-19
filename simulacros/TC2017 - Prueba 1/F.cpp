#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint) n; i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint) n; i++)

struct Card
{
	tint red,blue;
	Card(tint rr, tint bb)
	{
		red = rr;
		blue = bb;
	}
};

bool porRojo (Card c1, Card c2)
{
	return make_pair(c1.red,c1.blue) < make_pair(c2.red,c2.blue);
}

bool porAzul (Card c1, Card c2)
{
	return make_pair(c1.blue,c1.red) < make_pair(c2.blue,c2.red);
}

const tint INFINITO = 1e15;

tint inversiones (vector<tint> &v, tint s, tint e)
{
	if (e - s == 1)
		return 0;
	else if (e - s == 2)
		return v[s] > v[e-1];
	else
	{
		tint med = (s+e)/2;
		tint s1 = inversiones(v,s,med), s2 = inversiones(v,med,e);
		vector<tint> v1,v2;
		forsn(i,s,med)
			v1.push_back(v[i]);
		forsn(i,med,e)
			v2.push_back(v[i]);
		sort(v1.begin(),v1.begin());
		sort(v2.begin(),v2.begin());
		tint i = v1.size() - 1, j = v2.size() - 1;
		tint ans = 0;
		while (i >= 0)
		{
			while (j >= 0 && v1[i] < v2[j])
				j--;
			ans += (j+1);
			i--;
		}
		return ans + s1 + s2;
	}
}

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	//~ vector<tint> w = {2,1};
	//~ cout << inversiones(w,0,w.size()) << endl;
	while (cin >> n)
	{
		vector<Card> v (n,Card(0,0));
		forn(i,n)
		{
			tint r,b;
			cin >> r >> b;
			v[i] = Card(r,b);
		}
		tint ans = INFINITO;
		sort(v.begin(),v.end(),porRojo);
		vector<tint> azul (n);
		forn(i,n)
			azul[i] = v[i].blue;
			
		ans = min(ans,inversiones(azul,0,n));
		sort(v.begin(),v.end(),porAzul);
		vector<tint> rojo (n);
		forn(i,n)
			rojo[i] = v[i].red;
		
		ans = min(ans,inversiones(rojo,0,n));
		
		cout << ans << "\n";
	}
}
 
