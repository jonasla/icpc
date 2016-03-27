#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int (i)=0; i<(int)(n); (i)++)
#define forsn(i,s,n) for(int (i)=(s); i<(int)(n); (i)++)

int main()
{
	int n;
	while (cin >> n)
	{
		int ans = 0;
		vector<int> k (n);
		forn(i,n)
			cin >> k[i];
		int m;
		cin >> m;
		vector<int> d (m);
		forn(i,m)
			cin >> d[i];
		
		sort(k.begin(),k.end());
		forn(i,m)
		{
			//cout << "d[i] = "  << d[i] << endl;
			forn(j,n)
			{
				if (d[i] == k[j])
				{
					//cout << "i = " << i << endl << "------" << endl;
					ans++;
					break;
				}
				else if (d[i] > k[j])
				{
					int cinf = 0, csup = n-1;
					if (k[cinf] > (d[i] - k[j]) )
						csup = 0;
					else if (k[csup] == (d[i] - k[j]))
					{
						//cout << "i = " << i << endl << "------" << endl;
						ans++;
						break;
					}
					else if (k[csup] < (d[i] - k[j]))
						csup = 0;
					else
					{
						while (csup - cinf > 1)
						{
							int c = (cinf + csup)/2;
							if (k[c] > (d[i] - k[j]))
								csup = c;
							else
								cinf = c;
						}
						if (k[cinf] == (d[i] - k[j]))
						{
							ans++;
							//cout << "i = " << i << endl << "------" << endl;
							break;
						}
					}
				}
				else
					break;
			}
		}
		
		
		cout << ans << endl;
	}
	return 0;
}
