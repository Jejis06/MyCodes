#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 3e5 + 10;
vector<int> tree[N];


int needed_before(int k, int v=1, int p=0) {
	int sum = 0;
	for (int child : tree[v]) 
		if (child != p)
			sum += needed_before(k, child, v) + 1;
	return max(0, sum - k);
}

bool ok(const int& mid) {
	return (needed_before(mid) == 0);
}

int bs(int l, int r) {
	while (l != r) {
		int mid = (l + r) / 2;
		if (ok(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}

/* luk.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;
	for (int i=0; i<n-1; i++) {
		cin >> a >> b;

		tree[a].pb(b);
		tree[b].pb(a);
	}

	cout << bs(0, n) << '\n';
}
