#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 4e4 + 10;
vector<int> graph[N];

int dis[N][2];
bool vis[N];

void bfs(int v, bool mode) {
	queue<int> q;
	q.push(v);

	while (q.size()) {
		int u = q.front(); q.pop();

		if (dis[u][mode] == 2) continue;
		for (int child : graph[u]) {

			if (vis[child] == !mode) continue;

			dis[child][mode] = dis[u][mode] + 1;
			vis[child] = !mode;
			q.push(child);
		}

	}
}

/* tel.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	int a1=0, a2=0, a3=0, a4=0;

	bfs(1, 0);
	bfs(2, 1);
	for (int i=1; i<=n; i++) {
		if (dis[i][0] == 1) 
			a1++;
		else if (dis[i][0] == 2) 
			a2++;
		if (dis[i][1] == 1)
			a4++;
		else if (dis[i][1] == 2)
			a3++;
	}
	int res = n * (n - 1) / 2 - m - (n - 1 - a1) - a1 * (1 + a4 + a3) - a2 * (1 + a4) -
      (n - 1 - a4 - 1 - a1 - a2) - min(a, a4) * (n - 1 - a1 - a2 - 1 - a4 - a3);

	cout << res << '\n';
}
	
