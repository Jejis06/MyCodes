#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6;
constexpr int base = 1 << 20;
int tree[base * 2];

void build(int v, int l, int r) {
	if (l == r) return;
	int mid = (l + r) /2;

	build(2*v, l, mid);
	build(2*v+1, mid+1, r);

	tree[v] = max(tree[2*v], tree[2*v+1]);
}

int query(int a, int b) {
	int res = -1;

	a += base - 1 - 1;
	b += base - 1 + 1;

	while (a/2 != b/2) {
		if (a%2 == 0) res = max(res, tree[a + 1]);
		if (b%2 != 0) res = max(res, tree[b - 1]);

		a/=2; b/=2;
	}
	return res;

}
void update(int v, int x) {
	v += base - 1;
	tree[v] = x;
	v /= 2;
	while (v) {
		tree[v] = max(tree[2*v], tree[2*v+1]);
		v /= 2;
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q, a, b;
	cin >> n;

	for (int i=0; i<n; i++) 
		cin >> tree[base + i];
	build(1, 1, base);

	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << query(a, b) << '\n';
	}
}
