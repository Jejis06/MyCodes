#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int L = 5e5 + 10;
/* num, how many times it accurs */
vector<pair<int,int>> sections;



/* piramida.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, num;
	cin >> n;

	ll res = 0;
	sections.reserve(L);

	for (int i=0; i<n; i++) {
		cin >> num;

		int occ = 1;
		while (sections.size() > 0) {
			if (sections.back().first > num) break;

			occ += sections.back().second;
			sections.pop_back();
		}
		sections.push_back( make_pair(num, occ) );
		for (auto& [n,o] : sections) res += (ll)n * (ll)o;

	}
	cout << res << '\n';
}
