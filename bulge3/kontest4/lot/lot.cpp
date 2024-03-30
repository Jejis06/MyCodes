#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 9,
              N = 2e5 + 10,
              A = 1e3 + 10;

int pre[N][A];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, res = 0, a;
    int last = 1, ind = 0;
    vector<int> beg, en;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a;

        if (a <= last) {
            pre[ind][a]++;

            if (a == 1) {
                beg.push_back(ind);
            }
            if (a == k) {
                en.push_back(ind);
            }

            ind++;

            if (a == last)
                last++;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <A; j++) {
            pre[i][j] += pre[i-1][j];
        }
    }

    for (auto b : beg) {
        for (auto e : en) {
            a = 1;
	    int cntr = 0;

            for (int i = 2; i < ind; i++) {
		int amm = pre[e-1][i] - pre[b][i];
		if (amm <= 0) break;
		cntr++;
                a = (a * (pre[e-1][i] - pre[b][i]) ) % MOD;
            }
	    if (cntr < k - 2) a = 0;

            res = (res + a) % MOD;
        }
    }

    cout << res << '\n';

}
