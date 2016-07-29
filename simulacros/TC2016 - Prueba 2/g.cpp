#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int (i) = 0; i < int(n); i++)

using namespace std;

typedef long long tint;

const vector<vector<tint> > jugadas = {{2,1,0,2},{1,1,1,1},{0,0,1,1},{0,3,0,0},{1,0,0,1}};

int gana[9][9][9][9];

bool esGanador (tint a, tint b, tint c, tint d)
{
	if (a >= 0 && b >= 0 && c >= 0 && d>= 0)
	{
		if (gana[a][b][c][d] != -1 && gana[a][b][c][d])
			return true;
		else if (gana[a][b][c][d] != -1)
			return false;
		else
		{			
			bool funciona = false;
			for (auto j : jugadas)
				funciona |= ((j[0] <= a) && (j[1] <= b) && (j[2] <= c) && (j[3] <= d));
			if (!funciona)
			{
				gana[a][b][c][d] = 0;
				return false;
			}
			else
			{
				bool ans = false;
				for (auto j : jugadas)
					ans |= !esGanador(a-j[0],b-j[1],c-j[2],d-j[3]);
				if (ans)
					gana[a][b][c][d] = 1;
				else
					gana[a][b][c][d] = 0;
				return ans;
			}
		}
	}
	else
		return true;
}

int main()
{
	tint n;
	cin >> n;
	forn(i,9)forn(j,9)forn(k,9)forn(l,9)
		gana[i][j][k][l] = -1;
	forn(i,n)
	{
		tint a,b,c,d;
		cin >> a >> b >> c >> d;
		if (esGanador(a,b,c,d))
			cout << "Patrick" << endl;
		else
			cout << "Roland" << endl;
	}
	return 0;
}
