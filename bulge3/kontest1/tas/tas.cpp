#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e5 + 10;
int arr[N];

/* tas.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> n;
		for (int i=1; i<=n; i++) 
			cin >> arr[i];
		int s = 1, e = n;
		int res = 0;

		while (arr[s] == arr[e] && s != e) 
			e--;
		res = e - s;

		s = 1; e = n;
		while (arr[s] == arr[e] && s != e) 
			s++;
		res = max(res, e - s);

		if (res <= 0) cout << "BRAK\n";
		else cout << res << '\n';

	}


}
	
