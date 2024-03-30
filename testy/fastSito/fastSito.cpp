#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 2e7;
bool isPrime[N+1];

constexpr void build(const int n) {
	int x = 0;
	for (int i=2; i*i<=n; i++) {
		if (!isPrime[i]){
			for (int j=i*i; j<=n; j+=i) {
				isPrime[j] = 1;
			}
		}
	}
}



/* fastSito.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	build(N);
	isPrime[1] = 1;
	int cntr = 0;
	int i = 2;
	while (cntr != n) {
		if (isPrime[i] == 0) {
			cout << i << '\n';
			cntr++;
		}
		i++;
	}

}
