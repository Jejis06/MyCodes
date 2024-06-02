#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e5 + 10;
int ciag[N];
int diff[N];
int num[N];

/* podAr.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q, a, b;

	cin >> n >> q;
	cin >> b;
	for (int i=2; i<=n; i++) {
		cin >> a;
		diff[i] = a - b;
		if (diff[i] == diff[i-1]) 
			num[i] = num[i - 1];
		num[i]++;

		b = a;
	}
	while (q--) {
		cin >> a >> b;
		if (num[b] >= b - a || b - a < 2) {
			cout << "TAK\n";
		} else cout << "NIE\n";
	}
}
	
