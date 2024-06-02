#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


constexpr int N = 2e5 + 10;

bool can(ll a, ll b, ll c) {
	return (a + b > c && a + c > b && b + c > a) ;
}

ll pre[N];
/* tro.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> pre[i];
		pre[i] += pre[i-1];
	}
	ll poss = 0;
	for (int j=1; j<n; j++) {
		for (int i=j+1; i<=n; i++) {
			ll a = pre[j];
			ll b = pre[i-1] - pre[j];
			ll c = pre[n] - pre[i-1];

			if (can(a, b, c)) poss++;

		}
	}
	cout << poss << '\n';

}
