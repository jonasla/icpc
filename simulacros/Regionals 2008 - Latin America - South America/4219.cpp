#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)n;i++)

struct carta{
	int r;
	char s;
	bool done;
	bool usada;
	carta(int a, char b){r=a;s=b;done=false;usada=false;jugada=false;}
	bool jugada;
};
carta actual(1,'a');
deque<carta>sPile;

bool operator<(const carta &a, const carta &b){
	if(a.r<b.r || (a.r==b.r && a.s<b.s)|| a.jugada) return true;
	else return false;
}

struct jugador{
	vector<carta> mano;
	bool play;
	int c;
	
	jugador() {play=true;c=0;}
	
	bool puedoJugar(){
		sort(mano.begin(),mano.end());
		int n = mano.size();
		for(int i=n-1;i>=0;i--)
			if(mano[i].r==actual.r || mano[i].s==actual.s) {
				c = i;
				return mano[i].jugada;
			}
		return false;
	}
	bool gano(){bool gane=true;forn(i,mano.size())if(!mano[i].jugada)gane=false;return gane;}
	carta jugar(){mano[c].jugada = true;return mano[c];}
	void levantar(int k){forn(i,k){mano.push_back(sPile.front());sPile.pop_front();}}
};
bool play;
bool clockwise=true;

void efectoCartaActual(carta &actual, jugador &j){
	actual.done = true;
	switch(actual.r){
		case 1: 
			j.levantar(1);
			j.play = false;
			break;
		case 7: 
			j.levantar(2);
			j.play=false;
			break;
		case 11: 
			j.play = false;
			break;
		case 12: 
			clockwise = !clockwise; 
			j.play = true;
			break;
		default: 
			//cout << "no hice nada"<<endl;
			j.play = true;
			break;
	}
}


int main(){
	int p,m,n;
	while(cin >> p >> m >> n && p!=0){
	bool termino=false;
	clockwise=true;
	sPile.clear();
	vector<jugador> jugadores(10);
	
	int r;char s;
	forn(i,p)forn(j,m){cin >> r >> s;jugadores[i].mano.push_back(carta(r,s));}
	forn(i,n-m*p){cin >> r >> s;sPile.push_back(carta(r,s));}
	
	
	actual = sPile.front();sPile.pop_front();
	//cout <<"carta actual:" <<actual.r<<" "<<actual.s<<endl;
	int k = 0;
	int ganador;
	while(!termino){
		//cout << "jugador "<<k<<endl;
		if(!actual.done){
			//cout << "efct carta act\n";
			efectoCartaActual(actual,jugadores[k]);
			//cout << "efct carta act done\n";
		}else jugadores[k].play=true;
		if(jugadores[k].play){
			//cout << "puedo jugar 1"<<endl;
			if(!jugadores[k].puedoJugar()){
				actual = jugadores[k].jugar();
				//cout << "juego la carta "<<actual.r<<" "<<actual.s<<endl;
				termino = jugadores[k].gano();
				if(termino)ganador =k;
			}
			else{
				carta l = sPile.front();
				sPile.pop_front();
				if(l.r==actual.r || l.s==actual.s) actual=l;
				else jugadores[k].mano.push_back(l);
			}
		}
		//else cout <<"no puedo jugar"<<endl;
		if(clockwise)k++;
		else k--;
		
		k = (k%p+p)%p;
	}
	cout << ganador+1<<endl;
	}
	return 0;
}
