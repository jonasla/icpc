#include <iostream> 
#include <set> 
#include <vector> 
#include <map> 
#include <algorithm> 

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forsn(i,s,n) for(int i=s;i<(int)n;i++)

using namespace std;

typedef long long tint; 

const int MAXN = 10000000;  // hasta ahi se la re banca, y uno mas tambien 
// si p[i] = 0      => i es primo
// si p[i] = j != 0 => j divide a i (y j primo)
int p[MAXN];
// arma la criba
void criba() {
	for(int i=4; i<MAXN; i+=2) p[i]=2;
	for(int i=3; i<MAXN; i+=2)
		if(!p[i]) for(int j=2*i; j<MAXN; j+=i) p[j] = i;
}
// devuelve una factorizacion de N del tipo <primo,exponente>
map<int,int> factorizar(int N){
    map<int,int> res;
    while(p[N]){
        res[p[N]]++;
        N /= p[N];
    }
    res[N]++;
    return res;
}
// devuelve vector con los factores primos que dividen a N en orden
vector<int> factorizarLista(int N){
    vector<int> res;
    while(p[N]){
        res.push_back(p[N]);
        N /= p[N];
    }
    res.push_back(N);
    // puede omitirse si no interesa que esten ordenados
    sort(res.begin(), res.end());
    return res;
}

int main(){
	criba();
    int N;
    while(cin >> N && N != 0){
        vector<int> f = factorizarLista(N);
        for(auto ff : f) cout << ff << " ";
        cout << endl;
        map<int,int> fs = factorizar(N);
        for(auto ff : fs) cout << "(" << ff.first << "," << ff.second << ") ";
        cout << endl;
    }
	return 0;
}
