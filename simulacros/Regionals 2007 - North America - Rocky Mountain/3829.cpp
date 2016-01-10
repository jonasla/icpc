#include <iostream>
#include <string>

using namespace std;

int comas[16];
string llaves[16];

void llenarComas(){
	comas[0] = 0; 		//0
	comas[1] = 0; 		//1
	//cout << comas[0] << " " << comas[1] << " ";
	for(int i=2; i<=15; i++){
		int suma = i-1;
		for(int j=0; j<i; j++){
			suma += comas[j];
		}
		comas[i] = suma;
		//cout << comas[i] << " ";
	}
	//cout << endl;
}

void llenarLlaves(){
	llaves[0] = "{}";
	llaves[1] = "{{}}";
	//cout << llaves[0] << endl;
	//cout << llaves[1] << endl;
	
	for(int i=2; i<=15; i++){
		string res;
		res += "{";
		for(int j=0; j<i; j++){
			res += llaves[j];
			if(j != i-1)
				res += ",";
		}
		res += "}";
		llaves[i] = res;
		//cout << res << endl;
	}
}

int contarComas(string &str){
	int com = 0;
	for(unsigned int i=0; i<str.length(); i++){
		if(str[i] == ',')
			com++;
	}
	
	return com;	
}

int queNum(string &str, int cantComa){
	if(cantComa == 0){	//0 o 1
		if(str == "{}")
			return 0;
		
		if(str == "{{}}")
			return 1;
			
	}else{
		for(int i=2; i<=15; i++){
			if(cantComa == comas[i])
				return i;
		}
	}
}




int main(){
	llenarComas();
	llenarLlaves();
	//cout << llaves[2] << endl;
	//cout << llaves[3] << endl;
	//cout << llaves[4] << endl;
	//cout << llaves[5] << endl;
	
	int T;
	cin >> T;
	while(T--){
		string num1, num2;
		cin >> num1 >> num2; 
		
		int comas1 = contarComas(num1);
		int comas2 = contarComas(num2);
		
		int queNum1 = queNum(num1, comas1);
		int queNum2 = queNum(num2, comas2);
		
		//cout << comas1 << " " << comas2 << endl;
		//cout << queNum1 << " " << queNum2 << " = " << queNum1 + queNum2 << endl;
		
		cout << llaves[queNum1 + queNum2] << endl;
		
	}
	
	return 0;
}
