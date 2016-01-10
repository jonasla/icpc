#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
	
	int n;
	cin >> n;
	while (n != -1)
	{
		n--;
		set<long long> esta;
		vector<long long> x (n);
		long long total = 0;
		forn(i,n)
		{
			cin >> x[i];
			total += x[i];
			esta.insert(x[i]);
		}
		sort(x.begin(),x.end());
		long long med1 = x[n/2-1];
		long long med2 = x[n/2];
		int ans = 0;
		long long sol1 = med1*(n+1) - total;
		long long sol2 = med2*(n+1) - total;

		
		set<long long>::iterator fd1 = esta.find(sol1);
		set<long long>::iterator fd2 = esta.find(sol2);
		
		
		if (sol1 < med1 && fd1 == esta.end())
			ans++;
		if (sol2 > med2 && fd2 == esta.end())
			ans++;
		if (total % n == 0)
		{
			long long sol = total/n;
			set<long long>::iterator fd = esta.find(sol);
			if(sol > med1 && sol < med2 && fd == esta.end())
				ans++;
		}
		cout << ans << endl;
		cin >> n;
	
	}
	
	
	return 0;
}
