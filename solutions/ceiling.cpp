#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,k,val,i,root,found,index = 1 ,vtx;
	unordered_map<int,pair<int,int>> list;
	set<set<int>> ans;
	set<int> track;
	
	cin >> n >> k;
	
	while(n--){
		list.clear();
		for(i=0;i<k;i++){
			cin >> val;
			if(!i){
				root = val;
			}
			vtx = root;
			index = 1;
			unordered_set<int> lol;
			found = 1;
			while(found){
				if(!list.count(vtx)){
					list.insert({vtx,make_pair(-1,-1)});
					track.insert(1);
					break;
				}
				else{
					if(val > vtx){
						index = index*2 + 1;
						if(list[vtx].second > 0){
							vtx = list[vtx].second;
						}
						else{
							track.insert(index);
							list[vtx].second = val;
							list.insert({val,make_pair(-1,-1)});
							found = 0;
						}

					}
					else{
						index *= 2;
						if(list[vtx].first > 0){
							vtx = list[vtx].first;
						}
						else{
							track.insert(index);
							list[vtx].first = val;
							list.insert({val,make_pair(-1,-1)});
							found = 0;
						}
					}

				}
			}
		}
		ans.insert(track);
		track.clear();
		
	}
	cout << ans.size() << endl;
	
}