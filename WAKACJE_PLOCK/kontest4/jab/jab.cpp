#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

constexpr int L = 1e6 + 10;
vector<int> conn[L];
int amm[L];

ll dp[L][2];

ll solve(int v, bool take, int par, bool parCh) {

	if (take == 1 && parCh == 1) return 0;
	if (v == par) return 0;

	if (dp[v][take] >= 0) return dp[v][take];

	if (take) dp[v][take] = amm[v];
	else dp[v][take] = 0;

	ll childSum = 0;

	for (int child : conn[v]) {
		if (child == par || child == v) continue;
		childSum += max(solve(child, !take, v, take), solve(child, take, v, take));
	}
	dp[v][take] += childSum;
	return dp[v][take];
}

/* jab.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	cin >> n;

	for (int i=1; i<=n; i++){
		cin >> amm[i];
		dp[i][0] = dp[i][1] = -1;
	}

	for (int i=1; i<n; i++) {
		cin >> a >> b;
		conn[a].pb(b);
		conn[b].pb(a);
	}

	ll res = max(solve(1,0,-1,1), solve(1,1,-1,0));

	cout << res << '\n';
}
	
