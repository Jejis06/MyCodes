#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


/* krol.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int last = 0;
	cout << 0 << '\n';
	for (int i=0; i<100; i++) {
		bitset<32> bits(i);
		int cnt = bits.count();
		string x = bits.to_string();
		x.erase(0, x.find_first_not_of('0'));

		if (cnt % 2 == 0) {
			cout << x  << '\t' << i << '\n';
			last++;
		}

	}
	cout << last << '\n';

}
	

