#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

struct Person
{
	tint codeCoder, topForces, indice;
	Person(tint cc, tint tt, tint ii)
	{
		codeCoder = cc;
		topForces = tt;
		indice = ii;
	}
};

bool porCode (Person p1, Person p2)
{
	return make_tuple (p1.codeCoder,p1.topForces,p1.indice) > make_tuple (p2.codeCoder,p2.topForces,p2.indice); 
}

bool porTop (Person p1, Person p2)
{
	return make_tuple (p1.topForces,p1.codeCoder,p1.indice) > make_tuple (p2.topForces,p2.codeCoder,p2.indice); 
}

const tint maxN = 4194304;

tint fenwick[maxN];

tint sum (tint k)
{
	tint s = 0;
	while (k >= 1)
	{
		s += fenwick[k];
		k -= k&(-k);
	}
	return s;
}

void add (tint k, tint x)
{
	while (k <=maxN)
	{
		fenwick[k] += x;
		k += k&(-k);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	while (cin >> n)
	{
		vector<tint> ans (n,0);
		forn(i,maxN)
			fenwick[i] = 0;
		vector<Person> p (n,Person(0,0,0));
		forn(i,n)
		{
			tint r1,r2;
			cin >> r1 >> r2;
			p[i] = Person(r1,r2,i);
		}
		
		sort(p.begin(),p.end(),porCode);
		forn(i,n)
		{
			ans[p[i].indice] += n-i-1 + sum(p[i].topForces);
			add(p[i].topForces,1);
		}
		
		
			
		forn(i,n)
			cout << ans[i] << "\n";
	}
}
