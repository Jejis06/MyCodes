#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int N = 1e5 + 10;

vector<int> otwierajace;
vector<int> zamykajace;

vector<int> tree[N];
int ids[N];
int depth[N];
bool vis[N];

vector<pair<int,int>> ans;

void bfs(int start) {
	
	vis[start] = 1;

	queue<int> q[2];
	short ptr = 0;

	q[0].push(start);

	int lastEg = -1,
	    EgCnt  =  0,
	    d      =  0;

	while (q[0].size() || q[1].size()) {

		int v = q[ptr].front(); q[ptr].pop();

		depth[v] = d;
		if (ids[v] == 1) {
			EgCnt++;
			if (lastEg == -1) lastEg = v;
			else {
				ans.pb({lastEg, v});
				lastEg = -1;
			}
		} else if (ids[v] == 2) {
			otwierajace.pb(v);
		} else if (ids[v] == 3) {
			zamykajace.pb(v);
		}

		for (int child : tree[v]) {
			if (vis[child]) continue;

			q[ptr ^ 1].push(child);
			vis[child] = 1;
		}
		if (q[ptr].size() == 0) {
			ptr ^= 1;
			if (EgCnt % 2 != 0) {
				cout << "NIE\n"; exit(0);
			}
			d++;
		}

	}


}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=2; i<=n; i++) {
		cin >> ids[i];
	}

	int a,b;
	for (int i=1; i<n; i++) {
		cin >> a >> b;

		tree[a].pb(b);
		tree[b].pb(a);
	}
	bfs(1);

	if (otwierajace.size() != zamykajace.size()) {
		cout << "NIE\n";
		return 0;
	}

	for (int i=otwierajace.size() - 1; i >= 0; i--) {
		if (depth[otwierajace[i]] >= depth[zamykajace[i]]) {
			cout << "NIE\n";
			return 0;
		}
		ans.pb({otwierajace[i], zamykajace[i]});
	}

	cout << "TAK\n";
	for (auto& [a, b] : ans) {
		cout << a << ' ' << b << '\n';
	}
}
