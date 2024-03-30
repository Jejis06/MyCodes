#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int BASE = 1 << 17;

int tree[BASE << 1],
    lazy[BASE << 1];

constexpr int lim = 1e5;
int arr[lim];

void push(int v, int lv, int rv) {
	tree[lv] += lazy[v];
	tree[rv] += lazy[v];

	lazy[lv] += lazy[v];
	lazy[rv] += lazy[v];

	lazy[v] = 0;
}

void build(int ind, int lx, int rx) {
	if (lx == rx) return;
	int mid = (lx + rx)/2;

	build(2*ind, lx, mid);
	build(2*ind+1, mid+1, rx);

	tree[ind] = min(tree[2*ind], tree[2*ind+1]);
}

void add(int v, int l, int r, int p, int k, int x) {
	if (k < l || p > r) return;
	else if (p <= l && r <= k) {
		tree[v] += x;
		lazy[v] += x;
	} else {
		int mid = (l + r) / 2;

		push(v, 2*v, 2*v+1);

		add(2*v, l, mid, p, k, x);
		add(2*v+1, mid+1, r, p, k, x);

		tree[v] = min(tree[2*v], tree[2*v+1]);
	}
}
int get(int v, int l, int r, int p, int k) {
	if (k < l || p > r) return lim;
	else if (p <= l && r <= k) {
		return tree[v];
	} else {
		int mid = (l + r)/2;
		push(v, 2*v, 2*v+1);

		return min( get(2*v, l, mid, p, k), get(2*v+1, mid+1, r, p, k));

	}
	

}

/* naw.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i=1; i<=n; i++) 
		cin >> arr[i];

	tree[BASE] = arr[1];
	for (int i=2; i<=n; i++)
		tree[BASE + i - 1] = tree[BASE + i - 2] + arr[i];

	int q,a;
	int sum = tree[BASE + n - 1];
	while (1) {
		cin >> a;
		if (a == -1) break;

		if (a == 0) {
			// TAK ? NIE
			int x = 0;
			for (int i=1;i <=n; i++) {
				cout << arr[i] << ' '; 
				x += arr[i];
			}
			cout << '\n';
			cout << x << ' '<< sum  << ' ' <<  get(1, 0, BASE-1, 1, n) << '\n';
			/* cout << "NIE\n";
			cout << "TAK\n"; */
		}
		else {
			arr[a] *= -1;
			sum += 2 * arr[a];
			add(1, 0, BASE-1, a, n, 2 * arr[a]);
		}
	}

}

