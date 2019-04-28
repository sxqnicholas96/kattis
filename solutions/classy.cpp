#include <bits/stdc++.h>
using namespace std;

typedef pair<string,string> stringstring;

string toHashCode(string line){
	string rank,hashcode;
	stringstream ss(line);
	hashcode.clear();
	while(getline(ss,rank,'-')){
		if(rank == "lower"){
			hashcode = "1" + hashcode;
		}
		else if( rank == "middle"){
			hashcode = "2" + hashcode;
		}
		else if( rank == "upper"){
			hashcode = "3" + hashcode;
		}
	}
	while(hashcode.size() != 10){
		hashcode = hashcode + "2";
	}
	
	return hashcode;
	
}

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int T,n;
	string name, line, dummy, lol = "==============================";
	vector<stringstring> vec;
	
	cin >> T;
	while(T--){
		cin >> n;
		while(n--){
			cin >> name >> line >> dummy;
			name.pop_back();
			vec.push_back(make_pair(toHashCode(line),name));
		}
		sort(vec.begin(),vec.end(),	[](stringstring a, stringstring b){
			if(a.first != b.first){
				return a.first > b.first;
			}
			else{
				return a.second < b.second;
			}
		
		});
		for(auto it: vec){
			cout << it.second << endl;
		}
		cout << lol << 	endl;
		vec.clear();
	}
}