#include <bits/stdc++.h>
using namespace std;

constexpr int L = 2e5 + 10;
struct Edge {
	int a, b;
	long long cost;
	bool operator<(const Edge& x) const{
		return cost < x.cost;
	}
} edges[L];
int identifiers[L];


int check(int node) {
	if (node == identifiers[node])
		return node;
	return identifiers[node] = check(identifiers[node]);
}

/* 6.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long neededCost = 0;
	long long totalCost = 0;
	/* num edges / num vertecies */
	int n,m;
	cin >> m >> n; 
	while (m != 0 && n != 0) {
		neededCost = totalCost = 0;
		int a,b;
		long long c;
		for (int i=0; i<n; i++) {
			cin >> a >> b >> c;
			edges[i] = {a,b,c};
			totalCost += c;
		}

		for (int i=0; i<m; i++) 
			identifiers[i] = i;
		sort(edges, edges + n);


		for (int i=0; i<n; i++) {
			Edge e = edges[i];

			int aI = check(e.a);
			int bI = check(e.b);

			if (aI == bI) continue;

			identifiers[aI] = bI;
			neededCost += e.cost;

		}
		cout << totalCost - neededCost << '\n';
		cin >> m >> n; 
	}
}
	
