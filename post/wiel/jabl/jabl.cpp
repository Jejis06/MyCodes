#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
constexpr int N = 1e5 + 10;

int segSize=0;
struct Query {
	int l, r, idx;
	bool operator<(const Query b) const {
		if ((l / segSize) != (b.l / segSize)) 
			return (l / segSize) < (b.l / segSize);
		return r < b.r;

	}
};

int cols[N];

vector<int> tree[N];

int PR[N];
int PS[N];
int stree[N];
int ord = 0;

Query queries[N];
ll ans[N];

void dfs(int v, int p) {
	stree[++ord] = v;
	PR[v] = ord;
	for (int child : tree[v])
		if (child != p)
			dfs(child, v);
	PS[v] = ord;
}
int occ[N];
ll sum = 0;
// (x+1)^2 = x^2 + 2x + 1
//  S1 = U + x^2   =>   S2 = U + (x + 1)^2 = U = x^2 + 2x + 1
void add(int x) {
	int it = cols[stree[x]];
	sum += 2 * ll(occ[it]) + 1;
	occ[it]++;
}
void remove(int x) {
	int it = cols[stree[x]];
	if (occ[it] == 0) return;
	sum += -2 * ll(occ[it]) + 1;
	occ[it]--;
}


/* jabl.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;

	for (int i=1; i<=n; i++)
		cin >> cols[i];
	for (int i=1; i<n; i++) {
		cin >> a >> b;

		tree[a].pb(b);
		tree[b].pb(a);
	}
	dfs(1, 0);

	segSize = static_cast<int>( sqrt(n) );

	// TODO:  calculte sum of squares of numbers of distinct colors

	for (int i=1; i<=n; i++) 
		queries[i] = {PR[i], PS[i], i};
	sort(queries + 1, queries + n + 1);

	int curr_l = 0,
	    curr_r = -1;
	for (int i=1; i<=n; i++) {
		Query q = queries[i];
		while (curr_l > q.l) {
			curr_l--;
			add(curr_l);
		}
		while (curr_r < q.r) {
			curr_r++;
			add(curr_r);
		}
		while (curr_r > q.r) {
			remove(curr_r);
			curr_r--;
		}
		while (curr_l < q.l) {
			remove(curr_l);
			curr_l++;
		}
		ans[q.idx] = sum; 
	}
	for (int i=1; i<=n; i++) 
		cout << ans[i] << ' ';
	cout << '\n';


}
	
