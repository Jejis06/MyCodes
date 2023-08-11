#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1e5 + 10;
vector<int> graph[L];
int parents[L];


/* 7.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;

	int a,b;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		parents[b]++;
	}
	queue<int> q;

	for (int i=1; i<=n; i++)
		if (parents[i] == 0) q.push(i);

	vector<int> res;
	while (q.size()) {
		int node = q.front();
		q.pop();
		res.push_back(node);

		for (int& child : graph[node]) {
			parents[child]--;
			if (parents[child] == 0)
				q.push(child);
		}
	}

	if (res.size() == n)
		for (int& x : res)
			cout << x << ' ';
	else cout << "IMPOSSIBLE";
}
	
