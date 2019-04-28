#include <bits/stdc++.h>
using namespace std;

int main(void){
	queue<int> que1, que2;
	int max = 0,n,i,num,size = 0;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> num;
		que1.push(num);
	}

	while(!(que1.empty())){
		if(que1.front() > max){
			size++;
			max = que1.front();
			que2.push(que1.front());
			que1.front();
		}
		else{
			que1.pop();
		}
	}

	cout << size << endl;

	for(i=0;i<size;i++){
		cout << que2.front();
		if(i!= size-1){
			cout << " ";
		}
		que2.pop();
	}
	cout << endl;
	return 0;

}