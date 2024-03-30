#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int L = 1 << 17;
int tree[L << 1],
    lazy[L << 1],
    maxInd[L << 1];

int base = 1;
constexpr int inf = 1e9 + 1e3;


void Max(int v, int v1, int v2) {
	// cout << v << ' ' << v1 << ' ' << v2 << '\n';
	if (v1  >= base) {
		maxInd[v1] = v1 - base + 1;
		maxInd[v2] = v2 - base + 1;
	}
	if (tree[v1] >= tree[v2]) {
		maxInd[v] = maxInd[v1];
		tree[v] = tree[v1];
		return;
	}
	maxInd[v] = maxInd[v2];
	tree[v] = tree[v2];
}

void build(int v, int lx, int rx) {
	if (lx == rx) return;
	
	int mid = (lx + rx)/2;

	build(2*v, lx, mid);
	build(2*v+1, mid+1, rx);

	// tree[v] = max()
	Max(v, 2*v, 2*v+1);
}
void push(int v, int l, int r) {
	tree[l] += lazy[v];
	tree[r] += lazy[v];

	lazy[l] += lazy[v];
	lazy[r] += lazy[v];

	lazy[v] = 0;
}

void add(int v, int a, int b, int p, int k, int x) {
	if (a > k || b < p) return;
	else if (a >= p && b <= k) {
		if (tree[v] < 0) return;
		tree[v] += x;
		lazy[v] += x;
	} else {
		int l = 2 * v,
		    r = 2 * v + 1,
		    mid = (a + b)/2;
		
		push(v,l,r);

		add(l, a, mid, p, k,x);
		add(r, mid+1, b,  p, k,x);

		Max(v,l,r);
	}
}

pair<int,int> query(int v, int a, int b, int p, int k) {
	if (a > k || b < p) return {-1, -1};
	else if (a >= p && b <= k) {
		return {tree[v], maxInd[v]};
	} else {
		int l = 2 * v,
		    r = 2 * v + 1,
		    mid = (a + b)/2;

		push(v,l,r);
		return max(query(l, a, mid, p, k), query(r, mid+1, b,  p, k));
	}

}

void display(){
    int lim = 0;
    int x = 1;
    for (int i=1; i< base* 2; i++) {

        cout << tree[i] << ' ';
        lim++;
        if (lim == x){
            x*=2;
            lim=0;
            cout << '\n';
        }
    }
}

/* kon.cpp */
int main(){
	/* ios_base::sync_with_stdio(0);
	cin.tie(0); */

	int n, a;
	cin >> n;
	while (base < n) base <<= 1;
	for (int i=0; i<n; i++) {
		cin >> a;
		tree[base + i] = a;
	}
	bool t;
	build(1,0,base-1);
	display();
	cout << '\n';
	int p,k,x;
	while(1) {
		cin >> t;
		if (t) {
			cout << "dodaj na przedziale\n";
			cin >> p >> k >> x;
			p--;
			k--;
			add(1,0,base-1,p,k,x);
			display();

		} else {
			cout << "max na przedziale z indeksem w tablicy\n";
			cin >> p >> k;
			p--;
			k--;
			auto ret = query(1, 0, base-1, p, k);
			cout << "MaxVal: "<< ret.first << "\nIndex : " << ret.second << '\n';
			display();

		}
	}


}
	
