#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n, numcmd,x,pos = 0;
	string cmd;
	stack<int> cmdstk;
	
	cin >> n >> numcmd;
	
	while(cin >> cmd ){
		if(cmd == "undo"){
			cin >> x;
			while(--x){
				cmdstk.pop();
			}
			pos = cmdstk.top();
			cmdstk.pop();
		}
		else{
			x = stol(cmd);
			cmdstk.push(pos);
			pos = (pos+x)%n;
			if(pos<0){
				pos += n;
			}
		}
	}
	cout << pos << endl;
}