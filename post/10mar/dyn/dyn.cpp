#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int L = 3e5 + 10;

vector<int> tree[L];
bool dyn[L];

int fire[L];
int disDyn[L];

int needed;

void dfs(int v, int p, int x) {

	if (dyn[v]) disDyn[v] = 0;

	for (int child : tree[v]) {

		if (child == p) continue;
		dfs(child, v, x);

		if (disDyn[child] != -1) disDyn[v] = max(disDyn[v], disDyn[child] + 1);
		if (fire[child] != -1) {
			if (fire[v] == -1) fire[v] = fire[child] + 1;
			else fire[v] = min(fire[v], fire[child] + 1);
		}
	}
	// nie ma czego podpalac 
	if (disDyn[v] == -1) return;

	if (fire[v] != -1 && (disDyn[v] + fire[v] <= x)) disDyn[v] = -1;
	else if (disDyn[v] == x || v == 1) {
		disDyn[v] = -1;
		fire[v] = 0;
		needed++;
	}
}

/* dyn.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;

	for (int i=1; i<=n; i++)
		cin >> dyn[i];

	for (int i=1; i<n; i++) {
		cin >> a >> b;
		tree[a].pb(b);
		tree[b].pb(a);
	}

	int l=0, r=n;
	while (l < r) {
		int mid = (l + r) / 2;
		needed = 0;
		for (int i=1; i<=n; i++) 
			disDyn[i] = fire[i] = -1;
		dfs(1, 0, mid);

		if (m >= needed) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';

}
	
