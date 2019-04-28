	#include <bits/stdc++.h>
	using namespace std;

	typedef pair<int,int> ii;

	vector<vector<ii>> adjlist;
	unordered_set<int> ans,forced;
	int counter = 0;

	void dfs(int vtx,int madefault,int forcedmoves,unordered_set<int> visited){
		visited.insert(vtx);
		if(!forced.count(vtx)){ //Checks whether vertex is a forced vertex
			ans.insert(vtx);
			//cout << "End vertex detected" << endl;
		}
		//cout << "Counter: " << counter++  << endl;
		//cout << "Forcedmoves: " << forcedmoves << endl;
		for(auto it: adjlist[vtx]){
			if(!madefault || it.second){
				if(it.second == 0){
					//visited.clear();
					forcedmoves = 0;
					//cout << "Visiting: " << it.first+ 1 << endl;
					dfs(it.first,1,0,visited);
				}
				else if(visited.count(it.first) && forcedmoves){
					//cout << "Loop detected at vertex " << it.first + 1 << endl;
					return;
				}
				else{
					//cout << "Visiting: " << it.first + 1 << endl;
					forcedmoves++;
					dfs(it.first,madefault,forcedmoves,visited);
				}
			}
		}
	}

	int main(void){
		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
		int N, E,fro,to;
		unordered_set<int> visited;

		cin >> N >> E;

		adjlist.assign(N,vector<ii>());

		while(E--){
			cin >> fro >> to;

			if(fro < 0){
				adjlist[-fro -1].push_back(make_pair(to-1,1)); // if fro < 0, the edge is a forced edge
				forced.insert(-fro-1);
			}
			else{
				adjlist[fro - 1].push_back(make_pair(to-1,0));
			}

		}

		dfs(0,0,0,visited);

		cout << ans.size() << endl;

		/*for(auto it: adjlist){
			for(auto it1: it){
				cout << it1.first << " " << it1.second << " ";
			}
			cout << endl;
		}*/

	}