#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string word,longword,line;
	vector<string> list;

	while(!cin.eof()){
		getline(cin,word);
		longword = word;
		while(!cin.eof() && !word.empty()){
			//cout << "Input: " << word << endl;
			list.push_back(word);
			getline(cin,word);
			if(word.size() > longword.size()){
				longword = word;
			}
		}
			sort(list.begin(),list.end(),[](string a,string b){
				reverse(a.begin(),a.end());
				reverse(b.begin(),b.end());
				return a < b;
		});

		for(auto it: list){
			cout.width(longword.size());
			cout << right << it << endl;
		}
		list.clear();
		if(!cin.eof()){
			cout << endl;
		}
	}
}
