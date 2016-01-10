#include <iostream>

using namespace std;

typedef long long ull;

const ull nmod = 1000000007;

ull deK[50010];
ull hastaK[50010];

void llenarTablas(){
	deK[0] = 1;
	hastaK[0] = 1;
	
	for(int i=1; i<50010; i++){
		deK[i] = (nmod + ((deK[i-1]*hastaK[i-1]) % nmod) - (((deK[i-1]*(deK[i-1]-1))/2) % nmod)) % nmod;
		hastaK[i] = (deK[i] + hastaK[i-1]) % nmod;
	}
	
}

ull divmod(ull n, ull d){
	while(n % d)
		n += nmod;
	
	return ((n/d) % nmod);
}

int main(){
	llenarTablas();

	ull K;
	while(cin >> K && K != 0){
		ull res = 0;
		if(K % 2){		// Impar
			ull A = deK[(K-1)/2];
			ull AAm1 = (A*(A-1)) % nmod;
			ull B = hastaK[((K-1)/2) - 1];
			
			res = A;													// Elegir 3 iguales de altura (K-1)/2
			res = (res + ((divmod(AAm1, 6)*(A-2)) % nmod)) % nmod;		// + Elegir 3 distintos de altura (K-1)/2
			res = (res + AAm1) % nmod;									// + Elegir 2 iguales y 1 distinto de altura (K-1)/2
			
			ull dosIgualesDistintos = (A + divmod(AAm1, 2)) % nmod;		// 2 iguales + 2 distintos de altura (K-1)/2
			
			res = (res + ((dosIgualesDistintos*B) % nmod)) % nmod;		// + Elegir 2 de altura (K-1)/2 y otro mas chico
			
			cout << res << endl;
		}else{			// Par
			res = ((deK[K/2]*(deK[K/2]-1)) / 2) % nmod;					// Elegir 2 distintos de altura exactamente K/2
			res = (res + deK[K/2]) % nmod;								// + Elegir 2 iguales de altura exactamente K/2
			
			cout << res << endl;
		}
	}
	return 0;
}
