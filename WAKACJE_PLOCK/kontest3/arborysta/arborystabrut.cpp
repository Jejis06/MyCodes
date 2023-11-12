#include <bits/stdc++.h>
using namespace std;

constexpr int L = 5e5 + 10;
int trees[L];
int points[L];

int main(){
	int n,m;
	cin >> n >> m;

	for (int i=1; i<=n; i++){
		cin >> trees[i];
	}
	int nr, dh;

	int maxVal= -1;
	int maxInd = 0;
	vector<int> ind;

	for (int j=1; j<=m; j++){
		ind = {};
		cin >> nr >> dh;
		trees[nr] += dh;
		maxVal = -1;

		for (int i=1; i<=n; i++){
			maxVal = max(maxVal, trees[i]);
		}
		for (int i=1; i<=n; i++){
			if (trees[i] == maxVal){
				ind.push_back(i);
			}
		}
		for (int x : ind)
			points[x] += j;

		maxVal = -1;
		for (int i=1; i<=n; i++){
			if (points[i] > maxVal){
				maxVal = points[i];
				maxInd = i;
			}
		}

	}
	cout << maxInd << '\n';
}
