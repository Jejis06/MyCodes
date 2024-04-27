#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 20;
constexpr int M = 1 << 20;
constexpr int MOD = 1e9 + 7;

int arr[N];
ll dp[M];

/* got.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	dp[0] = 1;

	for (int mask=0; mask < (1 << n); mask++) {
		ll sum = 0;
		for (int bit=0; bit < n; bit++) {
			if (mask & (1 << bit)) sum += arr[bit];
		}
		for (int bit=0; bit < n; bit++) {
			if (mask & (1 << bit)) continue;
			if (sum + arr[bit] >= 0) {
				dp[mask + (1 << bit)] += dp[mask];
				if (dp[mask + (1 << bit)] >= MOD) dp[mask + (1 << bit)] -= MOD;
			}
		}

	}
	cout << dp[(1 << n) - 1] << '\n';
}
	
