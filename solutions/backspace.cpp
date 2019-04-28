#include <bits/stdc++.h>
using namespace std;

int main(void){
	list<char> string;
	char c;


	while((c = getchar())!= EOF){
		if(c != '<'){
			string.push_back(c);
		}
		else if(!(string.empty())){
			string.pop_back();
		}
	}
	for(auto it: string){
		cout << it;
	}
}