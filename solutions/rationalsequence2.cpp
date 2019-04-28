#include <bits/stdc++.h>
using namespace std;

int main(void){
	int P,K,p,q;
	string track = "";
	
	cin >> P;
	
	while(P--){
		cin >> K;
		
		cin >> p; cin.get(); cin >> q;
		while( p>1 || q>1){
			if(p < q){
				track = "L" + track;
				q = q - p;
				
			}
			else{
				track = "R" + track;
				p = p - q;
			}
		}
		int N = 1;
		for(auto it: track){
			if(it == 'L'){
				N *= 2;
			}
			else if(it == 'R'){
				N = N*2 + 1;
			}
			
		}
		cout << K << " " << N << endl;
		track.clear();
		
	}
}