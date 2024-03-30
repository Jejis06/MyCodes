#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<long long, int> para;

constexpr int N = 1e5 + 10;
constexpr long long inf = LLONG_MAX;

struct Node{
	vector<pair<int,int>> conn;
	long long dis = inf;
	bool vis;
} graph[N];

void disjkstra(int v = 1) {
	priority_queue<para, vector<para>, greater<para>> pq;

	graph[v].dis = 0;
	pq.push({0, v});
	while (pq.size()) {
		auto [cost, w] = pq.top(); pq.pop();

		if (graph[w].vis) continue;
		graph[w].vis = 1;

		for (auto [child, childCost] : graph[w].conn) {
			if (graph[child].dis > cost + childCost) {
				graph[child].dis = cost + childCost;
				pq.push({cost + childCost ,child});
			}
		}
	}

}


/* dij.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		graph[a].conn.pb({b, c});
		graph[b].conn.pb({a, c});
	}
	disjkstra();
	if (graph[n].dis == inf) {
		cout << -1 << '\n';
		return 0;
	}
	stack<int> q;
	int v = n;
	while (v != 1) {
		for (auto [child, dist] : graph[v].conn) {
			if (graph[v].dis == dist + graph[child].dis) {
				v = child;
				q.push(child);
			}

		}
	}
	while (q.size()) {
		cout << q.top() << ' ';
		q.pop();
	}
	cout << n << '\n';

}
	
