#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

ll k, n, m, l;
int calc(int m) {
	return k * calc(m - 1) - (k - 1) * calc(m - l);
}

/* pro.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n >> m >> l;
	ll x = pow(k, m) - ( (m - l + 1) * (m - l) * k + k) ;
	ll res =  log2(pow(x, n/m));
	cout << res << '\n';
}
