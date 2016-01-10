#include <iostream>
#include <deque>
#include <vector>

#define forn(i,n) for(int i = 0; i < (int) (n);i++)

using namespace std;

deque<long long> baseN (long long m, long long n)
{
	deque<long long> num;
	while (m > 0)
	{
		num.push_front(m % n);
		m /= n;
	}
	return num;
	
}


int main()
{
	
	long long n,Q;
	cin >> n >> Q;
	while( n != 0)
	{
		vector<string> canciones (n);
		forn(i,n)
			cin >> canciones[i];
		forn(i,Q)
		{
			long long k;
			cin >> k;
			long long q = 1;
			long long nAlaq = n;
			long long suma = n;
			long long nivel = n;
			while (suma < k)
			{
				q++;
				nAlaq *= n;
				nivel = q*nAlaq;
				suma += nivel; 
				
			}
			suma -= nivel;
			k = k - suma - 1;
			long long pos = k % q;
			k /= q;
			deque <long long> desarrollo = baseN(k,n);
			cout << canciones[desarrollo[pos]] << endl; ;	
			
		}
		
		
		
		cin >> n >> Q;
	}
	return 0;
}
