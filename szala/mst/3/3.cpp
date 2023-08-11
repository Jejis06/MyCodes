#include <bits/stdc++.h>
using namespace std;


constexpr int L = 1e4 + 10;
constexpr int lim = 1e9 + 10;
struct Edge{
	int a,b;
	int c;
	bool operator<(const Edge& x) const{
		return c < x.c;
	}

} edges[L];
int ids[L];

int check(int node){
	if (node == ids[node]) return node;
	return ids[node] = check(ids[node]);
}




/* 3.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	/* vertecies / edges */
	cin >> n >> m;

	int a,b;
	int c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		edges[i] = {a,b,c};
	}

	sort(edges, edges+m);
	int res = 2 * lim;


	for (int i=0; i<m; i++) {
		int maxD = -lim;
		int minD = lim;
		int numEdges = 0;

		for (int j=1; j<=n; j++) 
			ids[j] = j;

		for (int j=i; j<m; j++) {

			auto& [a,b,c] = edges[j];
			int A = check(a);
			int B = check(b);

			if (A != B) {
				ids[A] = B;
				minD = min(c, minD);
				maxD = max(c, maxD);
				numEdges++;
			} 
			if (numEdges == n-1) {
				res = min(res, maxD - minD);
				break;
			} 
		}
	}
	if (res == 2 * lim) cout << "NO\n";
	else cout << "YES\n" << res;

}
	
