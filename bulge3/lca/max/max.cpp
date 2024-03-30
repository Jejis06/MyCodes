#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int N = 5e5 + 10;
constexpr int LOG = 19;

struct Edge{
	int dest, dist;
};

vector<Edge> tree[N];

int jump[N][LOG+1];
int dist[N][LOG+1];

int depth[N];


void dfs(int v, int p=0, int dis=0) {
	depth[v] = depth[p] + 1;

	jump[v][0] = p;
	dist[v][0] = dis;

	for (int i=1; i<=LOG; i++) {
		jump[v][i] = jump[ jump[v][i - 1] ][i - 1];
		dist[v][i] = max(dist[v][i - 1], dist[ jump[v][i - 1] ][i - 1]);
	}

	for (auto [child, d]: tree[v]) 
		if (child != p)
			dfs(child, v, d);
}

int lca(int a, int b) {
	int res = INT_MIN;
	if (depth[a] < depth[b]) swap(a, b);
	int delta = depth[a] - depth[b];

	
	for (int i=LOG; i>=0; i--) {
		if (delta & (1 << i)) {
			res = max(res, dist[a][i]);
			a = jump[a][i];
		}
	}
	if (a == b) return res;

	for (int i=LOG; i>=0; i--) {
		int ancA = jump[a][i];
		int ancB = jump[b][i];

		if (ancA == ancB) continue;

		res = max({dist[a][i] , dist[b][i], res});
		a = ancA; b = ancB;
	}
	return max({res, dist[a][0], dist[b][0]});
}

/* max.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, c, m;
	cin >> n;
	for (int i=0; i<n-1; i++) {

		cin >> a >> b >> c;
		tree[a].pb({b, c});
		tree[b].pb({a, c});
	}
	dfs(1);
	a = 0, b = 0;
	while (1) {
		cin >> a;
		if (a == -1) break;
		cin >> b;
		int ans = lca(a, b);
		if (ans == INT_MIN) ans = 0;
		cout << ans << '\n';
	}
}
	
