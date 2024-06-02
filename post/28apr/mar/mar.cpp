#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e5 + 10;
bool arr[N];

unordered_map<int,int> ks[17];
unordered_map<int,int> val[N];

void ans() {
	for (int i=1; i<=16; i++) {
		if (ks[i].size() < (1 << i)) {
			cout << i << '\n';
			return;
		}
	}
	cout << 17 << '\n';
	return;
}

/* mar.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, x;
	string s;
	cin >> n >> m >> s;
	for (int i=0; i<n; i++) {
		if (s[i] == '1')
			arr[i + 1] = 1;

	}
	
	for (int i=1; i<=n; i++) {
		int mask = 0;
		for (int k=1; k<17; k++) {
			if (i + k - 1 > n) break;
			if (arr[i + k - 1]) mask += (1 << k);
			ks[k][mask]++;
			val[i][k] = mask;
		}
	}

	ans();
	while (m--) {
		cin >> x;
		arr[x] = !arr[x];

		int start = max(1, x - 15);

		for (int i=start; i<=x; i++) {
			int mask = 0;
			for (int k=1; k<17; k++) {
				if (i + k - 1 > n) break;
				if (arr[i + k - 1]) mask += (1 << k);
				if (i + k - 1 < x) continue;
				ks[k][val[i][k]]--;
				if (ks[k][val[i][k]] == 0) ks[k].erase(val[i][k]);
				ks[k][mask]++;
				val[i][k] = mask;
			}
		}
		ans();

	}

}
	
