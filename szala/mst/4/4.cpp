/*#include <bits/stdc++.h> 
using namespace std;

constexpr int L = 1e5 + 10;
typedef long long ll;

struct Edge {
	int a,b;
	ll c;
	bool operator<(const Edge& x) const{
		return c > x.c;
	}
} edges[L];
int ids[L];

int check(const int node) {
	if (node == ids[node]) return node;
	return ids[node] = check(ids[node]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	ll s;
	cin >> n >> m >> s;

	int a,b;
	ll c;
	for (int i=1; i<=m; i++) {
		cin >> a >> b >> c;
		edges[i] = {a,b,c};
	}

	for (int i=1; i<=n; i++)
		ids[i] = i;

	sort(edges+1, edges+1+m);

	vector<Edge> tries;
	for (int i=1; i<=m; i++) {
		auto& [a,b,c] = edges[i];

		int A = check(a);
		int B = check(b);

		if (A == B) {
			if (c <= s) tries.push_back({i,-1,c});
			continue;
		}
		ids[A] = B;
	}

	sort(tries.begin(), tries.end());
	vector<int> todelete;
	for (int i=tries.size()-1; i>=0; i--) {
		auto& [ind,b,c] = tries[i];

		if (s >= c) {
			todelete.push_back(ind);
			s -= c;
		}
	}

	sort(todelete.begin(), todelete.end());
	cout << todelete.size() << '\n';
	for (int& x : todelete)
		cout << x << ' ';


}
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5; 
struct Node
{
	int p;
	int r;
	int maxn;
};
Node node[N];
/*
struct Monkey
{
	int l, r;
};
Monkey monkey[N];
*/
//int monkey[N][2];
int merge(int x, int y) // y points to x
{
	node[y].p = x;
	return 0;
}
int assign(int x, int y) // x assigns to y
{
	node[y].p = x;
	return 0;
}
int get(int x)
{
	if (node[x].p == x) return x;
	int y = get(node[x].p);
	//node[x].p = y;
	assign(y, x);
	return y;
}
void _union(int x, int y)
{
	x = get(x);
	y = get(y);
	if (x == y) return ;
	if (node[x].r == node[y].r) node[x].r++;
	if (node[x].r > node[y].r)
	{
		merge(x, y);
	}
	else
	{
		merge(y, x);
	}
}
/*
int get_Ans(int x)
{
	if (node[x].time != INT_MAX) return node[x].time; 
	node[x].time = get_Ans(node[x].p);
	return node[x].time;
}
*/
bool cmp(vector<int> a, vector<int> b)
{
	return a[2] > b[2];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	long long cost;
	cin >> n >> m >> cost;
	for (int i = 1; i <= n; i++)
	{
		node[i].p = i;
		node[i].r = 0;
	}
	vector< vector<int> > edges;
	for (int i = 0; i< m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		vector<int> edge = {x, y, w, 0, i};
		edges.push_back(edge);
	}
	sort(edges.begin(), edges.end(), cmp);
	int num = 0;
	for (int i = 0; i < m; i++)
	{
		int x = edges[i][0], y = edges[i][1], w = edges[i][2];
		x = get(x); y = get(y);
		if (x == y) continue;
		_union(x, y);
		edges[i][3] = 1;
	}
	vector<int> ans;
	for (int i = m - 1; i >= 0; i--)
	if (edges[i][3] == 0)
	{
		if (cost >= edges[i][2])
		{
			cost -= edges[i][2];
			num += 1;
			ans.push_back(edges[i][4]);
		}
	}
	printf("%d\n", num);
	int L = ans.size();
	for (int i = 0; i < L; i++) printf("%d ", ans[i] + 1);
	return 0;
}


