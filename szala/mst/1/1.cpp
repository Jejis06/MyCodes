#include <bits/stdc++.h>
using namespace std;


constexpr int L = 2e5 + 10;
struct Edge{
	int a,b;
	long long c;
	bool operator<(const Edge& x) const{
		return c < x.c;
	}

} edges[L];
int ids[L];

int check(int node){
	if (ids[node] == node) return node;
	return ids[node] = check(ids[node]);
}
/* 1.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	long long o=0;
	cin >> n >> m;

	int a,b;
	long long c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		edges[i] = {a,b,c};
	}

	for (int i=1; i<=n; i++)
		ids[i] = i;

	sort(edges, edges + m);
	for(int i=0; i<m; i++) {
		auto& [a,b,c] = edges[i];

		int A = check(a);
		int B = check(b);

		if (A == B) continue;
		ids[A] = B;
		o += c;
	}
	cout << o;



}
	
