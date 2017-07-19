#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

typedef long long tint;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < (tint) n; i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint) n; i++)

//~ const tint MAXN = 100050;
//~ tint p[MAXN];
//~ vi primos;

//~ void criba() {
	//~ for(int i=4; i<MAXN; i+=2) p[i] = 2;
	//~ for(int i=3; i*i<MAXN; i+=2)
		//~ if (!p[i]) for (int j=i*i; j<MAXN; j+=2*i) p[j] = i;
//~ }

//~ void prims() {
	//~ forsn(i,2,MAXN) if (!p[i]) primos.push_back(i);
	//~ reverse(primos.begin(), primos.end());
//~ }

//~ vi fact(tint n) {
	//~ vi r;
	//~ for(auto e : primos) {
		//~ while(n % e == 0) {
			//~ r.push_back(e);
			//~ n /= e;
		//~ }
		//~ if (e*e > n) break;
	//~ }
	//~ if (n!=1) r.push_back(n);
	//~ return r;
//~ }

void divs(tint cur, vi &f, tint s, tint e, vi &d) {
	if (s == e) d.push_back(cur);
	else {
		tint m;
		for (m=s+1; m<e && f[m] == f[s]; m++);
		for (int i=s; i<=m; i++) {
			divs(cur, f, m, e, d);
			cur *= f[s];
		}
	}
}

//////////////////////////////////////////////////

const tint semilla = 38532164;

mt19937 gen(semilla);

tint mult(tint a, tint b, tint m)
{
	
	int largestBit = 0;
	while( (b >> largestBit) != 0)
		largestBit++;
	
	
	tint ans = 0;
	for(tint currentBit = largestBit - 1; currentBit >= 0; currentBit--)
	{
		ans = (ans + ans);

		if (ans >= m)
			ans -= m;

		if ( (b >> currentBit) & 1)
		{ 
			ans += a;
			if (ans >= m)
				ans -= m; 
		}
	}
	return ans;
}


tint potLogMod (tint x, tint y, tint nmod) // Calcula: (x^y) mod nmod
{
	tint ans = 1;
	while (y > 0)
	{
		if (y % 2)
			ans = mult(x,ans,nmod);
		x = mult(x,x,nmod);
		y /= 2;
	}
	return ans;
}


bool esPrimoRM (tint n)
{
	if (n <= 1)
		return false;
	else if (n <= 3)
		return true;
	else if (n % 2 == 0)
		return false;
	else
	{
		
		uniform_int_distribution<tint> dis(2, n-2);
		tint kOrig = 0, m = n-1;
		while (m % 2 == 0)
		{
			kOrig++;
			m /= 2;
		}
		bool esPrimo = true;
		vector<tint> testigos = {2,3,5,7,11,13,17,19,23,29,31,37, dis(gen), dis(gen), dis(gen), dis(gen), dis(gen)};
		for (auto a : testigos)
		{
			if (a < n)
			{
				tint b = potLogMod(a,m,n), k = kOrig;
				if (b == 1 or b == n-1)
					continue;
				else
				{
					forn(j,k)
					{
						b = mult(b,b,n);
						if (b == n-1)
							break;
						else if (b == 1)
						{
							esPrimo = false;
							break;
						}
					}
					
					if (b != n-1)
					{
						esPrimo = false;
						break;
					}
				}
			}
		}
		return esPrimo;
	}
}

tint gcd (tint a, tint b)
{
	if (a == 0)
		return b;
	return gcd (b % a, a);
}


//~ void factorizar (tint n, unordered_map<tint,tint> &f)
void factorizar (tint n, vi &f)
{
	while (n > 1)
	{
		if (esPrimoRM(n))
		{
			//~ f[n]++;
			f.push_back(n);
			n /= n;
		}
		else
		{
			
			uniform_int_distribution<tint> dis(1, n-1);
			tint a = dis(gen), b = dis(gen), x = 2, y = 2, d;
			
			do
			{
				x = (mult(x,x,n) + mult(a,x,n) + b) % n;
				y = (mult(y,y,n) + mult(a,y,n) + b) % n;
				y = (mult(y,y,n) + mult(a,y,n) + b) % n;
				d = gcd(abs(x-y),n);
			}
			while (d == 1);
			if (d != n)
			{
				factorizar(d,f);
				n /= d;
			}
				
		}
	}
}


//////////////////////////////////////////////////

unordered_map<tint, tint> sols;
vi dameDivs(tint N) {
	vi d;
	vi f;
	factorizar(N,f);
	sort(f.begin(), f.end());
	
	divs(1, f, 0, f.size(), d);
	sort(d.begin(), d.end());
	return d;
}

tint dameSol(tint N) { 
	if (sols.find(N) != sols.end()) return sols[N];
	else {
		vi div = dameDivs(N);
		
		if (div.size() <= 2) {
			for (auto d : div) {
				sols[d] = 1;
			}
			return 1;
		} else {
			tint lasol = 0;
			for (auto d : div) {
				if (d == 1) continue;
				if (d*d > N) break;
				tint s1 = d;
				tint s2 = N / d;
				
				tint sol1 = dameSol(s1);
				tint sol2 = dameSol(s2);
				
				tint r = sol1 * sol2;
				if (s1 != s2) r*=2;
				lasol += r;
			}
			sols[N] = lasol;
			return lasol;
		}
	}
}



int main()
{
	//~ criba();
	//~ prims();
	
	//~ forn(i,10) cout << primos[i] << endl;
	
	//~ forsn(i,2,16) cout << i << " " << p[i] << endl;

	//~ vi div;
	//~ vi f;
	//~ factorizar(10000019*12, f);
	//~ for (auto e : f) cout << e << endl;
	//~ cout << endl;
	
	//~ divs(1, f, 0, f.size(), div);
	//~ for(auto e : div) {
		//~ cout << e << endl;
	//~ }
	
	tint T; cin >> T;
	while(T--) {
		tint N; cin >> N;
		
		cout << dameSol(N) << endl;
		
	}
	return 0;
}
