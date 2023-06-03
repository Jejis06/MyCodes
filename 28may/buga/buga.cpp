#include <bits/stdc++.h>
using namespace std;

constexpr int L = 4e5 + 10;
constexpr int inf = INT_MAX;

typedef pair<int,int> para;

struct Node{
	vector<para> conn; /* cost, peak */
	int dis = inf;
	bool visited = 0;
} graph[L];

int n;

void dijkstra(int start=1){
	priority_queue<para, vector<para>, greater<para>> Q;

	graph[start].dis = 0;
	Q.push({0,start});

	while (Q.size()) {
		auto [cost, ver] = Q.top();
		Q.pop();

		if (graph[ver].visited) continue;
		graph[ver].visited = 1;

		for (auto& [cost2, ver2] : graph[ver].conn) {
			if (graph[ver2].dis > cost + cost2) {
				graph[ver2].dis = cost + cost2;
				Q.push({graph[ver2].dis, ver2});
			}

		}


	}


}

/* buga.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	/* miasta, drogi */
	int m;
	cin >> n >> m;

	int a,b,c;
	for (int i=0; i<m ;i++) {
		cin >> a >> b >> c;

		if (c%2 == 1) {
			/* polaczenie miedzy roznymi parzystosciami */
			graph[a].conn.push_back({c,b+n});
			graph[b+n].conn.push_back({c,a});
			
			graph[a+n].conn.push_back({c,b});
			graph[b].conn.push_back({c,a+n});
		} else {
			/* polaczeni miedzy tymi samymi parzystosciami */
			graph[a].conn.push_back({c,b});
			graph[b].conn.push_back({c,a});

			graph[a+n].conn.push_back({c,b+n});
			graph[b+n].conn.push_back({c,a+n});

		}

	}

	dijkstra();
	if (graph[n+n].dis != inf) cout << graph[2 * n].dis << '\n';
	else cout << 0 << '\n';
	

}
	
