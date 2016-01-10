#include <iostream>
#include <deque>

using namespace std;

void printDeq(deque<bool> &vec){
	for(unsigned int i=0; i<vec.size(); i++){
		if(i) cout << " ";
		cout << vec[i];
	}
	cout << endl;
}

int main(){

	int n;
	cin >> n;
	while(n != 0){
		deque<bool> postes;
		
		for(int i=0; i<n; i++){
			int e; cin >> e;
			postes.push_back((bool)e);
		}
		
		//shifting
		int s = 0;
		while(!postes[n-1] && s < n){
			//cout << "shift\n";
			bool ult = postes[n-1];
			postes.pop_back();
			postes.push_front(ult);
			
			s++;
		}
		
		//printDeq(postes);
		
		int ps = 0;
		int cerosCon = 0;
		for(unsigned int i=0; i<postes.size(); i++){
			if(postes[i]){		// 1
				if(cerosCon > 0){
					ps += cerosCon / 2;
				}
				cerosCon = 0;
			}else{				// 0
				cerosCon++;
			}
		}
		// todos 0
		if(!postes[n-1]){
			ps += cerosCon / 2;
		}
		
		cout << ps << endl;
		
		cin >> n;
	}
	
	return 0;
}
