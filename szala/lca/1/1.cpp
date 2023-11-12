#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1e4 + 10;
constexpr int LOG = 14;
vector<int> graph[L];
int anc[L][LOG];
bool vis[L];
int depth[L];

void dfs(int v){
	vis[v] = 1;
	for (int& w: graph[v]) {
		if (vis[w]) continue;
		anc[w][0] = v;
		depth[w] = depth[v] + 1;

		for (int i=1; i<LOG; i++)
			anc[w][i] = anc[anc[w][i-1]][i-1];
		dfs(w);
	}
}
int lca(int a, int b){
	if (depth[a] < depth[b]) swap(a,b);
	int k = depth[a] - depth[b];

	for (int i=LOG-1; i>=0; i--)
		if (k & (1 << i))
			a = anc[a][i];

	if (a == b) return a;
	for (int i=LOG-1; i>=0; i--) {
		int A = anc[a][i];
		int B = anc[b][i];

		if (A == B) continue;

		a = A;
		b = B;
	}
	return anc[a][0];
}


/* 1.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,child;
	cin >> n;
	for (int parent=0; parent<n; parent++) {
		cin >> m;
		for (int j=0; j<m; j++) {
			cin >> child;
			graph[parent].push_back(child);
		}
	}

	dfs(0);

	int q; cin >> q;
	int a,b;
	while (q--) {
		cin >> a >> b;
		cout << lca(a,b) << '\n';
	}

}
	
