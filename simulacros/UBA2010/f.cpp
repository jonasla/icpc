#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long tint;

#define forn(i,n) for(int i=0; i<(int)(n); i++)

int main()
{
	
	tint k;
	string st;
	cin >> k >> st;
	while (k != -1)
	{
		tint n = st.size();
		if (n > k)
			cout << 0 << endl;
		else
		{
			int i = 1, j = 0;
			vector<tint> bordes (n);
			bordes[0] = 0;
			while (i < n)
			{
				
				while (j > 0 && st[i] != st[j])
					j = bordes[j-1];
				if (st[i] == st[j])
					j++;
				bordes[i++] = j; 
			}
			tint c = bordes[n-1];
			if (c == n)
				cout << k-n << endl;
			else
				cout << (k-n)/(n-c) + 1 << endl;	
		}
		
		cin >> k >> st;
	}
	return 0;
}
