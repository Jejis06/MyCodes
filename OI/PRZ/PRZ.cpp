#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int L_N = 1e5 + 7;
constexpr int L_M = 5e5 + 19;

struct edge{
	int dest, nr;
};
struct node{
	vector<edge> edges;
	bool vis = 0;

	bool operator<(const node& x) const {
		return edges.size() < x.edges.size();
	}
};

// nieparzyste -> wierzcholki to kolumny i wiersza a krawedzie to przyciski
node graph[2 * L_N];
int connected[2 * L_N];
vector<int> nieparzysteRes;



/* PRZ.cpp */
int main(){
	/* ios_base::sync_with_stdio(0);
	cin.tie(0); */

	int n,m,x,y;
	cin >> n >> m;

	for (int i=0; i<m; i++){
		cin >> y >> x;

		graph[y].edges.pb({x+n,i+1});
		graph[x+n].edges.pb({y,i+1});
	}
	sort(graph+1, graph+2*n);


	queue<int> q;
	for (int i=1; i<=2*n; i++){
		if (graph[i].edges.size() == 1) {
			connected[i]++;
			connected[graph[i].edges[0].dest]++;

			nieparzysteRes.pb(graph[i].edges[0].nr);
			q.push(graph[i].edges[0].dest);
		}
		else q.push(i);

		graph[i].vis = 1;
	}
	while (!q.empty()) {
		int f = q.front();
		q.pop();


		for (auto nei : graph[f].edges) {
			if (graph[nei.dest].vis || (graph[nei.dest].edges.size()-1) % 2 == 0) 
				continue;
			
			connected[f]++;
			connected[nei.dest]++;

			nieparzysteRes.pb(nei.nr);
			q.push(nei.dest);
		}
	}
	for (int i=1; i<=2*n; i++){
		if (connected[i] % 2 == 0) {
			cout << "NIE\n";
			return 0;
		}
	}
	cout << nieparzysteRes.size();
	for (auto i : nieparzysteRes){
		cout << i << ' ';
	}


}
	
