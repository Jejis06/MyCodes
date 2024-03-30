#include <bits/stdc++.h>
using namespace std;

constexpr int L = 18 + 2;
int arr[L];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=0; i<n; i++) 
		cin >> arr[i];

	for (int ulozenie=1; ulozenie<(1 << n); ulozenie++) {
		int sumA = 0,
		    sumB = 0;
		for (int j=0; j<n; j++) {
			if (ulozenie & (1 << j)) sumA += arr[j];
			else sumB += arr[j];
		}
		if (sumA == sumB) {
			cout << "TAK\n";
			return 0;
		}

	}
	cout << "NIE\n";

}
