#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


constexpr int L = 3e5 + 10;

int conn[L];
int maxEl[L];
int minEl[L];
int id[L];


int find(int x) {
	if (id[x] == x) return x;
	return id[x] = find(id[x]); } void Union(int a, int b) { a = find(a); b = find(b);

	if(a == b) return;
	if (conn[a] > conn[b]) swap(a,b);

	id[a] = b;
	conn[b] += conn[a];
	minEl[b] = min(minEl[a], minEl[b]);
	maxEl[b] = max(maxEl[a], maxEl[b]);
}


/* B.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;

	for (int i=0; i<=n; i++) {
		id[i] = i;
		minEl[i] = i;
		maxEl[i] = i;
		conn[i] = 1;
	}

	string op;
	int a,b;

	while (m--) {
		cin >> op >> a;

		if (op[0] == 'u') {
			cin >> b;
			Union(a,b);
		}
		else {
			int ind = find(a);
			cout << minEl[ind] << ' ' << maxEl[ind] << ' ' << conn[ind] << '\n';
		}

	}


}
	
