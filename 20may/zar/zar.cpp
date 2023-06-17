#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1e6 + 10;
bool arr[L];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();

	int n, m, res = 0;
	char lb;
	bool latest = 0;

	cin >> n >> m;

	for (int i=1; i<=n; i++) {
		cin >> lb;
		if (lb == '1') {
			arr[i] = 1;
			if (!latest) {
				res++;
				latest = 1;
			}
		} else latest = 0;
	}

	cout << res * 2 - arr[1] << '\n';

	int pos;
	while (m--) {
		cin >> pos;

		if (pos == 1) {
			if (!arr[2]) {
				if (arr[1]) res--;
				else res++;
			}
		}
		else if (pos == n) {
			if (!arr[n-1]) {
				if (arr[n]) res--;
				else res++;
			}
		}
		else {
			res += (arr[pos-1] && arr[pos+1]) * (arr[pos] ? 1 : -1);
			res += (!arr[pos-1] && !arr[pos+1]) * (arr[pos] ? -1 : 1);
		}

		arr[pos] = arr[pos] ^ 1;
		cout << res * 2 - arr[1] << '\n';
	}
	
}
