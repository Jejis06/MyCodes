#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e6 + 10;
vector<int> graph[N];

int dis[N];

void bfs(int v = 1) {
	queue<int> q;
	q.push(v);

	dis[v] = 0;

	while (q.size()) {
		int w = q.front(); q.pop();

		for (int child : graph[w]) {
			if (dis[child] != 0 || child == v) continue;

			dis[child] = dis[w] + 1;
			q.push(child);
		}
	}

}

/* bfs.cpp */
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
	bfs();
	cout << 0 << ' ';
	for (int i=2;i<=n;i++) {
		if (dis[i] == 0) cout << -1 << ' ';
		else cout << dis[i] << ' ';
	}
	cout << '\n';
		

}
	
