#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 2e5 + 10;
int continous[L];
int starting[L];

vector<int> edges[L];
bool vis[L];

void dfs(int v, int par) {
	vis[v] = 1;

	cout << v << ' ' << par << ' ' << edges[v].size()<< '\n';
	if (edges[v].size() == 1) return;
	cout << "LESGO\n";

	for (int child : edges[v]) if (!vis[child]) dfs(child, v);

	cout << "processed " << v << '\n';

	int maxCont = -1,
	    maxChildSum = -1;

	for (int child : edges[v]) {
		if (child == par || child == 0) continue;
		cout << child << '\n';
		maxCont = max(maxCont, starting[child]);
	}

	cout << "MCS\n";
	for (int i=0; i < edges[v].size(); i++) {
		for (int j=0; j < edges[v].size(); j++) {
			if (j == i || edges[v][i] == par || edges[v][j] == par || edges[v][i] == par || edges[v][j] == par) continue;
			maxChildSum = max( starting[edges[v][i]] + starting[edges[v][j]], maxChildSum );
			cout << maxChildSum << '\n';
		}

	}

	starting[v] = edges[v].size() + max(0, maxCont - 1);
	continous[v] = max(starting[v], int(maxChildSum + edges[v].size() - 2));

	cout << "s : " << starting[v] << "\t c : " << continous[v] << '\n';
}



/* parada.cpp */
int main(){
	/* ios_base::sync_with_stdio(0);
	cin.tie(0); */

	int n;
	cin >> n;

	int a,b;
	for (int i=1; i<n; i++) {
		cin >> a >> b;

		edges[a].pb(b);
		edges[b].pb(a);
	}

	edges[1].pb(0);
	vis[0] = 1;

	dfs(1,-1);
	cout << continous[1] + 1;


}
	
