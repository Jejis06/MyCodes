#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 2e5 + 10;
pair<int,int> arr[L];

vector<int> graph[L];
int id[L];

unordered_map<int, int> X, Y;

int n;

void dfs(int v, int org){
	id[v] = org;
	for (int child : graph[v]) if (!id[child]) dfs(child, org);
}


/* met.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, x, y;
	cin >> n >> t;

	for (int i=1; i<=n; i++) {
		cin >> x >> y;
		arr[i] = {x,y};

		X[x] = Y[y] = i;
	}

	for (int i=1; i<=n; i++) {
		x = arr[i].first;
		y = arr[i].second; 

		if (X[x] != i) {
			graph[i].pb(X[x]);
			graph[X[x]].pb(i);
		}
		if (Y[y] != i) {
			graph[i].pb(Y[y]);
			graph[Y[y]].pb(i);
		}

	}
	for (int i=1; i<=n; i++) if (!id[i]) dfs(i,i);
	int a, b;
	for (int i=0; i<t; i++) {
		cin >> a >> b;
		if (arr[a].first == arr[b].first || arr[a].second == arr[b].second) {
			cout <<  "TAK\n";
			continue;
		}

		cout << ((id[a] == id[b]) ? "TAK" : "NIE") << '\n';
	}


}
	
