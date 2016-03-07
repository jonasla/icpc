#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(int)(n); (i)++)
#define debug(x) cout << #x << " = "  << x << endl

typedef long long tint;

struct Cubo{
	int x,y,z;
	Cubo(int a, int b , int c){
		x = a;y=b;z=c;
	}
};

int canAdd(Cubo cubo,vector<Cubo> &cubos){
	int lados=0;
	forn(i,cubos.size()){
		//cout << "Comparando:"<<endl;
		//cout << cubo.x << " con " << cubos[i].x<<endl;
		//cout << cubo.y << " con " << cubos[i].y<<endl;
		//cout << cubo.z << " con " << cubos[i].z<<endl;
		if(cubo.x==cubos[i].x && cubo.y==cubos[i].y && abs(cubo.z-cubos[i].z)<=1) lados+=2;
		else if(cubo.z==cubos[i].z && cubo.y==cubos[i].y && abs(cubo.x-cubos[i].x)<=1) lados+=2;
		else if(cubo.x==cubos[i].x && cubo.z==cubos[i].z && abs(cubo.y-cubos[i].y)<=1)lados+=2;
	}
	return lados;
}

vector<string> split (string s, char x)
{
	tint anterior = 0, r = s.size();
	vector<string> termino;
	forn(i,r)
	{
		if (s[i] == x)
		{
			termino.push_back(s.substr(anterior, i - anterior));
			anterior = i+1;
		}
	}
	termino.push_back(s.substr(anterior, r - anterior));
	return termino;
}

int main(){
	int n;cin >> n;
	forn(i,n){
		int p;cin >> p;
		vector<Cubo> cubos;
		string coor;
		cout << i+1 << " ";
		cin >> coor;
		//cout << coor << endl;
		vector<string> coords = split(coor,',');
		int x = stoi(coords[0]);
		int y = stoi(coords[1]);
		int z = stoi(coords[2]);
		Cubo cubo(x,y,z);
		cubos.push_back(cubo);
		int interLados=0;
		bool f = true;
		int k = 0;
		forn(j,p-1){
			cin >> coor;
			coords = split(coor,',');
			int x = stoi(coords[0]);
			int y = stoi(coords[1]);
			int z = stoi(coords[2]);
			Cubo cubo(x,y,z);
			//debug(x);debug(y);debug(z);
			int lados = canAdd(cubo,cubos);
			//debug(lados);
			bool has = false;
			forn(i,cubos.size())
			{
				if(cubo.x==cubos[i].x && cubo.y==cubos[i].y && cubo.z==cubos[i].z)
					has = true;
			}
			
			if(lados>0 && !has){
				interLados+=lados;
				cubos.push_back(cubo);
			}
			else if(f){
				k = j+2;
				f = false;
			}
		}
		//
		if(f)
		cout << 6*p-interLados << endl;
		else
		cout << "NO " <<k<<endl;
	}
}
