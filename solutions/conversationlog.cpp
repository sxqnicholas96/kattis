#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int M;
	map<string,int> freq;
	unordered_map<string,unordered_set<string>> wordl;
	unordered_set<string> names;
	string line,name,word;
	vector<pair<int,string>> list;
	priority_queue<pair<int,string>> pq;

	cin >> M; cin.get();

	while(M--){
		getline(cin,line);

		stringstream ss(line);
		ss >> name;
		//cout << name << endl;
		names.insert(name);
		//cout << names.size() << endl;
		while(!ss.eof()){
			ss >> word;
			freq[word]++;
			wordl[word].insert(name);
		}
	}

	for(auto it: wordl){
		//cout << "lol" << it.first << " " << it.second.size() << endl;
		if(it.second.size() == names.size()){
			//cout << it.first << freq.at(it.first) << endl;
			list.push_back(make_pair(-freq[it.first],it.first));
			//pq.push(make_pair(freq[it.first],it.first));
		}
	}

	sort(list.begin(),list.end());
	if(list.empty()){
		cout << "ALL CLEAR" << endl;
	}
	else{
		for(auto it: list){
			cout << it.second << endl;
		}
	}
/*	while(!pq.empty()){
		//cout << get<1>(list.back()) << " Num: " << get<0>(list.back()) <<  endl;
		cout << get<1>(pq.top()) << endl;
		pq.pop();
	}
*//*	for(auto it = prev(freq.end()); it != prev(freq.begin()); it--){
		cout << it->first << endl;
	}*/

}