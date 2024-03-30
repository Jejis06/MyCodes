#include <bits/stdc++.h>
using namespace std;

constexpr int LOG =17;
constexpr int N = 1e5 + 10;

vector<int> tree[N];
int depth[N],
    jmp[N][LOG];

void dfs(int v, int p) {
	depth[v] = depth[p] + 1;
	jmp[v][0] = p;

	for (int i=1; i<LOG; i++) 
		jmp[v][i] = jmp[ jmp[v][i-1] ][i-1];
	for (int child : tree[v]) {
		if (child != p)
			dfs(child, v);
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a,b);
	int dis = depth[a] - depth[b];

	for (int i=LOG-1; i>=0; i--) 
		if (dis & (1 << i)) 
			a = jmp[a][i];

	if (a == b) return a;

	for (int i=LOG-1; i>=0; i--) {
		if (jmp[a][i] != jmp[b][i]) {
			a = jmp[a][i];
			b = jmp[b][i];
		}
	}
	return jmp[a][0];

}
