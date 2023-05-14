#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

constexpr long long inf = LLONG_MAX;
constexpr int L = 1e5 + 10;

struct node{
	vector<pair<int,int>> conn;
	long long dis = inf;
	bool visited=false;
}graph[L];
stack<int> P;

/* dijkstra */
void dijkstra(int v = 1){

	typedef pair<long long,int> para;

	priority_queue<para,vector<para>, greater<para>> Q;
	int w;
	long long cost;

	graph[v].dis = 0;
	Q.push({graph[v].dis,v});

	while (Q.size()) {
		cost = Q.top().first;
		w = Q.top().second;

		Q.pop();

		if(graph[w].visited) continue;
		graph[w].visited = 1;

		for (auto& w2 : graph[w].conn) {
			if(graph[w2.first].dis > cost + w2.second) {
				graph[w2.first].dis = cost + w2.second;
				Q.push({graph[w2.first].dis,w2.first});
			}
		}



	}

}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	/* wierzcholki, polaczenia */
	int n,m;
	cin >> n >> m;

	int a,b,w;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> w;
		graph[a].conn.push_back({b,w});
		graph[b].conn.push_back({a,w});
	}
	
	dijkstra();

	if (graph[n].dis == inf) {
		cout << -1 << '\n';
		return 0;
	}
	
	int v = n;
	while (v != 1) {
		for (auto& w:graph[v].conn) {
			if (graph[w.first].dis + w.second == graph[v].dis) {
				v = w.first;
				P.push(v);
			}
		}
	}

	while (!P.empty()) {
		cout << P.top() << ' ';
		P.pop();
	}
	cout << n << '\n';





}
