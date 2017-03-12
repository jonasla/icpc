#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef long long tint;
typedef map<tint, tint> mii;

#define forn(i,n) for(tint i=0; i<(tint)n; i++)
#define forsn(i,s,n) for(tint i=(tint)s; i<(int)n; i++)
#define debug(x) cout << #x << " " << x << endl;

tint SOL = 0;
tint N, K;

void solve(mii m) {
	while(!m.empty()) {
		tint cartas = K;
		tint lastx = 0;
		while(cartas > 0){
			if (m.empty()) {
				break;
			}
			auto lejano = m.begin();
			tint dist = lejano->first;
			tint cant_total = lejano->second;
			
            //debug(dist)
            //debug(cant_total)
            
            // voy con las que me sobraron a uno nuevo
            // siempre deberia tener 0 entregadas en ese
            tint new_entregadas = min(cant_total, cartas);			
			cartas -= new_entregadas;
            SOL += abs(abs(dist) - abs(lastx));

            //debug(new_entregadas)
            //debug(cartas)
            //debug(SOL)
            
            // me fijo cuantas me faltan y hago las vueltas necesarias
            tint faltan = cant_total - new_entregadas;
            tint vueltas = (faltan + K - 1) / K;
            tint sobran = (new_entregadas + (K*vueltas)) - cant_total + cartas;
            SOL += abs(dist)*vueltas*2;
            
            //debug(faltan)
            //debug(vueltas)
            //debug(sobran)
            //debug(SOL)
            
            cartas = sobran;
			lastx = dist;
            m.erase(m.begin());
            
            //debug(lastx)
		}
		SOL += abs(lastx);
        //debug(SOL)
	}
}

int main() {
	cin >> N >> K;
	mii izq, der, izqc, derc;
	forn(i,N) {
		tint x, l; cin >> x >> l;
		if (x < 0) {
			izq[x] += l;
			izqc[x] = 0;
		}
		if (x > 0) {
			der[-x] += l;
			derc[-x] = 0;
		}
	}
	solve(izq);
	solve(der);
	
	cout << SOL << endl;
	return 0;
}
