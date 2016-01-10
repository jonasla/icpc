#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <tuple>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stdio.h>



#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl

typedef long long tint;
typedef unsigned long long utint;

using namespace std;

void imprimirVector (vector<int> v)
{
	if (!v.empty())
	{ 
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}
	else
		cout << "[]" << endl;
}

int log2(int n)
{
	int k = 0;
	int p = 1;
	while(p < n)
	{
		k++;
		p*= 2;
	}
	return k;
}

vector<int> f (vector<int> a, vector<int> b)
{
	vector<int> d;
	int n = a.size();
	forn(i,n)
	{
		d.push_back((a[i]+b[i])/2);
		d.push_back((a[i]-b[i])/2);
	}
	return d;
}

int main()
{
	int n;
	cin >> n;
	while(n != 0)
	{
		int first;
		cin >> first;
		if (n == 1)
			cout << first << endl;
		else
		{
			vector<vector<int> > sb (log2(n));
			int k = 1;
			forn(i,log2(n))
			{
				forn(j,k)
				{
					int aux;
					cin >> aux;
					sb[i].push_back(aux);
				}
				k*=2;
			}
			vector<int> a = {first};
			forn(i,log2(n))
				a = f(a,sb[i]);
			forn(i,n-1)
				cout << a[i] << " ";
			cout << a[n-1];
			cout << endl;
		}
		cin >> n;
	}
	return 0;
}



