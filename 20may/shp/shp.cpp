#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> Para;
constexpr int L = 3001;
constexpr int inf = 1e9 + 10;

int dis[L][L];
vector<int> g[L];
vector<int> res;
unordered_map<long long, bool> forbid;
Para save[L][L];

void bfs(int start=1){
	queue<Para> Q;

	dis[1][0] = 0; //sus
	Q.push({1,0});

	while (Q.size()) {
		auto [curr, last] = Q.front();
		Q.pop();

		for (auto& nei: g[curr]) {
			long long triplet = (long long)last + (long long)L*curr + (long long)L*L*nei;

			if (dis[curr][last] + 1 < dis[nei][curr] && forbid.find(triplet) == forbid.end()) {
				dis[nei][curr] = dis[curr][last] + 1;
				save[nei][curr] = {curr, last};
				Q.push({nei, curr});
			}

		}

	}

}


/* shp.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,k;
	cin >> n >> m >> k;

	int a,b,c;
	while (m--) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	while (k--) {
		cin >> a >> b >> c;
		long long triplet = (long long)a + (long long)L*b+ (long long)L*L*c;
		forbid[triplet] = 1;
	}

	for (int i=0; i<=n; i++) 
		for (int j=0; j<=n; j++) 
			dis[i][j] = inf;
	
	bfs();



	int curr=n, last=0;
	for (int i=1; i<=n; i++) 
		if (dis[n][i] != inf && dis[n][i] < dis[n][last])
			last = i;



	if (last == 0) {
		cout << -1 << '\n';
		return 0;
	}


	res.push_back(n);
	while (curr != 1) {
		pair<int,int> x = save[curr][last];

		res.push_back(save[curr][last].first);

		curr = x.first;
		last = x.second;
	}
	reverse(res.begin(), res.end());
	
	cout << res.size() - 1<< '\n';
	for (auto& i: res)
		cout << i << ' ';
	cout << '\n';
}
	
