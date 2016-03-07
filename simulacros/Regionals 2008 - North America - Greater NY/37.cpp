
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(int)(n); (i)++)
#define forsn(i,s,n) for(int (i)=(s); (i)<(int)(n); (i)++)

bool esNumero (char x)
{
	return (x - '0' <= 9 && x - '0' >= 0);
}

string compactaMas (string s)
{
	int n = s.size();
	string ans;
	bool flag = false;
	forn(i,n)
	{
		int k = 0;
		while ( i < n && s[i] == '+')
		{
			i++;
			k++; 
			flag = true;
		}
		if (flag && !esNumero(s[i-k-1]) && esNumero(s[i]))
		{
			ans.push_back('+');
			flag = false;
		}
		else if (flag)
			ans += string(k,'+');
		if (i < n)
			ans.push_back(s[i]);
	}
	return ans;
}

string compactaCero (string s)
{
	int n = s.size();
	string ans;
	bool flag = false;
	forn(i,n)
	{
		int k = 0;
		while ( i < n && s[i] == '0')
		{
			i++;
			k++; 
			flag = true;
		}
		if (flag && !esNumero(s[i-k-1]) && esNumero(s[i]))
		{
			ans.push_back('0');
			flag = false;
		}
		else if (flag)
			ans += string(k,'0');
		if (i < n)
			ans.push_back(s[i]);
	}
	return ans;
}



string f (string s)
{
	int n = s.size();
	string ans;
	forn(i,n)
	{
		//if (!(i < n-1 && s[i] == '0' && esNumero(s[i+1])))
		//	ans.push_back(s[i]);
		if (i < n-1 && s[i] == '+' && esNumero(s[i+1]))
		{
		}
		
				
	}
}


int main()
{
	int n;
	cin >> n;
	forn(i,n)
	{
		string s1,s2;
		cin >> s1 >> s2;
		s1 = (compactaMas(s1));
		s2 = (compactaMas(s2));
		cout << s1 << " " << s2 << endl;
		//cout << comp(s1,s2) << endl;
		
	}
	return 0;
}
