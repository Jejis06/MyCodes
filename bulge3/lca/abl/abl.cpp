#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e5 + 10;
constexpr int LOG = 17;

int depth[N],
    jump[N][LOG + 1],
    children[N];
vector<int> tree[N];

int dfs(int v, int p = 0) {
	jump[v][0] = p;
	depth[v] = depth[p] + 1;

	for (int i=1; i<=LOG; i++)
		jump[v][i] = jump[ jump[v][i - 1] ][i - 1];

	for (int child : tree[v]) {
		if (child == p) continue;
		children[v] += dfs(child, v);
	}
	return children[v] + 1;
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int dis = depth[a] - depth[b];

	for (int i=LOG; i>=0; i--) 
		if (dis & (1 << i)) 
			a = jump[a][i];

	if (a == b) return a;

	for (int i=LOG; i>=0; i--) {
		int ancA = jump[a][i];
		int ancB = jump[b][i];

		if (ancA == ancB) continue;
		a = ancA;
		b = ancB;
	}
	return jump[a][0];
}

int res(int a, int b, int n) {
	int anc = lca(a, b);
	int dist = depth[a] + depth[b] - 2 * depth[anc];

	if (dist & 1) return 0;
	if (dist == 0) return n;

	if (depth[a] == depth[b]) {
		for (int i=LOG; i>=0; i--) {
			if (jump[a][i] != jump[b][i]) {
				a = jump[a][i];
				b = jump[b][i];
			}
		}
		return n - children[a] - children[b] - 2;
	}
	if (depth[a] < depth[b]) swap(a, b);
	int mid = a;
	for (int i=LOG; i>=0; i--) 
		if ((dist / 2 - 1) & (1 << i)) 
			mid = jump[mid][i];
	return children[jump[mid][0]] - children[mid];
}


/* abl.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, m;
	cin >> n;
	for (int i=0; i<n-1; i++) {
		cin >> a >> b;

		tree[a].pb(b);
		tree[b].pb(a);
	}
	dfs(1);
	cin >> m;
	while (m--) {
		cin >> a >> b;
		cout << res(a, b, n) << '\n';
	}

}
	
