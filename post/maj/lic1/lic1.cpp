#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e5 + 10;
int wew[N],
    zew[N],
    sum[N];

set<int> nonNines;

/* lic1.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, z;
	cin >> n >> z;

	string input;
	cin >> input;
	for (int i=2; i<=n; i++) {
		wew[i] = input[i-2] - 48;
	}
	cin >> input;
	for (int i=2; i<=n; i++) {
		zew[i] = input[i-2] - 48;
	}



	for (int i=2; i<=n; i++) {
		sum[i] += wew[i] + zew[i];
		if (sum[i] != 9)
			nonNines.insert(i);
	}

	char k;
	int i, c, lastS;
	while (z--) {
		cin >> k;
		if (k == 'S') {
			cin >> i;

			i = n - i + 1;
			
			auto prop = nonNines.upper_bound(i);
			if (i == n || prop == nonNines.end()) {
				cout << sum[i] % 10 << '\n';
				continue;
			}
			cout << (sum[i] + sum[*prop] / 10) % 10 << '\n';
			continue;
		}
		cin >> i >> c;
		i = n - i + 1;
			

		if (k == 'W') {
			lastS = sum[i];
			wew[i] = c;
			sum[i] = zew[i] + wew[i];

			if (lastS == 9 && sum[i] != 9) nonNines.insert(i);
			else if (lastS != 9 && sum[i] == 9) nonNines.erase(i);

		} else {
			lastS = sum[i];
			zew[i] = c;
			sum[i] = zew[i] + wew[i];

			if (lastS == 9 && sum[i] != 9) nonNines.insert(i);
			else if (lastS != 9 && sum[i] == 9) nonNines.erase(i);

		}

	}


}
	
