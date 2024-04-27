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
		int b = 1;
		cin >> l;
		for (int i=1;; i++) {
			bitset<32> bits(i);
			int cnt = bits.count();

			if (cnt % 2 == 0) {
				b++;
				if (b == l) {
					cout << i << '\n';
					break;
				}

			}
		}

	}


}
	
