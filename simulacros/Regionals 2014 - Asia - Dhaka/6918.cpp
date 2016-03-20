#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int (i)=0; (i)<(ull)(n); (i)++)

typedef unsigned long long ull;
typedef vector<int> vi;


vi tobin(ull x){
	vi res;
	while(x > 0){
		res.push_back(x%2);
		x/=2;
	}
	return res;
}

void printv(vi vec){
	cout << "[";
	forn(i,vec.size()){
		if(i) cout << " ";
		cout << vec[i];
	}cout << "]\n";
}

ull twoTo(int x){
	ull a = 1;
	return (ull)(a<<x);
}

ull todec(vi vec){
	ull res = 0;
	//reverse(vec.begin(), vec.end());
	forn(i,vec.size()){
		res += vec[i]*twoTo(i);
	}
	
	return res;
}

int main(){
	//cout << twoTo(60) << endl;
	
	int N; cin >> N;
	
	forn(casito,N){
		ull A, B; cin >> A >> B;
		
		vi bina = tobin(A);
		vi binb = tobin(B);
		
		ull diff = B - A;
		int bindiff = binb.size() - bina.size();
		///
		vi resAnd, resOr;
		forn(i,bina.size()){
			ull mask1 = twoTo(i);
			ull partebaja = A & (mask1-1);
			
			// cambia
			if((mask1) - partebaja <= diff){
				resOr.push_back(1);
				resAnd.push_back(0);
			}else{
				resOr.push_back(bina[i]);
				resAnd.push_back(bina[i]);
			}
		}
		///
		forn(i,bindiff){
			resAnd.push_back(0);
			resOr.push_back(1);
		}
		
		//cout << resOr.size() << endl;
		///
		
		cout << "Case " << casito+1 << ": ";
		cout << todec(resOr) << " " << todec(resAnd) << endl;
		
	}
	return 0;
}
