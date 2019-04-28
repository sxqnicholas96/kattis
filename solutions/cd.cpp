#include <bits/stdc++.h>
using namespace std;

int main(void){
	//ios_base::sync_with_stdio(false); cin.tie(0); // better use this for all cin/cout stuffs
	int sizeJack, sizeJill,i,num;
	vector<int> Jack, Jill;

	cin >> sizeJack >> sizeJill;

	while(sizeJack || sizeJill){
		while(sizeJack--){
			cin >> num;
			Jack.push_back(num);
		}
		while(sizeJill--){
			cin >> num;
			Jill.push_back(num);
		}
		int it1 = 0, it2 = 0,ans = 0;
		while(it1 != Jack.size() && it2 != Jill.size()){
			if(Jack[it1] == Jill[it2]){
				ans++;
				it1++; it2++;
			}
			else if(Jack[it1] > Jill[it2]){
				it2++;
			}
			else{
				it1++;
			}
		}
		cout << ans << endl;
		Jack.clear();
		Jill.clear();
		cin >> sizeJack >> sizeJill;
		//cout << sizeJack << sizeJill;
	}
}