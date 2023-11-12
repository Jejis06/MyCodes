#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 1e6 + 10;
vector<int> tree[L];
bool vis[L];
int64_t pre[L],
    post[L];
int cntr = 1;

void dfs(int v=1) {
	pre[v] = cntr++;
	vis[v] = 1;
	for (int child : tree[v]){
		if (vis[child]) continue;
		dfs(child);
	}

	post[v] = cntr++;

}

/* podd.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,a,b;
	cin >> n;

	for (int i=0; i<n-1; i++) {
		cin >> a >> b;
		tree[a].pb(b);
	}
	dfs();
	for (int i=1; i<=n; i++)
		cout << (post[i] - pre[i] + 1)/2 << ' ';

}
