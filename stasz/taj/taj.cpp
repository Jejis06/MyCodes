#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e5 + 10;
vector<pair<int,int>> levels[N];
vector<int> tree[N];
bool vis[N];
int maf[N];
int maxDepth = -1;

void dfs(int v=1, int depth=0) {

	maxDepth = max(depth, maxDepth);

	if (v != 1 && maf[v] != 0) 
		levels[depth].pb({maf[v], v});
	vis[v] = 1;
	for (int child : tree[v]) {
		if (vis[child]) continue;
		dfs(child, depth+1);
	}
}


/* taj.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=2; i<=n; i++) 
		cin >> maf[i];

	int a, b;
	for (int i=1; i<n; i++) {
		cin >> a >> b;
		tree[a].pb(b);
		tree[b].pb(a);
	}
	dfs();

	vector<pair<int,int>> ans;
	queue<int> gorniOtwierajacy, tempOtwierajacy, agilarni;


	for (int i=0; i<=maxDepth; i++) {
		if (levels[i].empty()) continue;

		for (auto [id, agent] : levels[i]) {
			
			if (id == 1) {
				agilarni.push(agent);
			}
			else if (id == 2) {
				tempOtwierajacy.push(agent);
			}
			else if(id == 3) {
				if (gorniOtwierajacy.empty()) {
					cout << "NIE\n";
					return 0;
				}
				ans.pb({gorniOtwierajacy.front(), agent});
				gorniOtwierajacy.pop();
			}
		}
		if (agilarni.size() % 2 != 0) {
			cout << "NIE\n";
			return 0;
		}
		while (agilarni.size()) {
			int f = agilarni.front(); agilarni.pop();
			int s = agilarni.front(); agilarni.pop();
			ans.pb({f, s});
		}
		while(tempOtwierajacy.size()) {
			gorniOtwierajacy.push(tempOtwierajacy.front()); tempOtwierajacy.pop();
		}

	}
	if (gorniOtwierajacy.size() != 0) {
		cout << "NIE\n";
		return 0;
	}
	cout << "TAK\n";
	for (auto& [a,b] : ans) {
		cout << a << ' ' << b << '\n';
	}


}
	
