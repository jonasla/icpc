#include <iostream>
#include <vector>

using namespace std;

vector<int> calcularBordes(string st) {
	int i=1, j=0, n=st.size();
	vector<int> bordes(n, 0);
	while(i<n) {
		while(j>0 && st[i] != st[j])
			j = bordes[j-1];
		if (st[i] == st[j])
			j++;
		bordes[i++] = j;
	}
	return bordes;
}

int main() {
	vector<int> b1 = calcularBordes("abracadabra");
	for(auto i : b1) cout << i << " ";
	cout << endl;
	// Devuelve un arreglo, en la posición i
	// la longitud del máximo borde hasta st[i]. 
	// En el ejemplo "abracadabra" devuelve 
	// 0 0 0 1 0 1 0 1 2 3 4 
	
	// Ejemplo string matching
	vector<int> b2 = calcularBordes("abra$abracadabra");
	for(auto i : b2) cout << i << " ";
	cout << endl;
	// Devuelve 
	// 0 0 0 1 0 1 2 3 4 0 1 0 1 2 3 4 
	return 0;
}
