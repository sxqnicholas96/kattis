#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,i,coursenum,max=0,maxcourse,ans = 0;
	string line;
	vector<set<int>> frosh;
	map<set<int>,int> f;
	vector<set<int>> maxcomb;
	set<int> emptyset;
	
	cin >> n;cin.get();

	for(i=0;i<n;i++){
		frosh.push_back(emptyset);

	}


	
	for(i=0;i<n;i++){
		getline(cin,line);
		stringstream ss(line);
		while(!ss.eof()){
			ss >> coursenum;
			frosh[i].insert(coursenum);
		}
	}
		
	for(auto it: frosh){
		f[it]++;
	}
	
	for(auto it: f){
		if(it.second > max){
			//cout << "test" << endl;
			max = it.second;
			maxcomb.clear();
			maxcomb.push_back(it.first);
		}
		else if(it.second == max){
			maxcomb.push_back(it.first);
		}
	}
	for(auto it: frosh){
		for(auto it2: maxcomb){
			if(it == it2){
				ans++;
			}	
		}
	}
	if(max == 1){
		cout << n;
	}
	else{
		cout << ans << endl;
	}
	
}