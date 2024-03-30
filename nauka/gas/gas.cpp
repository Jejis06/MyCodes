#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e6;
constexpr int mod = 1e9;

int arr[N];
bool vis[N];

/* gas.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int l = 0, r = -1;
	int ans = 0;
	while (r < n-1) {
		r++;
		while (vis[arr[r]]) {
			vis[arr[l]] = 0;
			l++;
		}
		vis[arr[r]] = 1;
		ans = (ans + r - l + 1) % mod;
	}
	cout << ans << '\n';

}
	
