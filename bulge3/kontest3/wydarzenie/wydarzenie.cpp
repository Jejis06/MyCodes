#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e6 + 10;
int id[N];

int find(int x) {
	if (x == id[x]) return x;
	return id[x] = find(id[x]);
}
void Union(int a, int b) {
	a = find(a); b = find(b);

	if (a == b) return;
	if (a > b) swap(a, b);
	id[b] = a;
}


/* wydarzenie.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, m;
	cin >> n;
	for (int i=1; i<=n; i++)
		id[i] = i;
	for (int i=1; i<=n; i++) {
		cin >> x;
		if (x != 0) Union(i, x);
	}
	cin >> m;
	set<int> res;

	for (int i=0; i<m; i++) {
		cin >> x;
		res.insert(find(x));
	}
	cout << res.size() << '\n';

}
