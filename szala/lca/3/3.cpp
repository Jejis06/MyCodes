#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 1e5 + 200;
constexpr int LOG = 22;

typedef long long ll;
typedef pair<int,int> para; // child, dis

vector<para> graph[L];
int anc[L][LOG],
    ancDis[L][LOG];
int depth[L];
bool vis[L];

void dfs(int v) {
	vis[v] = 1;
	for (auto [child, dis] : graph[v]) {
		if (vis[child]) continue;

		anc[child][0] = v;
		ancDis[child][0] = dis;

		depth[child] = depth[v] + 1;
		for (int i=1; i<LOG; i++) {
			anc[child][i] = anc[ anc[child][i-1] ][ i-1 ];
			ancDis[child][i] = ancDis[child][i-1] + ancDis[ anc[child][i-1] ][i-1];
		}
		dfs(child);
	}
}

ll dis_lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a,b);
	int k = depth[a] - depth[b];

	ll res = 0;

	for (int i=LOG-1; i>=0; i--) {
		if (k & (1 << i)) {
			res += ancDis[a][i];
			a = anc[a][i];
		}
	}
	if (a == b) return res;

	for (int i=LOG-1; i>=0; i--) {
		int A = anc[a][i];
		int B = anc[b][i];

		if (A == B) continue;

		res += ancDis[a][i];
		res += ancDis[b][i];

		a = A;
		b = B;
	}

	return res + ancDis[a][0] + ancDis[b][0];
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a,b);
	int k = depth[a] - depth[b];


	for (int i=LOG-1; i>=0; i--) {
		if (k & (1 << i)) {
			a = anc[a][i];
		}
	}
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

int onPth_lca(int a, int b, int p) {
	int l = lca(a,b);
	int d = depth[a] - l - 1;

	// go from b
	if (d <= 0) {
		d = depth[b] - 1 + d;
		for (int i=LOG-1; i>=0; i--) {
			if (d & (1 << i)) {
				b = anc[b][i];
			}
		}
		return b;
	}
	// go from a
	for (int i=LOG-1; i>=0; i--) {
		if (d & (1 << i)) {
			a = anc[a][i];
			cout << a << '\n';
		}
	}
	return a;
}



/* 3.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,c,b,a;
	cin >> n;
	for (int i=1; i<n; i++) {
		cin >> a >> b >> c;
		graph[a].pb( {b, c} );
		graph[b].pb( {a, c} );
	}
	dfs(1);

	bool done = 0;
	string OP;
	while (!done) {
		cin >> OP;
		if (OP == "DONE") done = true;
		else if (OP == "KTH") {
			cin >> a >> b >> c;
			cout << onPth_lca(a, b, c) << '\n';
		}
		else if (OP == "DIST") {
			cin >> a >> b;
			cout << dis_lca(a, b) << '\n';
		}
	}

}
	
