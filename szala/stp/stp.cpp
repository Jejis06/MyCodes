#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1e3;

int n,m;
vector<vector<int>> G;
int przodkowie[L];

/* stp.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	

	cin >> n >> m ;

	for (int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
	}


	for (int i=0; i<n; i++) 
		for (auto& node : G[i]) 
			przodkowie[node]++;

	queue<int> q;

	for (int i=1; i<=n; i++) 
		if (przodkowie[i] == 0)
			q.push(i);

	while (q.size()) {
		int node = q.front();
		q.pop();
		cout << node << '\n';

		for(auto nextNode : G[ node ]){
		    przodkowie[ nextNode ]--;
		    if(przodkowie[ nextNode ] == 0){
			q.push(nextNode);
		    }
		}

	}



}
	
