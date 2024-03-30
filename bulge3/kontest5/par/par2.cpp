#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 10;

int npre[N], mpre[N];
int *np, *mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, q;
    cin >> q;

    while (q--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            cin >> x;
            x %= 2;
            npre[i] = npre[i-1] + x;
        }

        for (int i = 1; i <= m; i++) {
            cin >> x;
            x %= 2;
            mpre[i] = mpre[i-1] + x;
        }

        
        np = &npre[0];
        mp = &mpre[0];

        if (n < m) {
            np = &mpre[0];
            mp = &npre[0];

            swap(n, m);
        }

        int res = 0;

        for (int i = 1; i <= n - m + 1; i++) {
            int en = np[i + m - 1] - np[i + m - 2],
                sn = np[i] - np[i - 1],
                em = mp[m] - mp[m - 1],
                sm = mp[1] - mp[0];

            bool sum1 = (np[i + m - 1] - np[i-1]) % 2,
                 sum2 = mp[m] % 2;

            if (sum1 == sum2) {
                res = m;
                break;
            }

            if (sn != sm || en != em || sn != em || sm != en) {
                res = max(res, m - 1);
		continue;
            }
            
            x = !sn;

            int len = INT_MAX;
	    int b,e=-1;

            for (int j = 1; j <= m; j++) {
                if (np[j + 1] - np[j + i - 1] == x || mp[j] - mp[j - 1] == x) {
                    len = j;
		    b = j;
                    break;
                }
            }

            int it = 1;
            for (int j = m; j >= 1; j--) {
                if (np[j + i] - np[j + i - 1] == x || mp[j] - mp[j - 1] == x) {
		    if (it < len) {
			    len = it;
			    e = j;
		    }
                    break;
                }
                it++;
            }
	    cout << b << '_' << e << '\n';
	    res = max(res, m - len);
        }

        cout << res << '\n';
    }
}


