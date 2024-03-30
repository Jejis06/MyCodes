#include <bits/stdc++.h>
using namespace std;

constexpr int M = 5e5;
constexpr int N = 1e5 + 10;

struct edge {
    int to, id;
};

struct node {
    int ind; 
    vector<edge> edges;
    bool vis = false;

    bool operator<(const node& x) const {
	    return edges.size() < x.edges.size(); 
    }
} arr[M * 2];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> res_id;
    int n, m, y, x;
    cin >> n >> m;

    for (int i=1; i<=m; i++) {
        cin >> y >> x;

        arr[y].edges.push_back({x+n, i});
        arr[x+n].edges.push_back({y, i});

        arr[y].ind = y;
        arr[x+n].ind = x+n;
    }

    sort(arr+1, arr+2*n);

    priority_queue<node> pq;
    for (int i=1; i<=2*n; i++) {
        pq.push(arr[i]);
    }

    while (!pq.empty()) {
        node f = pq.top();
        pq.pop();

        if (arr[f.ind].vis) 
            continue; 

        vector<edge> e = arr[f.ind].edges;
        int ind = 0;
        while (arr[e[ind].to].vis && ind<e.size()) {
            if (ind == e.size() -1) {
                cout << "NIE\n";
                return 0;
            }
            ind++;
        }

        arr[ e[ind].to ].vis = !arr[ e[ind].to ].vis;
        res_id.push_back(e[ind].id);

        if (!arr[ e[ind].to ].vis) {
            pq.push(arr[e[ind].to]);
        }

        arr[f.ind].vis = true;
    }

    cout << "TAK\n" << res_id.size() << '\n';
    for (auto i : res_id) {
        cout << i << ' ';
    }
    cout << '\n';
}


