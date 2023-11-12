#include <bits/stdc++.h>
#define pb push_back
using namespace std;


constexpr int L = 1e6 + 10;
int y[L];
int x[L];

/* panorama.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m, maxX=-1, maxY=-1;
	cin >> n >> m;

	long long res = 0;

	for (int i=0; i<n; i++) {
		cin >> y[i];
		maxY = max(maxY, y[i]);
	}
	for (int i=0; i<m; i++) {
		cin >> x[i];
		maxX = max(maxX, x[i]);
	}

	if (maxY != maxX) {
		cout << "NIE\n";
		return 0;
	}

	for (int i=0; i<m; i++) {
		for (int j=n-1; j>=0; j--) {
			if (x[i] <= y[j])
				res += x[i];
			else res += y[j];
		}
	}
	cout << res << '\n';

}
	
