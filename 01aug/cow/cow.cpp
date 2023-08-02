#include <bits/stdc++.h>
using namespace std;

	/* cost , next node */
typedef pair<int,int> Para;
constexpr int inf = INT_MAX;
constexpr int L = 100 * 100;

struct Node{
	int dis = inf;
	vector<Para> conn;
	bool vis = false;
} graph[L * 3];

int prices[L];

constexpr int d2d1(int x, int y, int n){
	return y * n + x; 
}

vector<Para> pos = {
	{ 1,0},
	{-1,0},
	{0, 1},
	{0,-1},
};

void connect(int x, int y, int stepPrice, int n, int step=1){

	int org = d2d1(x,y,n);


	for (Para &i : pos) {
		int x1 = x + i.first;
		int y1 = y + i.second;

		if (!(x1 < n && y1 < n && x1 >= 0 && y1 >= 0)) continue;


		int ind = d2d1(x1, y1, n);
		if (step == 3) 
			graph[org + n * n  * (step - 1)].conn.push_back({stepPrice + prices[ind] ,ind});

		else {
			graph[org + n * n  * (step - 1)].conn.push_back({stepPrice ,ind + n * n * step});
			connect(x1, y1, stepPrice, n, step + 1);
		}


	}
}


void dijkstra(int v = 0){
	priority_queue<Para, vector<Para>, greater<Para>> pq;

	graph[v].dis = 0;
	pq.push({0,v});

	while (pq.size()) {
		auto [cost,v] = pq.top();
		pq.pop();

		if (graph[v].vis) continue;
		graph[v].vis = 1;

		for (Para &v2 : graph[v].conn) {
			if (graph[v2.second].dis > cost + v2.first) {
				graph[v2.second].dis = cost + v2.first;
				pq.push({graph[v2.second].dis, v2.second});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();

	// wymiary, czasmprzejscia
	int n,t;
	cin >> n >> t;

	int c;
	for (int i=0; i<n*n; i++) {
		cin >> c;
		prices[i] = c;
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) 
			connect(j,i,t,n);
	
	dijkstra();
	cout << min({graph[n*n-1].dis, graph[n*n*2-1].dis, graph[n*n*3-1].dis});
}
