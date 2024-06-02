#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
constexpr int N = 1e5 + 10;

int cols[N];

vector<int> tree[N];

int PR[N];
int PS[N];
int stree[N];
int ord = 0;


void dfs(int v, int p) {
	stree[++ord] = v;
	PR[v] = ord;
	for (int child : tree[v])
		if (child != p)
			dfs(child, v);
	PS[v] = ord;
}
int arr[N];

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


	for (int i=1; i<=n; i++) {
		 // sum of squares at this range inclusive- {PR[i], PS[i], i}
		 ll res = 0;
		 for (int j=PR[i]; j<=PS[i]; j++) arr[cols[stree[j]]]++;
		 for (int j=1; j<=n; j++) {
			 res += ll(arr[cols[stree[j]]]) * ll(arr[cols[stree[j]]]);
			arr[cols[stree[j]]] = 0;
		 }
		 cout << res << ' ';
	}
	cout << '\n';

}
	

