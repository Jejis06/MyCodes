#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1 << 19;

int PPtree[L << 1],
    PPlazy[L << 1],
    PPind[L << 1];
int tree[L << 1];

int base = 1;
constexpr int absMin = INT_MIN;

void setBase(int n) {
	while (base < n) base <<= 1;
}

int K;

void display1(){
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

void display2(){
    int lim = 0;
    int x = 1;
    for (int i=1; i< base* 2; i++) {

        cout << PPtree[i] << ' ';
        lim++;
        if (lim == x){
            x*=2;
            lim=0;
            cout << '\n';
        }
    }
}
// Funkcje do drzewa Punkt przedzial dla wyniku
void Tree_add(int v) {
	v += base;
	tree[v] = 1;
	v /= 2;
	while (v) {
		tree[v] = tree[v * 2];
		tree[v] += tree[v * 2 + 1];
		v /= 2;
	}

}

int Tree_query(int a, int b) {
	a += base -1;
	b += base +1;

	int res = 0;
	while (b - a > 1) {
		if (a%2 == 0) res += tree[a + 1];
		if (b%2 != 0) res += tree[b - 1];
		a /= 2;
		b /= 2;
	}
	return res;
}
// Funkcje do drzewa Przedzial Przedzial dla rosnacych drzew (+, max) z rozszerzeniem o indeks
void Max(int v, int v1, int v2) {
	if (v1  >= base) {
		PPind[v1] = v1 - base;
		PPind[v2] = v2 - base;
	}
	if (PPtree[v1] >= PPtree[v2]) {
		PPind[v] = PPind[v1];
		PPtree[v] = PPtree[v1];
		return;
	}
	PPind[v] = PPind[v2];
	PPtree[v] = PPtree[v2];
}

void build(int v, int lx, int rx) {
	if (lx == rx) return;
	
	int mid = (lx + rx)/2;

	build(2*v, lx, mid);
	build(2*v+1, mid+1, rx);

	Max(v, 2*v, 2*v+1);
}
void push(int v, int l, int r) {
	PPtree[l] += PPlazy[v];
	PPtree[r] += PPlazy[v];

	PPlazy[l] += PPlazy[v];
	PPlazy[r] += PPlazy[v];

	PPlazy[v] = 0;
}

void add(int v, int a, int b, int p, int k, int x) {
	if (a > k || b < p) return;
	else if (a >= p && b <= k) {
		if (PPtree[v] < 0) return;
		PPtree[v] += x;
		PPlazy[v] += x;
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
		return {PPtree[v], PPind[v]};
	} else {
		int l = 2 * v,
		    r = 2 * v + 1,
		    mid = (a + b)/2;

		push(v,l,r);
		return max(query(l, a, mid, p, k), query(r, mid+1, b,  p, k));
	}

}

// funkcje udostepnione testerce na szkopule

void inicjuj(int n, int k, int* D) {
	setBase(n);
	K = k;
	for (int i=0; i<n; i++) 
		PPtree[base + i] = D[i];
	build(1, 0, base-1);
	while (1) {
		auto [height, ind] = query(1, 0, base-1, 0, n-1);
		if (height < 0) return;
		if (height < K) break;

		add(1, 0, base-1, ind, ind, absMin);
		Tree_add(ind);
	}
}

void podlej(int a, int b) {
	add(1, 0, base-1, a, b, 1);
	while (1) {
		auto [height, ind] = query(1, 0, base-1, a, b);
		if (height < 0) return;
		if (height < K) break;

		add(1, 0, base-1, ind, ind, absMin);
		Tree_add(ind);
	}
}

int dojrzale(int a, int b) {
	return Tree_query(a, b);
}

