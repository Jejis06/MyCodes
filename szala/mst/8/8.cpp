#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int L = 1e5 + 10;
struct Edge{
	int a,b;
	ll c;

	bool operator<(const Edge& x) {
		return c < x.c;
	}
} edges[2 * L];
int ids[L];

int check(int node){
	if (ids[node] == node) return node;
	return ids[node] = check(ids[node]);
}

/* 8.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,a,b;
	ll c;

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		edges[i] = {a,b,c};

		ids[a] = a;
		ids[b] = b;
	}
	sort(edges, edges+m);
	ll minCost{}, amm{};

	for (int i=0; i<m; i++) {
		auto& [a,b,c] = edges[i];

		int A = check(a);
		int B = check(b);

		if (A == B) continue;

		minCost += c;
		amm++;

		ids[A] = B;
	}

	if (amm == n-1) cout << minCost;
	else cout << "IMPOSSIBLE";
	

}
	
