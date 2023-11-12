#include <bits/stdc++.h>
using namespace std;
 
constexpr int N = 1e6;
int arr[N];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    vector<int> exist;
    cin >> n >> m;
 
    for (int i=0; i<m; i++) {
        cin >> arr[i];
    }
 
    for (int i=0; i<m; i++) {
        exist.clear();
 
        for (int j=0; j<m; j++) {
            // sprawdz czy istnieje jakis taki sam element przed i oraz po i
            if (j > i) {
                for (auto k : exist) {
                    if (arr[j] == k) {
                        arr[i] = k;
                        break;
                    }
                } 
            }
            else if (j != i)
                exist.push_back(arr[j]);
        }
    }
 
    for (int i=1; i<m; i++) {
        cout << arr[i] << ' ';
    }
 
}
