#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 5e5 + 10;
constexpr int eps = 1e9 + 7;
vector<int> conn[L];
bool vis[L];

int64_t out = 1;
int64_t sil(int64_t k){
	int64_t res = 1;

	for (int i=2; i<=k; i++)
		res = (res * i) % eps;
	return res;
}

void dfs(int v=1) {
	vis[v] = 1;
	if (conn[v].size() != 1)
		out = (out * sil(conn[v].size() - 1)) % eps;
	for (int child : conn[v]) {
		if (vis[child]) continue;
		dfs(child);
	}

}

/* ile.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n;
	

	conn[1].pb(0);
	vis[0] = 1;

	bool hasPar = 0;
	for (int i=0; i<n-1; i++){
		cin >> a >> b;
		conn[a].pb(b);
		conn[b].pb(a);

	}
	dfs();
	cout << out << '\n';

}
	
