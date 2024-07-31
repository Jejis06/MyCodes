// dag, sortowanie topologiczne
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int N = 5e5 + 10;
int a[N], // prawe
    b[N], // lewe
    c[N];

vector<int> graph[N];
int deg[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }
    for (int i=0; i<n-1; i++) {
        cin >> a[i];
    }
    for (int i=1; i<n; i++) {
        cin >> b[i];
    }
    for (int i=0; i<n; i++) {
        if (a[i] < b[i+1]) {
            graph[i].push_back(i + 1);
            deg[i+1]++;
        }
        else if (a[i] > b[i+1]) {
            graph[i + 1].push_back(i);
            deg[i]++;
        }
    }
    
    queue<int> q;
    for (int i=0; i<n; i++) 
        if (deg[i] == 0) 
            q.push(i);
    
    long long price = 0;
    vector<int> ans;
    while (q.size())  {
        int node = q.front(); q.pop();
        ans.push_back(node);
        price += c[node];

        if (node + 1 <= n - 1) c[node + 1] += a[node];
        if (node - 1 >= 0) c[node - 1] += b[node];

        for (int child : graph[node]) {
            deg[child]--;
            if (deg[child] == 0) q.push(child);
        }
    }
    cout << price << '\n';
    for (int u : ans) cout << u + 1 << ' ';


}
