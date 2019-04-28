#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	int N,i;
	string line,name,food;
	map<string,set<string>> lol;

	cin >> N;cin.get();

	while(N){
		for(i=0;i<N;i++){
			getline(cin,line);
			stringstream ss(line);
			ss >> name;
			while(1){
				ss >> food;
				lol[food].insert(name);	
				if(ss.eof()){
					break;
				}
			}
		}

		for(auto it: lol){
			cout << it.first << " ";
			for(auto it2: it.second){
				cout << it2 << " ";
			}
			cout << endl;
		}
		lol.clear();
		cin >> N;cin.get();
		if(N){
			cout << endl;
		}	
	}

}