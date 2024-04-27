#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
constexpr int N = 1e5 + 10;

int segSize=0;
struct Query {
	int l, r, idx;
	bool operator<(const Query b) const {
		return mp(l / segSize, r) < mp(b.l / segSize, b.r);
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
unordered_map<int, int> occ;

void add(int x) {
	occ[cols[x]]++;
}
void remove(int x) {
	x = cols[x];
	occ[x]--;
	if (occ[x] == 0) occ.erase(x);
}
ll get_ans() {
	ll res = 0;
	for (auto it : occ) {
		res += ll(it.second) * ll(it.second);
	}
	return res;
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

	segSize = sqrt(n) + 1;
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
		ans[q.idx] = get_ans();
	}
	for (int i=1; i<=n; i++) 
		cout << ans[i] << ' ';
	cout << '\n';


}
	
