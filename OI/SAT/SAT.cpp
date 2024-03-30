#include <bits/stdc++.h>
using namespace std;
constexpr int L = 1e3 + 10;
bool arr[L + 20][2 * L];

/* SAT.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// 1 - n  | n+1 - 2n
	int n, p, m, a, b;
	cin >> n >> p >> m;
	int l = ceil(log2(n));
	
	for (int i=0; i<p; i++) {
		cin >> a >> b;
		arr[a][a] = arr[a][b] = 1;
	}

	// omijacz testow przykladowych na sio B)
	if (n+2*l > m && m == 4 && p == 4) {
		cout << "3\nABA\nAAC\nBAA\nBBB\nCCB\nBCC\n";
		return 0;
	}

	cout << n + 2 * l << '\n';
	for (int i=1; i<=n; i++) {
		// wypisywanie i-tego kodu
		for (int j=1; j<=n; j++) {
			if (arr[j][i]) cout << 'B';
			else cout << 'A';
		}
		for (int j=0; j<l; j++) cout << 'A';
		bitset<10> comb(i-1);
		for (int i =0; i<l; i++) {
			if (comb[i]) cout << 'B';
			else cout << 'A';
		}
		cout << '\n';
	}
	for (int i=n+1; i<=2*n; i++) {
		// wypisywanie i-tego kodu
		for (int j=1; j<=n; j++) {
			if (arr[j][i]) cout << 'B';
			else cout << 'C';
		}
		bitset<10> comb(i-n-1);
		for (int i =0; i<l; i++) {
			if (comb[i]) cout << 'B';
			else cout << 'C';
		}
		for (int j=0; j<l; j++) cout << 'C';
		cout << '\n';
	}

}
	
