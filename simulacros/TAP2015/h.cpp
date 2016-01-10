#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define forsn(i,s,n) for (int i = (s); i <(int) (n); i++)
#define forn(i,n) for (int i = 0; i <(int) (n); i++)

typedef long long tint;

tint aEntero (string s)
{
	int n = s.size();
	tint pot = 1;
	tint resultado = 0;
	for (int j = n-1; j >= 0; j--)
	{
		resultado += (s[j]-'0')*pot;
		pot *=10;
	}
	return resultado;
}

string aString (tint x)
{
	map<tint, string> cifras;
	cifras[0] = "0";
	cifras[1] = "1";
	cifras[2] = "2";
	cifras[3] = "3";
	cifras[4] = "4";
	cifras[5] = "5";
	cifras[6] = "6";
	cifras[7] = "7";
	cifras[8] = "8";
	cifras[9] = "9";
	string ans = "";
	while (x != 0)
	{
		ans = cifras[x%10] + ans;
		x/=10;
	}
	return ans;
	
	
}



int main()
{
	string s1,s2;
	while(cin >> s1 && s1 != "0"){
		s2 = s1;
		sort(s1.begin(),s1.end());
		tint ans = 1;
		tint resultado = (aEntero(s2) - aEntero(s1));
		while (resultado != 0)
		{
			s1 = aString(resultado);
			s2 = s1;
			sort(s1.begin(),s1.end());
			resultado = (aEntero(s2) - aEntero(s1));
			ans++;
			
		}
		cout << ans << endl;
		
	}
	return 0;
}
