#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint n;
	string strn;
	//~ cin >> n;
	getline(std::cin, strn);
	n = stoi(strn);
	forn(caso,n)
	{
		//~ char s[256];
		// En s hay que leer la linea entera tipo readline
		//~ cin.getline(s,256);
		string s;
		getline(cin, s);
		//~ cout << s << endl;
		vector<char> ans;
		for (auto x : s)
		{
			ans.push_back(x);
			if (x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u')
			{
				ans.push_back('p');
				ans.push_back(x);
			}
		}
		for (auto x : ans)
			cout << x;
		cout << "\n";
	}
	return 0;
}

