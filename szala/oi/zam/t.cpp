#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int dis[N];
bool vis[N];
vector<int> graph[N];

void bfs(int s) {
	queue<int> q;
	q.push(s);

	while (q.size()) {
		int v = q.front(); q.pop();
		vis[v] = 1;

		for (int child : graph[v]) {
			if (vis[child]) continue;
			dis[child] = dis[v] + 1;
			vis[child] = 1;
			q.push(child);
		}
	}
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;

	for (int i=0; i<m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(1);
	for (int i=1; i<=n; i++) {
		if (vis[i] == 0) cout << -1;
		else cout << dis[i];

		cout << ' ';
	}
};
