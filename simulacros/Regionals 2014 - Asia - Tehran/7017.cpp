#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n); i++)
#define forsn(i,s,n) for(int i = s; i < (int) (n); i++)

int mod (int a)
{
	return ((a%60) + 60) % 60;
}

int div (int a)
{
	if (a < 0)
		return a/60 - 1;
	else
		return a/60;
}

int main()
{
	pair<int,int> total = make_pair(0,0);
	string s;
	while (cin >> s && s != "###")
	{
		if (s == "$$$")
		{
			total.first += div(total.second);
			total.second = mod(total.second);
			cout << total.first << ":";
			if (total.second / 10 == 0)
				cout << 0;
			cout << total.second << endl;
			total = make_pair(0,0);
		}
		else
		{
			int n = s.size(), k = 0;
			forsn(i,1,n)
				if (s[i] == '.' or s[i] == ':')
				{
					k = i;
					break;
				}
			int h,m;
			if (s.substr(1,k-1).size() == 0)
				h = 0;
			else
				h = stoi(s.substr(1,k-1));
			if (s.substr(k+1).size() == 0)
				m = 0;
			else
				m = stoi(s.substr(k+1));
				
			if (s[0] == '+')
			{
				total.first += h;
				total.second += m;
			}
			else
			{
				total.first -= h;
				total.second -= m;
			}	
		}
	}
	total.first += div(total.second);
	total.second = mod(total.second);
	cout << total.first << ":";
	if (total.second / 10 == 0)
		cout << 0;
	cout << total.second << endl;
	return 0;
}
