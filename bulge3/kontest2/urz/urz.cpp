#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e6 + 1;
vector<int> tree[N];

int dp[N];
int Size[N];

/* urz.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, res = 0;
	cin >> n;
	for (int i=2; i<=n; i++) {
		cin >> a;
		tree[a].pb(i);
	}
	while (n >= 1) {
		if (tree[n].size() == 0) {
			dp[n] = 0;
			Size[n] = 1;
		} else {
			int s = 0;
			for (int child : tree[n]) {
				Size[n] += Size[child];
				s += dp[child];
			}
			Size[n]++;
			if (2 * s + 1 == Size[n]) dp[n] = s;
			else if (2 * s + 1 < Size[n]) dp[n] = s+1;
		}
		n--;
	}
	cout << dp[1] << '\n';
}
