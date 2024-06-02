#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e5 + 10;
int wew[N],
    zew[N],
    sum[N];

void add(int n) {
	for (int i=0; i<n-1; i++) {
		sum[i] += wew[i] + zew[i];
		if (sum[i] > 9) {
			sum[i+1] += sum[i] / 10;
			sum[i] %= 10;
		}

	}

}
void repair(int p, int delta, int n) {
	sum[p] += delta;
	if (sum[p] < 0) {
		int e = -1;
		for (int i=p+1; i<=n-1; i++) {
			if (sum[i] > 0) {
				e = i;
				break;
			}
		}
		if (e == -1) {
			return;
		}
		sum[e]--;

		for (int i=e-1; i>p; i--) 
			sum[i] = 9;
		sum[p] += 10;

	} else if (sum[p] > 9) {
		for (int i=p; i<n-1; i++) {
			if (sum[i] <= 9) break;
			sum[i + 1] += sum[i] / 10;
			sum[i] %= 10;
		}

	}
}

/* lic1.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, z;
	cin >> n >> z;

	string input;
	cin >> input;
	for (int i=n-2; i>=0; i--) {
		wew[i] = input[(n-2) - i] - 48;
	}
	cin >> input;
	for (int i=n-2; i>=0; i--) {
		zew[i] = input[(n-2) - i] - 48;
	}
	add(n);

	char k;
	int i, c, delta;
	while (z--) {
		cin >> k;
		if (k == 'S') {
			cin >> i;
			i--;
			cout << sum[i] << '\n';
			continue;
		}
		cin >> i >> c;
		i--;

		if (k == 'W') {
			delta = c - wew[i];
			wew[i] = c;
			repair(i, delta, n);
		} else {
			delta = c - zew[i];
			zew[i] = c;
			repair(i, delta, n);

		}

	}


}
	
