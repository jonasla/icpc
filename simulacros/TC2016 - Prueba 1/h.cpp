#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>

#define forn(i,n) for(int (i) = 0; i < int(n); i++)
#define forsn(i,s,n) for(int (i) = (s); i < int(n); i++)

using namespace std;

typedef long long tint;


map<tint, vector<tint> > vecinos = {{0 , {9,1}},{1 , {0,2}},{2 , {3,1}},
									{3 , {4,2}},{4 , {5,3}},{5 , {6,4}},
									{6 , {7,5}},{7 , {8,6}},{8 , {9,7}},
									{9 , {0,8}}};


const int maxN = 1000000;
const int maxDigitos = 6;
int p[maxN];
vector<tint> primos;

int gana[maxDigitos][maxN];
int visitado[maxDigitos][maxN];

void criba()
{
	for (int i = 4; i < maxN; i+= 2)
		p[i] = 2;
	for (int i = 3; i*i < maxN; i+=2)
		if (!p[i])
			for (int j = i*i; j < maxN; j+= 2*i)
				p[j] = i;
	p[0] = 1;
	p[1] = 1;
	forn(i,maxN)
		if(!p[i])
			primos.push_back(i);
}	

tint iesimoDigito (tint n, tint i)
{
	tint r = 1;
	forn(j,i)
		r*= 10;
	return (n/r)%10;
}

tint cambiarIesimoDigito(tint n, tint i, tint k)
{
	tint r = 1;
	forn(j,i)
		r*= 10;
	n -= r*iesimoDigito(n,i);
	n += r*k;
	return n;
}

int main()
{
	// PREPROCESO
	criba();
	tint t;
	cin >> t;
	forn(k,maxDigitos)
	{
		forn(i,maxN)
		{
			gana[k][i] = -1;
			visitado[k][i] = 0;
		}
	}
	
	tint r = 1;
	forn(k,maxDigitos)
	{
		r *= 10;
		deque<tint> v;
		deque<tint> nuevosVecinos;
		tint d = 0;
		for (auto x : primos)
		{
			if (x < r) 
			{
				visitado[k][x] = 1;
				gana[k][x] = d;
				v.push_front(x);
			}
			else
				break;
		}
		d++;
		while (!v.empty())
		{
			tint x = v.front();
			v.pop_front();
			forn(i,k+1)
				for (auto vecino : vecinos[iesimoDigito(x,i)])
				{
					tint u = cambiarIesimoDigito(x,i,vecino);
					if (!visitado[k][u])
					{
						
						nuevosVecinos.push_front(u);
						visitado[k][u] = 1;
						gana[k][u] = d;
					}
				}
			if (v.empty())
			{
				v = nuevosVecinos;
				nuevosVecinos.clear();
				d++;
			}
			
		}
	}
	
	//cout << iesimoDigito(12345,0) << endl;
	//cout << cambiarIesimoDigito(12345,0,1) << endl;
	//cout << " ------" << endl;
	//
	forn(caso,t)
	{
		tint k,n;
		
		scanf("%Ld %Ld",&k,&n);
		printf("%d\n",gana[k-1][n]);
		
	}
	return 0;
}
