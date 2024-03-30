#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int W = 1e5 + 10;

int dp[W];


/* knapsack.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, w, waga, val;
	cin >> n >> w;
	for (int j=1; j<=n; j++) {
		cin >> waga >> val;
		for (int i=w; i>=waga; i--) {
			dp[i] = max(dp[i], dp[i-waga] + val);
		}
	}
	cout << dp[w] << '\n';

}
	
