#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int LOG = 17;
constexpr int N = 3e5 + 10;

vector<int> tree[N];
int jump[N][LOG + 1],
    depth[N];

void dfs(int v, int p = 0) {

	depth[v] = depth[p] + 1;
	jump[v][0] = p;

	for (int i=1; i<=LOG; i++) 
		jump[v][i] = jump[ jump[v][i - 1] ][i - 1];

	for (int child : tree[v]) 
		if (child != p) 
			dfs(child, v);
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int dis = depth[a] - depth[b];

	for (int i=LOG; i >= 0; i--) 
		if (dis & (1 << i)) 
			a = jump[a][i];
	if (a == b) return a;

	for (int i=LOG; i >= 0; i--) {
		int ancA = jump[a][i];
		int ancB = jump[b][i];

		if (ancA == ancB) continue;

		a = ancA;
		b = ancB;
	}

	return jump[a][0];
}

/* kom.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, m, e, s = 1, res = 0;
	cin >> n;

	for (int i=0; i<n-1; i++) {
		cin >> a >> b;

		tree[a].pb(b);
		tree[b].pb(a);
	}
	dfs(1);
	cin >> m;
	while (m--) {
		cin >> e;
		int anc = lca(s, e);
		res += (depth[s] - depth[anc] + depth[e] - depth[anc]);
		s = e;
	}
	cout << res << '\n';
}
