#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int BASE = 1 << 17;
int tree[BASE << 1], // max na przedziale wierzcholka
    lazy[BASE << 1]; // o ile wzrosl max --- trzeba poinformowac dzieci

void push(int l, int r, int v) {
	tree[l] += lazy[v];
	tree[r] += lazy[v];

	lazy[l] += lazy[v];
	lazy[r] += lazy[v];

	lazy[v] = 0;
}

void update(int v, int a, int b, int p, int k, int x) {
	// przedzial v poza przedzialem zapytania
	if (k < a || p > b) return;
	// przedzial v zawiera sie w przedziale zapytania
	else if (a >= p && b <= k) {
		tree[v] += x;
		lazy[v] += x;
	}
	// przedzial v czesciowo zalezy w przedziale zapytania
	else {
		int l = 2 * v,
		    r = (2 * v) + 1,
		    mid = (a + b) / 2;


		push(l, r, v);

		update(l, a, mid, p, k, x);
		update(r, mid+1, b, p, k, x);

		tree[v] = max(tree[l], tree[r]);

	}
}
int query(int v, int a, int b, int p, int k) {
	// przedzial v poza przedzialem zapytania -- zwracamy element neutralny( ktory nie zmmienu wyniku zadania )
	if (k < a || p > b) 
		return 0; 
	// przedzial v zawiera sie w przedziale zapytania
	else if (a >= p && b <= k) {
		return tree[v];
	}
	// przedzial v czesciowo zalezy w przedziale zapytania
	else {
		int l = 2 * v,
		    r = (2 * v) + 1,
		    mid = (a + b) / 2;

		push(l, r, v);
		return max(query(l, a, mid, p, k), query(r, mid+1, b, p, k));
	}


}

/* kol.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, z,
	    p, k, x;

	cin >> n >> m >> z;
	while (z--) {
		cin >> p >> k >> x; // czy na trasie (a,b) jest co najwyzej m-x zajetych miejsc
				    // czy na przedziale (a,b) maximum jest <= m-x
		if (query(1, 0, BASE-1, p, k-1) <= m - x) {
			update(1, 0, BASE-1, p, k-1, x);
			cout << "T\n";
		}
		else cout << "N\n";
	}

}

