#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll N = 1e6 + 10;
int n, d;
ll a, b;

int dp[N];

int cost(ll x, ll y) {
    return (a*y + b*x) % 1001;
}

int main() {
    /* ios_base::sync_with_stdio(0);
    cin.tie(0); */

    cin >> n >> d >> a >> b;

    dp[0] = dp[1] = 0;
    dp[2] = cost(1,1);

    for (int x=3; x<=n; x++) {
	    dp[x] = INT_MAX;

	    int s = max((int)ceil((float(x) - float(d))/2), 1),
		e = (x + d)/2;

	    for (int i=s; i<=e; i++) {
		    int j = x - i;
		    if (j < 0) continue;


		    int next = cost((ll)i, (ll)j)
			    + dp[i] + dp[j];
		    dp[x] = min(dp[x], next);
	    }
    }
    cout << dp[n] << '\n';
}



