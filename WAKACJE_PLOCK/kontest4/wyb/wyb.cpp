#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 1e6 + 10;
int amm[L];
int gl[L];

/* wyb.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> gl[i];
		amm[gl[i]]++;
	}

	int ind = 0;
	int curr;
	while (ind < m) {
		curr = gl[ind];
		while (amm[curr] > 0 && ind < m) {
			if (gl[ind] != curr) {
				amm[gl[ind]]--;
				gl[ind] = curr;
				cout << curr << ' ';
			}
			else {
				amm[curr]--;
				cout << curr << ' ';
			}
			ind++;
		}
	}

}
	
