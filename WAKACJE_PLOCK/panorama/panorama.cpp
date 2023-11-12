#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

constexpr int L = 1e6 + 10;
int y[L];
int x[L];
ll pref[L];




int bs(int l, int r, int& val) {
	while (l != r) {
		int mid = (l + r + 1)/2;

		if (x[mid] >= val) l = mid;
		else r = mid-1;
	} 
	return l;
}

/* panorama.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	int n, m;
	int maxX=-1, maxY=-1;
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

	sort(x, x+m, greater<int>());
	sort(y, y+n);

	pref[0] = x[0];
	for (int i=1; i<m; i++) 
		pref[i] = pref[i-1] + x[i];

	int upperBound = m-1;
	for (int i=0; i<n; i++){
		upperBound = bs(0, upperBound, y[i]);
		res += (ll)y[i] * (upperBound + 1);

		if (upperBound < m-1)
			res += pref[m-1] - pref[upperBound];

	}
	cout << res << '\n';


}
	

