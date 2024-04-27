#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


/* krol.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int l;
		cin >> l;
		bitset<32> b1(2 * l - 2);

		if (b1.count() % 2 == 0) cout << 2 * l - 2 << '\n';
		else cout << 2 * l - 1 << '\n';

	}


}
	
