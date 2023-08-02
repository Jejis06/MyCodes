#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

constexpr int L = 1e6 + 10;
vec arr[L];

int bs(int id, int num){
	int mid, s = 0;
	int e = arr[id].size() - 1;

	while (s < e) {
		mid = s + (e - s) / 2;
		if (arr[id][mid] <= num) s = mid + 1;
		else e = mid; 
	}

	if (arr[id][s] <= num && s+1 < arr[id].size()) s++;
	return arr[id][s];
}

string question(){
	bool o = true;
	int len, min, b;

	cin >> len;
	for (int j=0; j<len; j++) {
		cin >> b;
		if (!o) continue;
		if (!arr[b].size()) {
			o = false;
			continue;
		}
		if (j == 0) {
			min = arr[b][0];
			continue;
		}

		if (min >= arr[b].back()) {
			o = false;
			continue;
		}

		min = bs(b, min);

	}
	if (o) return "TAK\n";
	return "NIE\n";

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m,n,a,b;

	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> a;
		arr[a].push_back(i);
	}

	cin >> n;
	for (int i=0; i<n; i++) 
		cout << question();
}
