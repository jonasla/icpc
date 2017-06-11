#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <map>
 
#define forn(i,n) for(int i=0;i<(int)(n); i++)
 
typedef long long tint;
 
using namespace std;

tint LETRAS_ALFABETO = 26; // alfabeto ingles de 'a' - 'z'

tint MAX_LETRAS = 52; // Notar que el enunciado dice que pueden 
					  // ser mayusculas y minusculas.
					  // Aunque en los ejemplos son todas minusculas.
/****************
* Nodo del Trie *
****************/

struct Trie 
{
	tint cantidadPrefijos; 	// Indica la cantidad de prefijos que  
							// utilizan al nodo
	map<char,Trie> hijos;	// map con los hijos del nodo.
	Trie() 		// Inicializacion de un nodo
	{
		cantidadPrefijos = 0;
		hijos = {};	// Un nodo que no fue creado, no tiene hijos
	}
};


/*******************
* Funcion Auxiliar *
*******************/

// 'a' - 'z' -> 0-25
// 'A' - 'Z' -> 26-51

tint char2Number (char x)
{
	if (x < 'a') 	// es mayuscula
		return LETRAS_ALFABETO + x - 'A';
	else 			// es minuscula
		return x - 'a';
}

/*********************
* Funciones del Trie *
*********************/

/* Como precondicion de "agregarPalabra" se tiene que:
  
 1) Para agregar una palabra entera, se debe llamar con "trie" como el 
 * nodo raiz del trie, e "indice" igual a cero.
 2) 0 <= indice <= palabra.size()

*/ 

void agregarPalabra (Trie &trie, string &palabra, tint indice)
{
	tint n = palabra.size();
	
	trie.cantidadPrefijos++;
	if (indice < n)
		agregarPalabra(trie.hijos[palabra[indice]],palabra,indice+1);
}

/* Como precondicion de "prefijosPalabra" se tiene que:
  
 * 1) La palabra tiene que haber sido agregada antes al Trie
 * 2) 0 <= indice <= palabra.size()

*/ 

tint prefijosPalabra (Trie &trie, string &palabra, tint indice)
{
	tint n = palabra.size();
	if (indice < n)
		return prefijosPalabra(trie.hijos[palabra[indice]],palabra,indice+1);
	else
		return trie.cantidadPrefijos;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Trie trie = Trie(); 	// Creamos la raiz del trie
		
		
	return 0;
}

