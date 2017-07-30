#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < tint(n); i++)

struct Pet
{
	tint animal,index;
	Pet (tint aa, tint ii)
	{
		animal = aa;
		index = ii;
	}
};

int main()
{
	tint caso;
	cin >> caso;
	forn(cada,caso)
	{
		tint c,d,v;
		cin >> c >> d >> v;
		vector<pair<Pet,Pet> > viewers (v, {Pet(0,0),Pet(0,0)}); 
		forn(i,v)
		{
			string in,out;
			cin >> in >> out;
			tint a1 = (in[0] == 'C'), a2 = (out[0] == 'C'); // 0 Perro | 1 Gato
			tint n1 = tint(stoi(in.substr(1),nullptr,10)-1), n2 = tint(stoi(out.substr(1),nullptr,10)-1);
			viewers[i] = {Pet(a1,n1),Pet(a2,n2)};
		}
		tint best = 0;
		forn(i,c) // Gato i afuera
		{
			tint japi = 0;
			forn(j,v)
				japi += (viewer[j].second.animal == 1)
		}
	}
	return 0;
}
