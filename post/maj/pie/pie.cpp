#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> para;

constexpr int N = 100 + 10;
constexpr int P = 20 + 10;

bitset<N> picture[N];
bitset<N> mask[N];
vector<para> on;
vector<para> stamps[P];

bool solve(int w, int s, int p) {
	for (int i=0; i<p; i++) {
		for (auto& [y, x] : on) {
			bool ok = true;
			for (auto& [y1, x1] : stamps[i]) {
				if (y + y1 < 0 || y + y1 >= w || 
				    x + x1 < 0 || x + x1 >= s || 
				    picture[y + y1][x + x1] == 0) 
				{
					ok = false;
					break;
				}
			}
			if (!ok) continue;
			for (auto& [y1, x1] : stamps[i]) 
				mask[y + y1][x + x1] = 0;
		}
	}
	int sum = 0;
	for (int i=0; i<w; i++) {
		sum += mask[i].count();
	}
	return (sum == 0);
}

/* pie.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	on.reserve(N * N);

	int w, s, p, r, c;
	char in;
	cin >> w >> s;
	for (int y = 0; y < w; y++) {
		for (int x = 0; x < s; x++) {
			cin >> in;
			if (in == '#') {
				picture[y][x] = 1;
				mask[y][x] = 1;
				on.pb({y, x});
			}
		}
	}
	bool orgSet;
	para org;
	cin >> p;
	for (int i=0; i<p; i++) {
		cin >> r >> c;
		orgSet = 0;
		for (int y=0; y<r; y++) {
			for (int x = 0; x < c; x++) {
				cin >> in;
				if (in == '#') {
					if (orgSet) {
						stamps[i].pb({y - org.first, x - org.second});

					} else {
						orgSet = 1;
						org = {y, x};
						stamps[i].pb({0, 0});
					}
				}
			}
		}
	}
	cout << (solve(w, s, p) ? "TAK" : "NIE") << '\n';

}
	
