#include <deque>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

#define forn(i,n) for (tint i = 0; i <(tint) (n); i++)
#define forsn(i,s,n) for (tint i = (s); i <(tint) (n); i++)

typedef long long tint;

using namespace std;

deque<tint> desarrolloB (tint n, tint B)
{
	deque <tint> ans;
	while (n > 0)
	{
		ans.push_front(n%B);
		n /= B;
	}
	return ans;
}

tint mayores (deque<tint> desarrollo, tint m, vector<tint> v)
{
	
	tint h = desarrollo.size();
	if (h == 0)
		return 0;
	else
	{
		tint mAlaK = 1;
		forn(k,h-1)
			mAlaK *= m;
		tint primero = desarrollo.front();
		desarrollo.pop_front();
		tint total = 0;
		forn(i,v.size())
		{
			if (v[i] > primero)
				total += mAlaK;
			else if (v[i] == primero)
				total += mayores(desarrollo,m,v);
		}
		return total;
	}
}

tint menores (deque<tint> desarrollo, tint m, vector<tint> v)
{
	
	tint d = desarrollo.size();
	if (d == 0)
		return 0;
	else
	{
		tint mAlaK = 1;
		forn(k,d-1)
			mAlaK *= m;
		tint primero = desarrollo.front();
		desarrollo.pop_front();
		tint total = 0;
		forn(i,v.size())
		{
			if (v[i] < primero)
				total += mAlaK;
			else if (v[i] == primero)
				total += menores(desarrollo,m,v);
		}
		return total;
	}
}

int main()
{
	tint D,H,B;
	string s;
	cin >> D >> H >> B >> s;
	while (D != -1)
	{
		bool flag = false;
		vector<tint> v;
		forn(i,s.size())
			if (s[i] == 'S')
			{
				if (i == 0)
					flag = true;
				v.push_back(i);
			}
		tint m = v.size();
		deque<tint> desD = desarrolloB(D,B);
		deque<tint> desH = desarrolloB(H,B);
		tint h = desH.size(), d = desD.size();
		tint mAlaK = 1;
		if (!flag)
		{
			forn(k,d)
				mAlaK *= m;
		}
		else
		{
			forn(k,d-1)
				mAlaK *= m;
		}
		tint salvaLasPapas = mAlaK;
		tint total = 0;
		forsn(k,d,h+1)
		{
			total += mAlaK;
			mAlaK *= m;
		}
		if (flag)
			total = total * (m-1);
		total -= menores(desD,m,v);
		if (flag)
			total += salvaLasPapas;
		total -= mayores(desH,m,v);
		cout << total << endl;
		cin >> D >> H >> B >> s;
	}
	
	return 0;
}
