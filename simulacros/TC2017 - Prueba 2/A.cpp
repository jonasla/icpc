#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef int tint;
typedef long double ldouble;
typedef vector<tint> vi;

#define forn(i,n) for (tint i = 0; i < (tint)(n); i++)
#define forsn(i,s,n) for (tint i = (s); i < (tint)(n); i++)

tint W;
const tint MAXW = 1<<17;
const tint NMOD = 1000000000+7;
tint dp[MAXW][4][4][4][4];

const tint IZQ = 0;
const tint ARR = 2;
const tint DER = 3;
const tint ABJ = 1;

#define noCostado(i,j) ((i == DER && j != IZQ) || (i != DER && j == IZQ))
#define noVert(u,d) ((u == ABJ && d != ARR) || (u != ABJ && d == ARR))

int main() {
	ios:: sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> W;
	dp[0][ARR][ARR][ARR][ARR] = 1;
	
	forsn(f,1,W+1) {
		forsn(i2,1,4){
    forn(j2,4){
      if (noCostado(i2,j2)) continue;
    forn(k2,4){
      if (noCostado(j2,k2)) continue;
    forn(l2,3){
      if (noCostado(k2,l2)) continue;
    forsn(i1,1,4){
      if (noVert(i1,i2)) continue;
    forn(j1,4){
      if (noVert(j1,j2)) continue;
      if (noCostado(i1,j1)) continue;
    forn(k1,4){
      if (noVert(k1,k2)) continue;
      if (noCostado(j1,k1)) continue;
    forn(l1,3){
      if (noVert(l1,l2)) continue;
      if (noCostado(k1,l1)) continue;
      
      dp[f][i2][j2][k2][l2] = (dp[f][i2][j2][k2][l2] + dp[f-1][i1][j1][k1][l1]) % NMOD;
    }}}}}}}}
	}
	tint suma = 0;
	forn(i,4){
    if (i==1) continue;
	forn(j,4){
    if (j==1) continue;
	forn(k,4){
    if (k==1) continue;
	forn(l,4){
    if (l==1) continue;
		suma = (suma + dp[W][i][j][k][l]) % NMOD;
	}}}}
	cout << suma << "\n";

	return 0;
}
