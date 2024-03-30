#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int L = 1e6 + 10;
constexpr int base = 1 << 20;
constexpr int inf = 1e9 + 10;

int y[L];
int tree[2 * base];

int query(int a, int b) {
	int res = -inf;
	a += base - 1;
	b += base + 1;

	while (a/2 != b/2) {
		if (a%2 == 0) res = max(res, tree[a+1]);
		if (b%2 == 1) res = max(res, tree[b-1]);

		a /= 2; b /= 2;
	}
	return res;
}
/* temp.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;

	for (int i=0; i<n; i++) 
		cin >> tree[i + base] >> y[i];

	for (int i=base-1; i>0; i--)
		tree[i] = max(tree[2*i], tree[2*i+1]);

	int res = 1;
	int j = 1;
	for (int i = 0; i < n; i++) {
		while (j < n && query(i, j-1) <= y[j]) 
			j++;
		res = max(res, j - i);
	}
	cout << res << '\n';

}
	
