#include <bits/stdc++.h>
using namespace std;



vector<string> sky;

void bfs(int i , int j, int row, int col){
	sky[i][j] = '#';
	if(i-1 >= 0){
		if(sky[i-1][j] == '-'){
			//bfs(sky,i-1,j,row,col);
			bfs(i-1,j,row,col);
		}
	}
	if(i+1 < row){
		if(sky[i+1][j] == '-'){
			//bfs(sky,i+1,j,row,col);
			bfs(i+1,j,row,col);
		}
	}
	if(j-1>=0){
		if(sky[i][j-1] == '-'){
			//bfs(sky,i,j-1,row,col);
			bfs(i,j-1,row,col);
		}
	}
	if(j+1 < col){
		if(sky[i][j+1] == '-'){
			//bfs(sky,i,j+1,row,col);
			bfs(i,j+1,row,col);
		}
	}
}

int main(void){
	int row, col,i,j,numstar = 0, casenum = 0;
	string str;
	
	while(cin >> row >> col){
		cin.get();
		casenum++;
		for(i=0;i<row;i++){
			getline(cin, str);
			sky.push_back(str);
		}
		/*cout << "Before: " << endl;
		for(auto it: sky){
			cout << it << endl;
		}*/
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(sky[i][j] == '-'){
					numstar++;
					bfs(i,j,row,col);
				}
			}
		}
		/*cout << "After: " << endl;
		for(auto it: sky){
			cout << it << endl;
		}*/
		
		cout << "Case " << casenum << ": " << numstar << endl;
		numstar = 0;
		sky.clear();
	}
}