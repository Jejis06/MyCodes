#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 1e6 + 10;
long long dp[L], prices[L];

/* gielda.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n, x, a;
	cin >> n >> x;

	for (int i=1; i<=n; i++) {
		cin >> prices[i];
	}
	long long doch = -1e9 - 10;
	for (int i=1; i<=n; i++) {
		dp[i] = max(dp[i-1], prices[i] - x + doch);
		doch = max(doch, dp[i-1] - prices[i]);
	}
	cout << dp[n] << '\n';
}
