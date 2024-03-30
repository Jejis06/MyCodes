#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int L = 5e5 + 10;
vector<int> inGraph[L];

vector<int> Graph[L];
bool inQueue[L];
int deg[L];
int labels[L];
bool vis[L];


/* zdj.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;

	for (int i=0; i<m; i++) {
		cin >> a >> b;

		inGraph[a].pb(b);
		inGraph[b].pb(a);
	}

	bool all = true;
	for (int i=1; i<=n; i++) 
		if (inGraph[i].size() > 0) {all = false; break;}

	if (all) {
		cout << "TAK\n";
		for (int i=1; i<=n; i++) cout << i << ' ';
		return 0;
	}

	// jezeli dwa specjalne wierzcholki sa odlaczone niemozliwe jest poprawne ustawienie
	if (inGraph[1].size() == 0 || inGraph[2].size() == 0) {
		cout << "NIE\n";
		return 0;
	}

	// uzupelnianie odlaczonych wierzcholkow
	for (int i=3; i<=n; i++) {
		if (inGraph[i].size() == 0) {
			deg[i] = 1;
			deg[2]++;

			Graph[i].pb(2);
			Graph[1].pb(i);
		}
	}


	queue<int> q;
	int connected{};
	q.push(1);

	while (q.size()) {
		int v = q.front(); q.pop();
		inQueue[v] = 0;
		vis[v] = 1;

		for (int child : inGraph[v]) {
			if (vis[child]) continue;
			if (inQueue[child] && child != 2) {
				cout << "NIE\n";
				return 0;
			} 

			Graph[v].pb(child);
			connected++;
			deg[child]++;

			if (child != 2 && deg[child] == inGraph[child].size() / 2){
				q.push(child);
				inQueue[child] = 1;
			}

		}
	}
	if (connected != m) {
		cout << "NIE\n";
		return 0;
	}

	// toposort
	queue<int> anc;
	anc.push(1);

	int counter = 1;
	while (anc.size()) {
		int v = anc.front(); anc.pop();
		labels[v] = counter++;
		for (int& child : Graph[v]) {
			deg[child]--;
			if (deg[child] == 0) anc.push(child);
		}
	}
	cout << "TAK\n";
	for (int i=1; i<=n; i++) 
		cout << labels[i] << ' ';
}
	
