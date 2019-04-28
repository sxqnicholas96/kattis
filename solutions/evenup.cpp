#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int size,i,num;
	stack<int> SL;

	cin >> size;

	for(i=0;i<size;i++){
		cin >> num;
		if(!SL.empty() && !((SL.top() + num)%2)){
			SL.pop();
		}
		else{
			SL.push(num);
		}

	}
	cout << SL.size();


}
