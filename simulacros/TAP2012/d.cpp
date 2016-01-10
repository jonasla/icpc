#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <tuple>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stdio.h>



#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl

typedef long long tint;
typedef unsigned long long utint;

using namespace std;

void imprimirVector (vector<int> v)
{
	if (!v.empty())
	{ 
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}
	else
		cout << "[]" << endl;
}

// se que son apellidos en la historia, de ahora en mas le digo nombre.

struct Par
{
	Par(string prefix, tint ind) // "prefijo" es el prefijo del nombre en la camiseta, e indice hace referencia al indice en la entrada del nombre del cual "prefijo" es prefijo. jaja, imposible de entender en una sola leida. 
	{
		prefijo = prefix;
		index = ind;
	}
	string prefijo;
	tint index;
};

bool operator < (Par p1, Par p2) // es para odrdenar a los nombres del segundo equipo por largo de prefijo.
{
	tint largo1 = p1.prefijo.size(), largo2 = p2.prefijo.size();
	return largo1 > largo2;
}


int main()
{
	tint n;
	cin >> n;
	while (n != -1)
	{
		// supongo que lo que quiero es un multiset, pero no se bien como usarlo, asi que voy a tener un set y un map por separado para hacer la misma funcion
		
		set<string> Ateam; // aca me voy a guardar todos los prefijos de nombres del primer equipo
		map<string, tint> AteamUsed; // aca me guardo cuantas veces aparecio cada prefijo.
		forn(i,n)
		{
			string nombre;
			cin >> nombre; 
			tint l = nombre.size(); 
			forn(j,l) // por cada prefijo del equipo A:
			{
				string prefijo = nombre.substr(0, l-j); 
				AteamUsed[prefijo]++; // aumento en uno la cantidad de veces que se uso el prefijo
				Ateam.insert(prefijo); // agrego el prefijo
			}
		}
		vector<Par> Bteam; // Aca voy a guardar todos los prefijos del equipo B y los asocio con el indice de entrada de la palabra para poder rastrearlo despues. OJO, guarda prefijos, no nombres completos, no es como Ateam.
		forn(i,n)
		{
			string nombre;
			cin >> nombre;
			tint l = nombre.size();
			forn(j,l) // por cada prefijo del equipo B:
			{
				string prefijo = nombre.substr(0, l-j); 
				Bteam.push_back(Par(prefijo,i)); // Agrego el prefijo con su correspondiente indice
			}
		}
		sort(Bteam.begin(), Bteam.end()); // aca los ordeno por tamaño, es MUY IMPORTANTE hacer esto para que el algoritmo sea correcto (hay un greedy de fondo que es claro que anda)
		tint total = 0; // contador de letras
		vector<bool> BteamUsed (n,false); // vector para saber si ya use un nombre del equipo B
		forn(i,Bteam.size()) // por cada prefijo del equipo B:
		{
			string palabra = Bteam[i].prefijo;
			tint indice = Bteam[i].index;
			if ( (Ateam.find(palabra) != Ateam.end() ) && AteamUsed[palabra] > 0 && !BteamUsed[indice]) // Si esta en el equipo A, todavia no me lo gaste en otro prefijo de mayor tamanho y no use un prefijo de este nombre:
			{
				BteamUsed[indice] = true; // ahora lo use
				tint l = palabra.size(); 
				total += l; // agrego la cantidad de letras del prefijo
				forn(j,l)
				{
					string prefijo = palabra.substr(0,l-j); 
					AteamUsed[prefijo]--; // y no puedo usar ninguno de los prefijos de este prefijo (notar que tampoco podemos usar los prefijos mas grandes del nombre original, pero no nos importa porque fuimos preguntando en orden)
				}
			}
		}
		cout << total << endl;
		
		cin >> n;
	}
	return 0;
}


