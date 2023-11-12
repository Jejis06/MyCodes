#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 4e6 + 10;
int arr[L];

/* karty2.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;

	int p=1,d=2,o=n;
	for (int i=1; i<=n; i++) {
		arr[i] = i;
	}
	char c;
	while (k--) {
		cin >> c;
		if (c == 'A') {
			arr[++o] = arr[p];
			p = d;
			d++;
		}
		else arr[++o] = arr[d++];
	}
	cout << arr[p] << '\n';

}
	
