#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)

typedef unsigned long long utint;
typedef long long tint;
typedef pair<utint, utint> uu;
// ordenes	-	size

utint nmod = 1000000007;

utint facts[1010];

deque<tint> desarrollo(tint n)
{
	deque<tint> des;
	while (n > 0)
	{
		des.push_back(n%2);
		n /= 2;
	}
	return des;
}

tint invMod (tint a)
{
	tint ans = 1;
	deque<tint> des = desarrollo(nmod-2);
	tint acc = a;
	forn(k,des.size())
	{
		
		if (des[k] != 0)
			ans = (((ans * acc) % nmod) * des[k]) % nmod;
		acc = (acc*acc) % nmod;
	}
	return ans % nmod;
	
}


void dfs(int s, vector<vector<int > > &hijos, vector<uu> &dp){
	utint size = 1; utint prodOrd = 1; utint prodFacts = 1;
	
	for(auto &h : hijos[s]){
		dfs(h, hijos, dp);
		
		prodOrd = (prodOrd * dp[h].first) % nmod;
		size += dp[h].second;
		prodFacts = (prodFacts * facts[dp[h].second]) % nmod;
	}
	
	utint factSize = facts[size-1];
	
	//utint ordenesTotal = factSize / prodFacts; //= divmod(factSize, prodFacts);
	utint ordenesTotal = (factSize * invMod(prodFacts)) % nmod;
	//cout << prodFacts << " " << invMod(prodFacts) << endl;
	ordenesTotal = (ordenesTotal * prodOrd) % nmod;
	
	dp[s] = make_pair(ordenesTotal, size);
}


void factoriales(){
	facts[0] = 1;
	forsn(i,1,1010){
		facts[i] = (facts[i-1] * i) % nmod;
	}
}

int main(){
	factoriales();
	
	int T; cin >> T;
	forn(caso,T){
		int N; cin >> N;
		
		vector<int> padres(N, -1);
		vector<vector< int > > hijos(N, vector<int>());
		
		forn(i,N-1){
			int u, v; cin >> u >> v;
			u--; v--;
			padres[v] = u;
			hijos[u].push_back(v);
		}
		
		int root = -1;
		forn(i,N){
			if(padres[i] == -1) root = i;
		}
		
		vector<uu> dp(N);
		
		dfs(root, hijos, dp);
		
		cout << "Case " << caso+1 << ": " << dp[root].first << endl;
	}

	return 0;
}
