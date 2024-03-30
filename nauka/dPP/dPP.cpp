#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int base = 1 << 17;

int tree[base << 1];
int lazy[base << 1];

void addS(int v, int a, int b, int p, int k, int x) {
	if (p > b || k < a) {
		return;
	} else if (p <= a && k >= b) {
		tree[v] += (b - a + 1) * x;
		lazy[v] += (b - a + 1) * x;
	} else {
		int l = 2*v,
		    r = 2*v + 1,
		    mid = (a + b)/2;

		tree[l] += lazy[v]/2;
		tree[r] += lazy[v]/2;

		lazy[l] += lazy[v]/2;
		lazy[r] += lazy[v]/2;
		lazy[v] = 0;

		addS(l, a, mid, p, k, x);
		addS(r, mid+1, b, p, k, x);

		tree[v] = tree[l] + tree[r];

	}

}

int queryS(int v, int a, int b, int p, int k) {
	if (p > b || k < a) {
		return 0;
	} else if (p <= a && k >= b) {
		return tree[v];
	} else {
		int l = 2*v,
		    r = 2*v + 1,
		    mid = (a + b)/2;

		tree[l] += lazy[v]/2;
		tree[r] += lazy[v]/2;

		lazy[l] += lazy[v]/2;
		lazy[r] += lazy[v]/2;
		lazy[v] = 0;

		return queryS(l, a, mid, p, k) + queryS(r, mid+1, b, p, k);
	}
}


/* dPP.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

}
	
