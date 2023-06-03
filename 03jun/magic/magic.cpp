#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1e6;
vector<int> diff;
map<vector<int>,int> M;
bool occ[L];

/* magic.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int n;
	long long res = 0;
	char spec;
	int si;

	cin >> n >> s;
	M[diff]++;

	spec = s[0];
	if('a' <= spec) si = spec - 'a';
	else si = spec - 'A' + 26;
	for (auto& x : s) { 
		if ('a' <= x) occ[x - 'a'] = 1;
		else occ[x - 'A' + 26]= 1;
	}
	for (auto& x : s) {
		if (x==spec) {
			for (int i=0; i<53; i++) {
				if(!occ[i] || i == si) continue;
				diff[i]++;

			}


		} else {
			if ('a' <= x) diff[x - 'a']++;
			else diff[x - 'A' + 26]++;
		}

		res += M[diff];
		M[diff]++;
	}
	cout << res << '\n';

}
	
