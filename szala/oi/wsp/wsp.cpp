#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int L = 1e5 + 10;
int n,m,k,a,b;

vector<int> conn[L];
bool vis[L];
ll val[L];

ll res;
void dfs(int v) {
	vis[v] = 1;
	res += val[v];

	for (int child : conn[v]) {
		if (vis[child]) continue;
		dfs(child);
	}

}

ll calc(int p) {
	for (int i=0; i<n; i++)
		vis[i] = 0;
	res = 0;
	dfs(p);
	return res;

}
/* wsp.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i=0; i<n; i++) cin >> val[i];
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		conn[a-1].pb(b-1);
	}

	for (int i=0; i<n; i++) {
		cout << calc(i) << '\n';

	}

}
	
