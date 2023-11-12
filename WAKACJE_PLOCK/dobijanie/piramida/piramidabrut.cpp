#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 5e5 + 10;
int arr[L];

/* piramida.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	uint64_t res = 0;
	for (int i=1; i<=n; i++){
		cin >> arr[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=1; j<=(n - i); j++) {
			res += arr[j];
			arr[j] = max(arr[j], arr[j+1]);
		}
	}
	cout << res << '\n';

}
	
