#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

typedef int tint;

#define forn(i,n) for (tint i = 0; i < (tint) (n); i++)
#define forsn(i,s,n) for (tint i = (tint)(s); i < (tint) (n); i++)

deque<tint>  aux;

void backtrack(deque<tint> &v, deque<tint> &w, bool &ans)
{
	tint n = tint(v.size()), m = tint(w.size());
	if (!ans)
	{
		if (v == w)
			ans = true;
		else if (n > m)
		{
			deque<tint> vOrig = v;
			forsn(i,1,n)
			{
				aux = {};
				forn(j,i)
				{
					aux.push_front(v.back());
					v.pop_back();
				}
				tint r = tint(v.size());
				forn(j,i)
				{
					if (r-j-1 < 0)
						v.push_front(aux[j]);
					else
						v[r-j-1] += aux[j];
				}
				backtrack(v,w,ans);
				v = vOrig;
			}
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	while (cin >> n)
	{
		deque<tint> v (n);
		forn(i,n)
			cin >> v[i];
		tint m;
		cin >> m;
		deque<tint> w (m);
		forn(i,m)
			cin >> w[i];
		bool ans = false;
		backtrack(v,w,ans);
		if ( ans )
			cout << "S\n";
		else
		{
			reverse(v.begin(),v.end());
			backtrack(v,w,ans);
			if ( ans )
				cout << "S\n";
			else
				cout << "N\n";
		}
		
		
	}
	return 0;
}
