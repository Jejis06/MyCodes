#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
constexpr int N = 1e6 + 10;
int vis[N];

set<int> poss;

/* skr.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, u;
	cin >> n >> m;

	poss.insert(1);

	for (int i=1; i<=m; i++) {
		cin >> k;
		for (int j=1; j<=k; j++) {
			cin >> u;
			vis[u] = i;
		}
		bool ok = false;
		for (auto it = poss.begin(); it != poss.end(); it++) {
			if (vis[*it] != i && vis[n] != i) {
				ok = true;
				break;
			}
		}
		if (ok) {
			cout << i-1 << '\n';
			return 0;
		}
		for (auto it = poss.begin(); it != poss.end(); it++) 
			if (vis[*it] != i) ok = true;

		if (ok) {
			for(int p=1; p <= n; p++) 
				if (vis[p] != i) 
					poss.insert(p);
		}
	}
	cout << m << '\n';

}
	
