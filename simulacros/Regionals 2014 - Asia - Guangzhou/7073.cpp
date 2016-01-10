#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long tint;

struct Outlaw
{
	string name;
	tint killed;
	Outlaw(string nn, tint kk)
	{
		name = nn;
		killed = kk;
	}
};

bool operator < (Outlaw o1, Outlaw o2)
{
	return make_pair(o1.killed, o2.name) > make_pair(o2.killed, o1.name);
}

int main()
{
	tint n;
	cin >> n;
	while (n != 0)
	{
		vector<Outlaw> outlaw (n, Outlaw("",0));
		map<string, tint> amountKilled;
		for (tint i = 0; i < n; i++)
		{
			tint k;
			string nombre;
			cin >> nombre >> k;
			outlaw[i] = Outlaw(nombre,k);
			amountKilled[nombre] = k;
		}
		sort(outlaw.begin(),outlaw.end());
		for(tint i = 0; i < n; i++)
			cout << outlaw[i].name << " " << outlaw[i].killed << endl;
		tint m;
		cin >> m;
		for (tint i = 0; i < m; i++)
		{
			string nombre;
			cin >> nombre;
			tint k = amountKilled[nombre], minorRank = 1, majorRank = 1;
			for(tint j = 0; j < n; j++)
			{
				if (outlaw[j].killed > k)
					majorRank++;
				else if (outlaw[j].killed == k && outlaw[j].name < nombre)
					minorRank++;
			}
			if (minorRank == 1)
				cout << majorRank << endl;
			else
				cout << majorRank << " " << minorRank << endl;
		}
		cin >> n;
	}
	return 0;
}
