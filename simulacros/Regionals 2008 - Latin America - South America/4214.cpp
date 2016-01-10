#include <iostream>
#include <vector>


#define forn(i,n) for(int (i) = 0; (i) < (int)(n); i++ )
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)


typedef long long tint;
using namespace std;


tint noLeap[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
tint leap[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

bool isLeap(tint y)
{
	return (y % 4 == 0 && y % 100 != 0) or (y % 400 == 0);
}

vector<tint> siguiente(tint d, tint m, tint y)
{
	vector<tint> ans;
	d++;
	if ((isLeap(y) && d > leap[m]) or (!isLeap(y) && d > noLeap[m]))
	{
		m++;
		d = 1;
	}
	if (m > 12)
	{
		y++;
		m=1;
	}
	ans.push_back(d);
	ans.push_back(m);
	ans.push_back(y);
	return ans;
}


int main()
{
	tint n;
	while (cin >> n && n != 0)
	{
		tint da,ma,ya,ca,totalDays = 0, totalConsumption = 0;
		cin >> da >> ma >> ya >> ca;
		forsn(i,1,n)
		{
			tint dh,mh,yh,ch;
			cin >> dh >> mh >> yh >> ch;
			vector<tint> hoy;
			hoy.push_back(dh);
			hoy.push_back(mh);
			hoy.push_back(yh);
			if (siguiente(da,ma,ya) == hoy)
			{
				totalDays++;
				totalConsumption += (ch-ca);
			}
			da = dh;
			ma = mh;
			ya = yh;
			ca = ch; 
		}
		
		cout << totalDays << " " << totalConsumption << endl;
	}
	return 0;
}
