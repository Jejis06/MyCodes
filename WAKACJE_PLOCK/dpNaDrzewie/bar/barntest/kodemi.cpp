#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
constexpr int N = 1e5 + 10;
constexpr int MOD = 1e9 + 7;
 
vector<int> edges[N];
int color[N], 
    poss[4][N];
 
ll solution(int v, int col, int par = -1, int par_col = -1) {
    // jezeli kolor jest rowny kolorowi parenta || ma juz ustawiony inny kolor
    if (col == par_col || (color[v] > 0 && color[v] != col)) 
        return 0;
 
    // juz zostalo ustawione
    if (poss[col][v] >= 0) 
        return poss[col][v];
 
    poss[col][v] = 1;
 
    for (auto child : edges[v]) {
        if (par == child)
            continue;
        
        ll child_pos = 0;
        
        for (int i=1; i<=3; i++) 
            child_pos += solution(child, i, v, col) % MOD;
 
        poss[col][v] = (poss[col][v] * child_pos) % MOD;
    }
 
    return poss[col][v];
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, k, a, b;
    cin >> n >> k;
 
    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
 
    for (int i=0; i<k; i++) {
        cin >> a >> b;
        color[a] = b;
    }
 
    // reset poss
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=3; j++) {
            poss[j][i] = -1;
        }
    }
 
    ll res = ( solution(1, 1) + solution(1, 2) + solution(1, 3) ) % MOD;
   
    cout << res << '\n';
}
