#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)

int main()
{ 

	string str1, str2;
	cin >> str1 >> str2;
	while(str1 != "*" && str2 != "*")
	{
		int n = str1.size();
		vector<bool> v (n);
		int total = 0;
		forn(i,n)
			v[i] = (str1[i] != str2[i]);
		bool prendido = false;
		forn(i,n)
		{
			if (v[i] && !prendido)
			{
				total++;
				prendido = true;
			}
			else if (!v[i])
				prendido = false;
		}
		cout << total << endl;
		cin >> str1 >> str2;
	}	
	return 0;
	
}
