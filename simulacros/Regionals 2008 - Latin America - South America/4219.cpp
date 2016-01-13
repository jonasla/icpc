#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define debug(x) cout << #x << " = "  << x << endl
#define dforn(i,n) for(int i=(n)-1; i >=0; i--)

using namespace std;

struct carta{
	int r,s; //rank and suit; suit C < D < H < S
	bool jugada,efectoRealizado;
	carta();
	carta(int a,int b){r=a;s=b;jugada=false;efectoRealizado=false;}
};

bool operator<(const carta &lC, const carta &rC){
		return (lC.r<rC.r || (lC.r==rC.r && lC.s<rC.s));
}

istream & operator >>(istream &inpu, carta &c){
    int r,s; char tmp;
    cin >> r >> tmp;
            switch(tmp){
                case 'C': s=1;break;
                case 'D': s=2;break;
                case 'H': s=3;break;
                case 'S': s=4;break;
                default: ;
            }
    c = carta(r, s);
    return inpu;
}
carta actual;
queue<carta> deck;
bool clockwise = true;

struct jugador{
	vector<carta> mano;
	jugador(){mano.clear();puedoJugar=true;}
	bool puedoJugar;
	void levantar(int n){forn(i,n){mano.push_back(deck.front());deck.pop();}}
	bool jugar(){
		if(!actual.efectoRealizado){
			actual.efectoRealizado = true;
			switch(actual.r){
				case 1: //cout <<"levanto 1"<<endl;
					levantar(1);puedoJugar=false;break;
				case 7: //cout <<"levanto 2"<<endl;
					levantar(2);puedoJugar=false;break;
				case 11: puedoJugar=false;break;
				case 12: clockwise=!clockwise;puedoJugar=true;break;
				default: puedoJugar = true;
			}
		}
		else
			puedoJugar = true;
		if(puedoJugar){
			//cout << "puedo jugar"<<endl;
			sort(mano.begin(),mano.end());
			int n = mano.size();
			forn(i,n){
				//cout <<"\tchequear carta "<< mano[n-i-1].r << " "<<mano[n-i-1].s<<endl;
				if(mano[n-i-1].r==actual.r || mano[n-1-i].s==actual.s){
					//mano[n-i-1].jugada = true;
					actual = mano[n-i-1];
					mano.erase(mano.begin()+n-i-1);
					//cout << "tire carta " << actual.r <<" "<<actual.s<<endl;
					if(actual.r==12){clockwise=!clockwise;actual.efectoRealizado=true;}
					return mano.size()==0;
				}
			}
			//cout << "levanto 1"<<endl;
			carta tmp = deck.front();deck.pop();
			if(tmp.r==actual.r || tmp.s==actual.s){//cout << "la tiro"<<endl;
				actual = tmp;if(actual.r==12){clockwise=!clockwise;actual.efectoRealizado=true;}}
			else mano.push_back(tmp);
		}
		//else
			//cout << "no puedo jugar"<<endl;
		return false;
	}
};


int main(){
	#ifdef ACMTUYO
		freopen("19.in","r",stdin);
	#endif
	int p,m,n;
	
	while(cin >>p>>m>>n && p!=0){
		vector<jugador> jugadores(10);
		deck = queue<carta>();
		forn(i,p)forn(j,m){	//llenamos manos de los jugadores
			carta c;
			cin >> c;
			jugadores[i].mano.push_back(c);
		}
		forn(i,n-m*p){	//llenamos el mazo
			carta c;
			cin >> c;
			deck.push(c);
		}
		bool end = false;
		clockwise = true;
		int k = 0;
		actual = deck.front(); deck.pop();
		
		while(!end){
			//cout << "jugador "<<k<<endl;
			end = jugadores[k].jugar();
			
			if(!end){
				if(clockwise)k++;
				else k--;
				k = (k%p+p)%p;
			}
		}
		cout << k+1 << endl;
	}
}	
