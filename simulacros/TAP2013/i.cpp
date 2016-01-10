#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <functional>
#include <string>
#include <tuple>

#include <iostream>
#include <sstream>

#include <utility>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl

using namespace std;

typedef long long tint;
typedef unsigned long long utint;
typedef pair<int, int> ii;
typedef vector<int> vi;

int F, C;
int grid[505][505];

void printMat(vector<vi> &mat){
	for(auto& vec : mat){
		for(auto& a : vec){
			cout << a << " ";
		}cout << endl;
	}
}

bool reachable(int segs){
	vector<vi> dist(F, vi(C, -1));
	
	queue<ii> Q;
	if(grid[0][0] > segs){
		dist[0][0] = 0;
		Q.push(make_pair(0,0));
	}
	
	int m_ud[] = {-1, 1, 0, 0};
	int m_lr[] = {0, 0, -1, 1};
	
	while(!Q.empty()){
		ii nod = Q.front(); Q.pop();
		
		//cout << "estoy en (" << nod.first << "," << nod.second << ")\n";
		
		forn(i, 4){
			if(nod.first + m_ud[i] >= 0 && nod.first + m_ud[i] < F && nod.second + m_lr[i] >= 0 && nod.second + m_lr[i] < C){	// pos valida
				//cout << "pos valida (" << nod.first + m_ud[i] << "," << nod.second + m_lr[i] << ")\n";
				if(dist[nod.first + m_ud[i]][nod.second + m_lr[i]] == -1){	// no visit
					//cout << "\tno visit\n";
					if(grid[nod.first + m_ud[i]][nod.second + m_lr[i]] > segs + dist[nod.first][nod.second] + 1){	// puedo moverme
						//cout << "\tpuedo mov\n";
						dist[nod.first + m_ud[i]][nod.second + m_lr[i]] = dist[nod.first][nod.second] + 1;
						Q.push(make_pair(nod.first + m_ud[i], nod.second + m_lr[i]));
					}
				}
			}
		}
		
	}
	
	//printMat(dist);
	
	return (dist[F-1][C-1] != -1);
}

int main(){
	cin >> F >> C;
	
	int lower, upper;
	lower = upper = 0;
	
	forn(i,F){
		forn(j,C){
			int e; cin >> e;
			upper = max(upper, e);
			grid[i][j] = e;
		}
	}
	
	//cout << upper << endl;
	/*
	cout << reachable(0) << endl;
	cout << reachable(1) << endl;
	cout << reachable(2) << endl;
	cout << reachable(3) << endl;
	
	cout << reachable(309) << endl;
	cout << reachable(310) << endl;
	cout << reachable(311) << endl;
	*/
	
	//cout << reachable(lower) << endl;
	//cout << reachable(upper) << endl;
	
	if(!reachable(lower)){
		cout << -1 << endl;
		return 0;
	}
	
	int middle;
	
	while(lower < upper){
		middle = lower + (upper-lower+1) / 2;
		
		//cout << "lower: " << lower << endl;
		//cout << "upper: " << upper << endl;
		//cout << "middle: " << middle << endl;
		
		if(!reachable(middle)){
			upper = middle-1;
		}else{
			lower = middle;
		}
	}
	
	cout << lower << endl;
	
	return 0;
}
