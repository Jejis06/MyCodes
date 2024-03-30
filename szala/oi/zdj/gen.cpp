#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1e6;
int deg[L];
vector<int> friends[L];

mt19937 r;
int randR(int a, int b) {
	return r() % (b - a + 1) + a;
}
bool notFriend(int v, int c) {
	bool x;
	x = true;
	for (int child : friends[v]) 
		if (child == c) 
			x = false;

	for (int cl : friends[c]) 
		if (cl == v) 
			x = false;
	return x;

}

int main() {
	/* ios_base::sync_with_stdio(0);
	cin.tie(0); */

	int seed;
	cin >> seed;
	r.seed(seed);

	int n = r() % 10 + 1;

	int m = 0;
	bool yes = 1;
	while (yes) {

		yes = 0;

		for (int i=1; i<=n; i++) {
			if (friends[i].size() % 2 != 0 || friends[i].size() == 0) {
				yes = 1;
				break;
			}
		}
		if (!yes) break;
		for (int i=1; i<=n; i++) {
			if (friends[i].size() % 2 != 0 || friends[i].size() == 0) {
				int c = i;
				while (c == i || !notFriend(i, c)){
					c = randR(1, n);
				} 
				friends[i].push_back(c);
				m++;
			}
		}


	}
	cout << n << ' ' <<  m << '\n';
	for (int i=1; i<=n; i++) {
		for (auto child : friends[i])
			cout << i << ' ' << child << '\n';

	}

}
