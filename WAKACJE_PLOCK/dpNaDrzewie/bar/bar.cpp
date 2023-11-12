#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

constexpr int l = 1e5 + 10;
constexpr int eps = 1e9 + 7;

vector<int> conn[l];
short col[l];
int dp[l][4]; /* how many ways for a given color */

		/* vertex to check, it color, parent, parent color */
ll solve(int current_ver, int c, int parent_ver=-1, int p_c=-1) {
	if (c == p_c || (col[current_ver] > 0 && col[current_ver] != c)) return 0;
	if (dp[current_ver][c] >= 0) return dp[current_ver][c];

	dp[current_ver][c] = 1;
	for (int child : conn[current_ver]) {
		if (child == parent_ver) continue;
		ll numways = 0;

		for (int c=1; c<=3; c++)
			numways += solve(child, c, current_ver, c) % eps;

		dp[current_ver][c] = (dp[current_ver][c] * numways) % eps;
	}
	return dp[current_ver][c];

}


/* bar.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k,a,b,c;
	cin >> n >> k;
	for (int i=1; i<n; i++) {
		cin >> a >> b;
		conn[a].pb(b);
		conn[b].pb(a);
	}
	for (int i=0; i<k; i++) {
		cin >> a >> c;
		col[a] = c;
	}

	for (int i=1; i<=n; i++)
		for (int j=0; j<=3; j++)
			dp[i][j] = -1;

	ll res = (solve(1,1) + solve(1,2) + solve(1,3)) % eps;
	cout << res << '\n';

}
	
