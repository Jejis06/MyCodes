#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int a,b,cost;
	bool operator<(const Edge& x) const {
		return cost < x.cost;
	}

};

/* code from leetcode */
class Solution {
private:
	static const int L = 5e5 + 510;
	Edge edges[L];
	int ids[L];

	int check(int node) {
		if (ids[node] == node) return node;
		return ids[node] = check(ids[node]);
	}
	int calculateCost(int x1, int y1, int x2, int y2) const {
		return abs(x1 - x2) + abs(y1 - y2);
	}

public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		int n = points.size();
		int k = 0;
		int cost;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				cost = calculateCost(points[i][0],points[i][1],points[j][0],points[j][1]);
				edges[k] = { i, j, cost };
				k++;
			}
		}

		for (int i=0; i<n; i++) 
			ids[i] = i;

		sort(edges, edges + k);

		int pathL = 0;
		int i=0;
		int step=0;
		for (int i=0; i<k && step < n-1; i++) {
			auto& [a,b,cost] = edges[i];
			
			int A = check(a);
			int B = check(b);

			if (A == B) continue;
			step++;
			pathL += cost;
			ids[A] = B;
		}
		return pathL;

	}
};
