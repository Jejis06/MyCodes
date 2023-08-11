#include <bits/stdc++.h>
using namespace std;


constexpr int L = 1e5+10;
struct Edge {
	int a,b;
	long double c;

	bool operator<(const Edge& x) {
		return c < x.c;
	}
} edges[2 * L];
int ids[L];


int check(int node) {
	if (ids[node] == node) return node;
	return ids[node] = check(ids[node]);
}

void solve(){
	int n,m;
	cin >> n >> m;

	int a,b;
	long double c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		edges[i] = {a,b,c};
		
		ids[a] = a;
		ids[b] = b;
	}
	sort(edges, edges+m);

	int res = 1;
	for (int i=0; i<m; i++) {
		auto& [a,b,c] = edges[i];

		int A = check(a);
		int B = check(b);

		if (A == B) continue;

		ids[A] = B;
		res += log2l(c);
	}
	cout << res << '\n';
}

/* 5.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

}
	
