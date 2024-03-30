#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int P = 10;
int sum[51] = {};

void dodaj(uint64_t x) {
	int i = 0;
	while (x) {
		int cyfra = x % P;
		x /= P;

		sum[i] += cyfra;
		if (sum[i] >= P) {
			sum[i] -= P;
			sum[i + 1]++;
		}
		i++;
	}

	// sprawdzenie czy nie zostawilismy nadwyzki
	while (sum[i] >= P) {
		sum[i] -= P;
		sum[i + 1]++;
		i++;
	}

}
// hakerskie wypisywanie
ostream& operator<<(ostream& o, const int* x){
	bool wasnotzero = 0;
	for (int i=50; i>=0; i--) {
		if (!x[i] && !wasnotzero) continue;
		wasnotzero = 1;
		o << x[i];
	}
	return o;
}


/* sum.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	uint64_t a;
	cin >> n;

	for (int i=1; i<=n; i++) {
		cin >> a;
		dodaj(a * i * (n - i + 1));
	} 
	cout << sum << '\n';
}
	
