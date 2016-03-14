#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

#define forn(i,n) for(int i = 0; i < (int) (n); i++)
#define sqr(x) (x)*(x)
#define mp make_pair

typedef long long tint;

map<int, vector<int> > colores;

int distC(vector<int> c1, vector<int> c2){
	int res = 0;
	res += sqr(c1[0] - c2[0]);
	res += sqr(c1[1] - c2[1]);
	res += sqr(c1[2] - c2[2]);
	return res;
}

string colorName[20];

int main()
{
	colorName[1] = "White";
	colorName[2] = "Silver";
	colorName[3] = "Gray";
	colorName[4] = "Black";
	colorName[5] = "Red";
	colorName[6] = "Maroon";
	colorName[7] = "Yellow";
	colorName[8] = "Olive";
	colorName[9] = "Lime";
	colorName[10] = "Green";
	colorName[11] = "Aqua";
	colorName[12] = "Teal";
	colorName[13] = "Blue";
	colorName[14] = "Navy";
	colorName[15] = "Fuchsia";
	colorName[16] = "Purple";

	//colores["White"] = {255,255,255};
	colores[1] = {255,255,255};
	//colores["Silver"] = {192,192,192};
	colores[2] = {192,192,192};
	//colores["Gray"] = {128,128,128};
	colores[3] = {128,128,128};
	//colores["Black"] = {0,0,0};
	colores[4] = {0,0,0};
	//colores["Red"] = {255,0,0};
	colores[5] = {255,0,0};
	//colores["Maroon"] = {128,0,0};
	colores[6] = {128,0,0};
	//colores["Yellow"] = {255,255,0};
	colores[7] = {255,255,0};
	//colores["Olive"] = {128,128,0};
	colores[8] = {128,128,0};
	//colores["Lime"] = {0,255,0};
	colores[9] = {0,255,0};
	//colores["Green"] = {0,128,0};
	colores[10] = {0,128,0};
	//colores["Aqua"] = {0,255,255};
	colores[11] = {0,255,255};
	//colores["Teal"] = {0,128,128};
	colores[12] = {0,128,128};
	//colores["Blue"] = {0,0,255};
	colores[13] = {0,0,255};
	//colores["Navy"] = {0,0,128};
	colores[14] = {0,0,128};
	//colores["Fuchsia"] = {255,0,255};
	colores[15] = {255,0,255};
	//colores["Purple"] = {128,0,128};
	colores[16] = {128,0,128};
	
	int r, g, b;
	while(cin >> r >> g >> b && r != -1){
		vector<int> cc = {r,g,b};
		string minC = "";
		int minD = 1000000;
		for(auto &c : colores){
			//cout << c.first << " " << c.second.first << endl;
			int distI = distC(cc, c.second);
			if(distI < minD){
				minD = distI;
				minC = colorName[c.first];
			}
		}
		cout << minC << endl;
	}
	
	return 0;
}
