#include <bits/stdc++.h>
using namespace std;

typedef pair<float,int> fi;

vector<vector<fi>> adjlist; 
vector<float> flist;

void djikstra(int vtx){
	priority_queue<fi> pq;
	flist[vtx] = 1;
	pq.push(make_pair(flist[vtx],vtx));

	while(!pq.empty()){
		int x = pq.top().second;
		pq.pop();
		for(auto it: adjlist[x]){
			int v = it.second; float w = it.first;
			if(flist[v] < w*flist[x]){
				flist[v] = w*flist[x];
				pq.push(make_pair(flist[v],v));
			}
		}

	}
}

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m,i,vtx1,vtx2;
	float factor;

	cin >> n >> m;

	while( n || m){
		adjlist.assign(n,vector<fi>());
		flist.assign(n,-1);
		for(i=0;i<m;i++){
			cin >> vtx1 >> vtx2 >> factor;
			adjlist[vtx1].push_back(make_pair(factor,vtx2));
			adjlist[vtx2].push_back(make_pair(factor,vtx1));
		}
		djikstra(0);
		cout << setprecision(4) << fixed <<  flist[n-1] << endl;
		cin >> n >> m;
	}


}