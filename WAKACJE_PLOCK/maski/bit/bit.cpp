#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 21;
int arr[L];

/* bit.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];


	for (int st=1; st<(1 << n); st++) {
		int sumA = 0,
		    sumB = 0;

		for (int j=0; j < n; j++){
			if (st & (1 << j)) sumA += arr[j];
			else sumB += arr[j];
		}
		if (sumA == sumB) {
			cout << "TAK\n";
			return 0;
		}
	}
	cout << "NIE\n";

}
	
