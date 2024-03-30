#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int L = 5e5 + 10;


/*-challange na nastepny tydzien --------------------------------------

  odejmmujemy 1 tylko parentowi 
  jezeli chce odczytac stopien wierzcholka to sprawdzam usuniete dzieci (ile ich zostalo) i w zaleznosci,
  jezeli parent istnieje dodaje 1. tak obliczam stopnien i do wyniku dodaje stopien - 1

  -----------------------------------------------------------------------*/

bool deleted[L];
int parent[L];
int children[L];
vector<int> conn[L];

bool vis[L];

int sub = 1;


void dfs(int v=1) {
	vis[v] = 1;
	for (int child : conn[v]) {
		if (vis[child]) continue;
		if (parent[v] != child) children[v]++;

		parent[child] = v;
		dfs(child);
	}
}

void add(int v) {
	int deg = children[v];
	sub -= deg + !deleted[parent[v]] - 1;

	children[parent[v]]++;
	deleted[v] = 0;
}
void remove(int v) {
	int deg = children[v];
	sub += deg + !deleted[parent[v]] - 1;

	children[parent[v]]--;
	deleted[v] = 1;
}

/* str.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, a, b, q, d;
	cin >> m;
	while (m-- > 1) {
		cin >> a >> b;
		conn[a].pb(b);
		conn[b].pb(a);
	}

	dfs();
	deleted[0] = 1;

	cin >> q;
	while (q--) {
		cin >> d;
		if (d > 0) remove(d);
		else add(-d);

		cout << sub << '\n';
	}

}

