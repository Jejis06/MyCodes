#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1e5 + 200;
constexpr int LOG = 22;

vector<int> graph[L];
int anc[L][LOG];
int depth[L];
bool vis[L];


void dfs(int v){
	vis[v] = 1;
	for (int& w : graph[v]) {
		if (vis[w]) continue;
		anc[w][0] = v;
		depth[w] = depth[v] + 1;

		for (int i=1; i<LOG; i++)
			anc[w][i] = anc[anc[w][i - 1]][i - 1];
		dfs(w);
	}

}

int lca(int a, int b){
	if (depth[a] < depth[b]) swap(a,b);
	int k = depth[a] - depth[b];

	for(int i=LOG-1; i>=0; i--) 
		if (k & (1 << i)) 
			a = anc[a][i];

	if (a == b) return a;

	for(int i=LOG-1; i>=0; i--) { 
		int ta = anc[a][i];
		int tb = anc[b][i];

		if (ta == tb) continue;

		a = ta;
		b = tb;
	}
	return anc[a][0];
}


/* wzor.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int a,b;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	int q; 
	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout <<  lca(a,b);

	}
}
	
