#include <bits/stdc++.h>
using namespace std;

int main(void){
	string str,cmpstr,temp;
	vector<string> list;
	set<string> cmp;
	int i,j;

	while(cin >> str){
		list.push_back(str);
	}

	for(i=0;i<list.size();i++){
		for(j=0;j<list.size();j++){
			if(list[j] == list[i]){
				continue;
			}
			else{
				cmpstr = list[i]+list[j];
				cmp.insert(cmpstr);
			}
		}
	}

	for(auto it: cmp){
		if(it == temp){
			continue;
		}
		cout << it << endl;
		temp = it;

	}
}