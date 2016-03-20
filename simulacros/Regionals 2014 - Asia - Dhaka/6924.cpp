#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(n); (i)++)
#define forsn(i,s,n) for(int (i)=s; (i)<(n); (i)++)

int maxNota = 161;

int main()
{
	int t;
	cin >> t;
	forn(test, t)
	{
		int n;
		cin >> n;
		vector<int> nota (maxNota,0);
		forn(i,n)
		{
			int grade;
			cin >> grade;
			nota[grade]++;
		}
		vector<int> sumaNota (maxNota,0);
		sumaNota[0] = nota[0];
		forsn(i,1,maxNota)
			sumaNota[i] = sumaNota[i-1] + nota[i];
		//cout << "Nota = ";
		//for (auto x : nota)
		//	cout << x << " ";
		//cout << endl;
		//cout << "sumaNota = ";
		//for (auto x : sumaNota)
		//	cout << x << " ";
		//cout << endl;
		tuple<int,int,int> c = make_tuple(160,160,160);
		double nd = double(n);
		nd /= 4.0;
		//cout << "nd = " << nd << endl;
		double ans = 999999999.0;
		//int casos = 0;
		int ii = 160,jj = 160,kk = 160;	
		forn(i,maxNota)
		forsn(j,i+1,maxNota)
		forsn(k,j+1,maxNota)
		{
	
			double value = abs(nd - double(sumaNota[i])) + abs(nd - double(sumaNota[j] - sumaNota[i])) + abs(nd - double(sumaNota[k] - sumaNota[j])) + abs(nd - double(sumaNota[maxNota-1] - sumaNota[k]));
			//if (casos < 1)
			//	cout << value << endl;
			//casos++;
			if (value < ans)
			{
				ans = value;
				if (ans == value)
					c = min(c,make_tuple(i,j,k));
				else
					c = make_tuple(i,j,k);
				ii = i;
				jj = j;
				kk = k;
			}
		}
		cout << "Case " << test+1 << ": " << ii << " " << jj << " " << kk << endl;
		//cout << "Case " << test+1 << ": " << get<0>(c) << " " << get<1>(c) << " " << get<2>(c) << endl; 
		
		
			
	}
	return 0;
}
