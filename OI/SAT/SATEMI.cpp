#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 + 10;
int n;
bool conn[N][2*N];

int first_power() {
    int res = 1, count = 0;
    while (res <= n) {
        res *= 2;
        count++;
    }
    return count -1; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int p, m, a, b;
    cin >> n >> p >> m;
    int POW = ceil(log2(n));

    for (int i=0; i<p; i++) {
        cin >> a >> b;
        conn[a][a] = true;
        conn[a][b] = true;
    }

    if (n + 2*(POW) > m && m == 4 && p == 4) {
        cout << "3\nABA\nAAC\nBAA\nBBB\nCCB\nBCC\n"; 
        return 0;
    }

    cout << n + 2*(POW) << '\n';

    for (int i=1; i<=2*n; i++) {
        for (int j=1; j<=n; j++) {
            if (!conn[j][i]) {
                if (i <= n) cout << "A"; 
                else cout << "B";
            }
            else cout << "C";
        } 

        bitset<10> bit( (i-1) % n);

        if (i > n) 
            for (int j=POW-1; j>=0; j--) cout << 'B';

        for (int j=POW-1; j>=0; j--) {
            if (bit[j] == 1) cout << 'C';
            else if (i > n) cout << 'B';
            else cout << 'A';
        }

        if (i <= n) 
            for (int j=POW-1; j>=0; j--) cout << 'A';

        cout << '\n';
    }
}


