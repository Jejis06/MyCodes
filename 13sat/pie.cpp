#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1001;
string board[M];

vector<pair<int,int>> piec;


bool stamp(int i, int j, int n, int m){
	for (auto& x : piec) {
		if (i + x.first >= n || i + x.first < 0 || j + x.second < 0 || j + x.second >= m) return 0;
		if (board[i + x.first][j + x.second] == '.') return 0;
		board[i + x.first][j + x.second] = '.';
		
	}
	return 1;
}

void solve() {
	int n,m,a,b;
	char c;

	cin >> n >> m >> a >> b;

	for (int i=0; i<n; i++) cin >> board[i];
	for (int i=0; i<a; i++){
		for (int j=0; j<b; j++) {
			cin >> c;
			if (c == 'x') piec.push_back({i,j});
		}
	} 

	for (size_t i=1; i<piec.size(); i++) {
		piec[i].first -= piec[0].first;
		piec[i].second -= piec[0].second;
	}
	piec[0] = {0,0};

	bool ok = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (board[i][j] == 'x') ok = stamp(i,j,n,m);
			if(!ok) goto endloop;
		}
	}

	endloop:;

	for (int i=0; i<n; i++) board[i].clear();
	piec.clear();
	cout << (ok ? "TAK\n" : "NIE\n");
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int x;
	cin >> x;

	while (x--) solve();
}
