#include <iostream>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n);i++)

int main()
{
	int n;
	cin >> n;
	int caso = 1;
	while (n != 0)
	{
		vector<char> ascii;
		forn(i,10)
			ascii.push_back('0'+i);
		forn(i,26)
			ascii.push_back('A'+i);
		forn(i,26)
			ascii.push_back('a'+i);
		set<char> format;
		set<char> forbidden;
		bool laCague = false;
		forn(i,n)		
		{
			string sti,sto;
			cin >> sti >> sto;
			int l1 = sti.size(), l2 = sto.size();
			if (l1 < l2)
				laCague = true;
			else
			{
				for(int j = 1; j < l2-1; j++)
				{
					//cout << sti[j];
					if (sti[j] == sto[j] && (forbidden.find(sti[j]) == forbidden.end()))
						format.insert(sti[j]);
					else
						laCague = true;
				}
			}
			if (sti[l2-1] != '"' && (format.find(sti[l2-1]) != format.end()))
				laCague = true;
			else if (sti[l2-1] != '"')
				forbidden.insert(sti[l2-1]);
		}
		cout << "Case " << caso << ": ";
		int cavegol = ascii.size();
		int largo = forbidden.size();
		if (!format.empty())
		{
			char ultimo = *(format.rbegin());
			forn(i,cavegol)
				if ((forbidden.find(ascii[i]) == forbidden.end()) && ascii[i] < ultimo)
					format.insert(ascii[i]);
		}
		else
		{
			if (largo == cavegol)
				laCague = true;
			else
			{
				forn(i,cavegol)
				{
					if ((forbidden.find(ascii[i]) == forbidden.end()))
					{
						format.insert(ascii[i]);
						break;
					}
				}
			}
		}
		if (laCague)
			cout << "I_AM_UNDONE" << endl;
		else
		{
			cout << "[";
			for (auto letra : format)
				cout << letra;
			cout << "]" << endl;
		}
		caso++;
		cin >> n;
	}
	return 0;
}
