#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> para;
constexpr int L = 1e4 + 10;
constexpr int inf = INT_MAX;

struct Node{
	vector<para> conn;
	int dis=inf;
	bool vis=false;
} graph[L];

void disjkstra(int v=1){
	priority_queue<para, vector<para>, greater<para>> Q;
	
	graph[v].dis = 0;
	Q.push({graph[v].dis, v});

	while (Q.size()) {
		auto [cost, w] = Q.top();
		Q.pop();

		if (graph[w].vis) continue; 
		graph[w].vis = 1;

		for (auto& w2 : graph[w].conn) {
			if (graph[w2.first].dis > cost + w2.second) {
				graph[w2.first].dis = cost + w2.second;
				Q.push({graph[w2.first].dis,w2.first});
			}
		}
	}
}


/* prze.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	/* rodzaje metali */
	int n, price;
	cin >> n;

	for (int i=n+1; i<=2*n; i++) {
		cin >> price;
		graph[i-n].conn.push_back({i,price/2});
	}

	/* zamiany */
	int m;
	cin >> m;

	int a,b,c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		graph[a].conn.push_back({b,c});
		graph[a+n].conn.push_back({b+n,c});
	}
	disjkstra(1);
	cout << graph[n+1].dis << '\n';
}
	
