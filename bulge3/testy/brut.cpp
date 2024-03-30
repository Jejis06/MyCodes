#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6;
int arr[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q, a, b;
	cin >> n;

	for (int i=1; i<=n; i++) 
		cin >> arr[i];

	cin >> q;
	while (q--) {
		cin >> a >> b;
		int ans = -1;
		for (int i=a; i<=b; i++) 
			ans = max(ans, arr[i]);
		cout << ans << '\n';
	}
}

