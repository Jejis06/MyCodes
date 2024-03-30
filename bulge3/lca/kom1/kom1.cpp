#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int LOG = 17;
constexpr int N = 1e5 + 10;

vector<int> tree[N];
int jump[N][LOG+1],
    depth[N];


void dfs(int v, int p=0) {
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
	int dist = depth[a] - depth[b];

	for (int i=LOG; i>=0; i--)
		if (dist & (1 << i))
			a = jump[a][i];

	if (a == b) return a;
	for (int i=LOG; i>=0; i--) {
		if (jump[a][i] != jump[b][i]) {
			a = jump[a][i];
			b = jump[b][i];
		}
	}
	return jump[a][0];
}

bool solve(const int a, const int b, const int c) {
		int ancAB = lca(a, b);
		int ancAC = lca(a, c);
		int ancBC = lca(b, c);

		if (a == c || b == c || ancAB == c) return 1;
		if (depth[c] <= depth[ancAB]) return 0;
		if (ancAC == c || ancBC == c) return 1;

		return 0;
}


/* kom1.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b, c;
	cin >> n;
	for (int i=0; i<n-1; i++) {
		cin >> a >> b;

		tree[a].pb(b);
		tree[b].pb(a);
	}
	dfs(1);
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		cout << (solve(a, b, c) ? "TAK\n" : "NIE\n");
	}

}
	
