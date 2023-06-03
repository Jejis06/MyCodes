#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> para;
 
constexpr int N = 100 + 10;
constexpr int oo = INT_MAX;
 
struct node {
    bool visited;
    int cost = oo;
    vector<int> edges;
 
} arr[N * N * 3];
 
 
void dijkstra() {
    priority_queue<para, vector<para>, greater<para>> pq;
    arr[1].cost = 0;
    pq.push({0, 1});
 
    while (!pq.empty()) {
        para f = pq.top();
        pq.pop();
 
        if (arr[f.second].visited) continue;
        arr[f.second].visited = true;
 
        for (auto i : arr[f.second].edges) {
            int x = f.first + i;
 
            if (x < arr[i.second].cost) {
                arr[i.second].cost = x;
                pq.push({x, i.second});
            } 
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    int n, t, a;
    cin >> n >> t;
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int nr = j*i + j;
            cin >> a;
            arr[nr + 2*N].var = a;
 
            // 1
            arr[nr].edges.push_back(nr + N + 1);
            arr[nr].edges.push_back(nr + N - 1);
            arr[nr].edges.push_back(nr + N + n);
            arr[nr].edges.push_back(nr + N - n);
 
            // 2
            arr[nr+N].edges.push_back(nr + 2*N + 1);
            arr[nr+N].edges.push_back(nr + 2*N - 1);
            arr[nr+N].edges.push_back(nr + 2*N + n);
            arr[nr+N].edges.push_back(nr + 2*N - n);
 
            // 3
            arr[nr+2*N].edges.push_back(nr + 1);
            arr[nr+2*N].edges.push_back(nr - 1);
            arr[nr+2*N].edges.push_back(nr + n);
            arr[nr+2*N].edges.push_back(nr - n);
 
        }
    }
}
