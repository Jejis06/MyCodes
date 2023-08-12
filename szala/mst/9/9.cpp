#include <bits/stdc++.h>
using namespace std;


constexpr int L = 1e5 + 10;
int ids[L];

int find(int node) {
	if (ids[node] < 0) return node;
	return ids[node] = find(ids[node]);
}

bool unite(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	if (ids[a] > ids[b]) swap(a,b);

	ids[a] += ids[b];
	ids[b] = a;
	return 1;
}

int unionSize(int node){
	return -ids[find(node)];
}
/* 9.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,a,b;
	cin >> n >> m;

	for (int i=1; i<=n; i++) ids[i] = -1;
	int outSize = n;
	int largest = -1;

	for (int i=0; i<m; i++){
		cin >> a >> b;
		if (unite(a,b)) {
			outSize--;
			largest = max(largest, unionSize(a));
		}
		cout << outSize << ' ' << largest << '\n';
	}


}
