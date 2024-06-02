#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

const int K = (1 << 13) + 10;
int occ[K];


/* kom2.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	char bit;
	int num;

	cin >> n >> k;

	for (int i=0; i<n; i++) {
		num = 0;
		for (int j=k-1; j>=0; j--) {
			cin >> bit;
			if (bit == '1') num += (1 << j);
		}
		occ[num]++;
	}

	ll res = 0;
	for (int i=1; i<(1 << k); i++) {
		int val = occ[i];
		if (!val) continue;
		res += (val * (val - 1)) / 2;
		for (int j=i+1; j<(1 << k); j++){
			if (i & j)
				res += val * occ[j];
		}

	}
	cout << res << '\n';
}
	
