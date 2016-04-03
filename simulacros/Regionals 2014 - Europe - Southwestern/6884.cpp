#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cassert>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)

using namespace std;
typedef long long tint;

int value[10] = {0,1,2,3,4,5,6,7,8,9};
int pos[30];
int primeras[30];

tint word2number (string &w)
{
	tint p = 1, ans = 0, n = w.size();
	for (int i = n-1; i >= 0; i--)
	{
		ans += value[pos[w[i]-'A']]*p;
		p *= 10;
	}
	return ans;
}

int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	tint n;
	while (cin >> n)
	{
		fill(pos,pos+30,0);
		fill(primeras,primeras+30,0);
		vector<string> word (n);
		forn(i,n)
			cin >> word[i];
		set<char> primerasSet;
		set<char> letrasSet;
		for (auto w : word)
		{
			primerasSet.insert(w[0]);
			for (auto x : w)
				letrasSet.insert(x);
		}
		string letras;
		for (auto x : primerasSet)
			primeras[x-'A'] = 1;
		for (auto x : letrasSet)
			letras.push_back(x);
		forn(i,letras.size())
			pos[letras[i]-'A'] = i;
		tint ans = 0;
		while (next_permutation(value,value+10))
		{
			bool flag = false;
			forn(i,letras.size())
			{
				if (value[i] == 0 && primeras[letras[i]-'A'])
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				tint valor = 0;
				forn(i,n-1)
					valor += word2number(word[i]);
				ans += (valor == word2number(word[n-1]));
			}
		}
		tint p = 1;
		forsn(i,1,10-letras.size()+1)
			p *= i;
		
		cout << ans/p << endl;
	}
	return 0;
}



