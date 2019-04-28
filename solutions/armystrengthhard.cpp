#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int TC,numG,numMG,i,power;

	cin >> TC;

	while(TC--){
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		//unordered_map<int,int> gf,mgf;
		cin >> numG >> numMG;
		for(i=0;i<numG;i++){
			cin >> power;
			pq.push(make_pair(power,2));
			//gf[power]++;
		}
		for(i=0;i<numMG;i++){
			cin >> power;
			pq.push(make_pair(power,1));
			//mgf[power]++;
		}
		while(numG && numMG){
			if(pq.top().second == 1){
				numMG--;
/*				if(--mgf[pq.top().first] == 0){
					mgf.erase(pq.top().first);
				}*/
			}
			else{
				numG--;
/*				if(--gf[pq.top().first] == 0){
					gf.erase(pq.top().first);
				}*/
			}
			pq.pop();
			}
		if(numG){
			cout << "Godzilla" << endl;
		}
		else if(numMG){
			cout << "MechaGodzilla" << endl;
		}
		else{
			cout << "uncertain" << endl;
		}
	}
}