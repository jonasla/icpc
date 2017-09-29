#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long tint;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)

const tint maxN = 100000; // largo del string

tint p[maxN], r[maxN], h[maxN],t,n;

bool sacmp (tint a, tint b)
{
	return p[(a+t)%n] < p[(b+t)%n];
}

void bwt(const string &s, tint nn)
{
	n = nn;
	tint bc[256]; // bc histograma de letras de s
	forn(i,256)
		bc[i] = 0;
	forn(i,n)
		++bc[tint(s[i])];
	forn(i,255)
		bc[i+1] += bc[i];
	forn(i,n)
		r[--bc[tint(s[i])]] = i;
	forn(i,n)
		p[i] = bc[tint(s[i])];
	
	tint lnb,nb = 1;
	for (t = 1; t < n; t *= 2)
	{
		lnb = nb;
		nb = 0;
		for (tint i = 0, j = 1; i < n; i = j++)
		{
			// calcula el siguiente bucket
			while (j < n && p[r[j]] == p[r[i]])
				j++;
			if (j-i > 1)
			{
				sort(r+i,r+j,sacmp);
				tint pk,opk = p[(r[i]+t)%n];
				tint q = i, v = i;
				for(; i < j; i++)
				{
					if ( (( pk = p[(r[i]+t)%n]) != opk) && !(q <= opk && pk < j) )
					{
						opk = pk;
						v = i;
					}
					p[r[i]] = v; 
				}
			}
			nb++;
		}
		if (lnb == nb)
			break;
	}
	// prim = p[0]
}

void lcp (const string &s)
{
	tint q = 0, j;
	forn(i,n)
	{
		if (p[i])
		{
			j = r[p[i]-1];
			while (q < n && s[(i+q)%n] == s[(j+q)%n])
				q++;
			h[p[i]-1] = q;
			if (q > 0)
				q--;
		}
	}
	
}

int main()
{
	// Uso de SUFFIX ARRAY y LCP : Agregar '$' al final del string
	// Uso de BWT (ROTACIONES) : Usar el string normal
	
	string s = "banana$";
	tint nn = s.size();
	forn(i,nn)
		cout << s.substr(nn-i-1,nn) << " : " << i << endl; // TESTEAR Suffix Array
		//~ cout << s.substr(i,nn-i) + s.substr(0,i) << " : " << i << endl; // TESTEAR BWT
	
	bwt(s,nn);
	cout << "---------" << endl;
	
	
	forn(i,nn)
		cout << s.substr(r[i],nn) << " : " << r[i] << endl; // TESTEAR Suffix Array
		//~ cout << s.substr(r[i],nn) + s.substr(0,r[i]) << " : " << r[i] << endl; // TESTEAR BWT
		
	lcp(s);
	cout << "---------" << endl;
	forn(i,n)
		cout << h[i] << endl;
	
	
	return 0;
}
