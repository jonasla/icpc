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

pair<vector<tint>,tint> inversiones(vector<tint> v)
{
	if (v.size() <= 1)
		return {v,0};
	else
	{
		tint n = v.size();
		tint med = n/2;
		vector<tint> v1,v2;
		forn(i,med)
			v1.push_back(v[i]);
		forsn(i,med,n)
			v2.push_back(v[i]);
		//~ cout << v1.size() << " " << v2.size() << endl;
		pair<vector<tint>,tint> r1 = inversiones(v1), r2 = inversiones(v2);
		tint f1 = 0, f2 = 0, t1 = r1.first.size(), t2 = r2.first.size();
		vector<tint> aux;
		while(f1 < t1 && f2 < t2)
		{
			if (r1.first[f1] <= r2.first[f2])
				aux.push_back(r1.first[f1++]);
			else
				aux.push_back(r2.first[f2++]);
		}
		while(f1 < t1)
			aux.push_back(r1.first[f1++]);
		while(f2 < t2)
			aux.push_back(r2.first[f2++]);
			
		tint ans = r1.second + r2.second;
		f1--;
		f2--;
		while (f1 >= 0)
		{
			while(f2 >= 0 && r1.first[f1] <= r2.first[f2])
				f2--;
			ans += f2+1;
			f1--;
		}
		return {aux,ans};
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	//~ cout << inversiones({2,2,1}).second << endl;
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
		ans = min(ans,inversiones(azul).second);
		
		sort(v.begin(),v.end(),porAzul);
		vector<tint> rojo (n);
		forn(i,n)
			rojo[i] = v[i].red;
		ans = min(ans,inversiones(rojo).second);
		cout << ans << "\n";
		
	}
	return 0;
}










