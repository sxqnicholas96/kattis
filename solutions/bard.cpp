#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,E,K,bard,num,numSong = 0,i;
	vector<unordered_set<int>> list;
	unordered_set<int> lol;
	vector<int> present;
	
	cin >> N >> E;
	for(i=0;i<N;i++){
		list.push_back(lol);
	}
	while(E--){
		cin >> K;
		bard = 0;
		while(K--){
			cin >> num;
			if(num == 1){
				bard = 1;
				numSong++;
			}
			present.push_back(num);
		}
		if(bard){
			for(auto it: present){
				list[it-1].insert(numSong);
			}
		}
		else{
			for(i=1;i<=numSong;i++){
				int known_song = 0;
				for(auto it: list){
					if(it.find(i) != it.end()){
						known_song = 1;
						break;
					}
				}
				if (known_song){
					for(auto it: present){
						list[it-1].insert(i);
					}
				}
			}
		}
		present.clear();
	}
	for(i=0;i<N;i++){
		if(list[i].size() == numSong){
			cout << i + 1 << endl;
		}
	}
}





































/*
//Wrong because songs are distinct. Villagers are able to share songs based on what songs they learnt. 
//2 villagers can know 2 distinct songs. After sharing songs the total songs they know should be 4
//not max(villager1.size(),villager2.size())
int main(void){
	int N,E,K,num,max,bard = 0,i;
	vector<pair<int,int>> list;
	vector<int> present,lol;
		
	cin >> N >> E;
	
	for(i = 0;i<N;i++){
		list.push_back(pair<int,int>(0,-(i+1)));
	}
	
	while(E--){
		bard = 0;
		cin >> K;
		while(K--){
			cin >> num;
			if(num == 1){
				bard = 1;
				list[0].first++;
				continue;
			}
			present.push_back(num);
			lol.push_back(list[num-1].first);
		}
		if(!bard){
			sort(lol.begin(),lol.end());
			for(auto it: present){
				list[it-1].first = lol.back();
			}
		}
		else{
			for(auto it: present){  
				list[it-1].first += 1;
			}
		}
		present.clear();
		lol.clear();
	}
	
	sort(list.begin(),list.end());
	max = list.back().first;
	while(list.back().first == max){
		cout << -list.back().second << endl;
		list.pop_back();
	}

}
*/