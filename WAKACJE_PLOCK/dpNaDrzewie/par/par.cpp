#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 2e5 + 10;
vector<int> conn[L];
int dp[L];
bool vis[L];


/* par.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b;
	cin >> n;

	for (int i=1; i<n; i++) {
		cin >> a >> b;

		conn[a].pb(b);
		conn[b].pb(a);
	}

}
/*






 */
	
