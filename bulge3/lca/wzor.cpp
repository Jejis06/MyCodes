#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6;
constexpr int LOG = 20;

int jump[N][LOG + 1];
int depth[N];
vector<int> tree[N];


void dfs(int v, int p) {
	
	depth[v] = depth[p] + 1;

	jump[v][0] = p;
	for (int i=1; i<=LOG; i++) 
		jump[v][i] = jump[ jump[v][i-1] ][i-1];

	for (int child : tree[v]) 
		if (child != p) 
			dfs(child, v);
}

int lca(int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);
	int dis = depth[a] - depth[b];

	for (int i = LOG; i>=0; i--) 
		if (dis & (1 << i)) 
			a = jump[a][i];

	if (a == b) return a;

	for (int i = LOG; i >= 0; i--) {
		int ancA = jump[a][i],
		    ancB = jump[b][i];

		if (ancA == ancB) continue;

		a = ancA;
		b = ancB;
	}
	return jump[a][0];
}
