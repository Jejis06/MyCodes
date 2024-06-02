#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000;
bool tr[N][N];
int id[N];


int find(int x) {
	if (id[x] == x) return x;
	return id[x] = find(id[x]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	id[b] = a;
}

mt19937 r;
int randRange(int a, int b) {
	return r() % (b - a) + a;
}

int main() {
	int seed;
	cin >> seed;

	r.seed(seed);
	int n = randRange(2, 20);

	for(int i=0; i<=n; i++) 
		id[i] = i;

	// n
	cout << n << '\n';

	// colors
	for (int i=1; i<=n; i++) 
		cout << randRange(1, n) << ' ';
	cout << '\n';
	// graph
	for (int i=2; i<=n; i++) {
		int conn = i;
		while (find(conn) == find(i) || conn == i || tr[i][conn] || tr[conn][i]) {
			conn = randRange(1, n);
		}
		cout << i << ' ' << conn << '\n';
		tr[i][conn] = 1;
		Union(i, conn);
	}


}
