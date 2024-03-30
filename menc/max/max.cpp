#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 5e5 + 10;
constexpr int LOG = 18;

struct Node{
	int b;
	int cost;
};
vector<Node> graph[N];
int depth[N];
int jmp[N][LOG],
    jmpDis[N][LOG];

void dfs(int v, int p, int dis) {
	jmp[v][0] = p;
	jmpDis[v][0] = dis;
	depth[v] = depth[p] + 1;

	for (int i=1; i<LOG; i++) {
		int poprzodek = jmp[v][i - 1];
		jmp[v][i] = jmp[poprzodek][i - 1];
		jmpDis[v][i] = max(jmpDis[v][i - 1], jmpDis[poprzodek][i - 1]);
	}
	for (auto [child, d]: graph[v]) 
		if (child != p)
			dfs(child, v, d);
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int delta = depth[a] - depth[b];
	
	int res = INT_MIN;
	for (int i=LOG-1; i>=0; i--) {
		if (delta & (1 << i)) {
			res = max(res, jmpDis[a][i]);
			a = jmp[a][i];
		}
	}
	if (a == b) return res;
	for (int i=LOG-1; i>=0; i--) {
		int ancA = jmp[a][i];
		int ancB = jmp[b][i];

		if (ancA == ancB) continue;

		res = max({res, jmpDis[a][i], jmpDis[b][i]});
	}
	return max({res, jmpDis[a][0], jmpDis[b][0]});
}

/* max.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, c;
	cin >> n;
	for (int i=1; i<n; i++) {
		cin >> a >> b >> c;
		graph[a].pb({b, c});
		graph[b].pb({a, c});
	}
	dfs(1, 0, 0);
	while (1) {
		cin >> a;
		if (a < 0) return 0;
		cin >> b;

		int maxDis = lca(a, b);
		if (maxDis == INT_MIN) 
			cout << 0;
		else cout << maxDis;
		cout << '\n';
	}

}
	
