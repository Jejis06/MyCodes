#include <bits/stdc++.h>
#define pb push_back
using namespace std;


constexpr int L = 1000 + 1000 + 10;
pair<int, bool> split[L];

/* czeko.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n, x, y;
	cin >> m >> n;
	for (int i=0; i<m-1; i++){
		cin >> x;
		split[i] = {x, 0};
	}
	for (int i=m-1; i<m+n-2; i++){
		cin >> y;
		split[i] = {y, 1};
	}
	sort(split, split + n + m - 1, greater<pair<int,bool>>());

	int dir[2] = {0,0}; /* vertical / horizontal */
	int res=0;

	for (int i=0; i<n+m-2; i++){
		auto& [price, mode] = split[i];
		res += price * (dir[!mode] + 1); 
		dir[mode]++;
	}
	cout << res << '\n';
}
