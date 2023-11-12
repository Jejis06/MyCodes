#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
constexpr int L = 5e5 + 10;
ll arr[L];
ll res[L];
ll daysSum[L];


/* arborysta.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, h, nr, dh;
	cin >> n >> m;

	ll maxHeight = -1;
	vector<pair<ll,ll>> maxHeightIndex;
	for (int i=1; i<=n; i++){
		cin >> arr[i];
		maxHeight = max(arr[i], maxHeight);
	}
	for (int i=1; i<=n; i++)
		if (arr[i] == maxHeight)
			maxHeightIndex.pb({i,0});

	ll maxRes = -1;
	ll maxResInd = 0;

	int delta = 0;
	for (int i=1; i<=m; i++){
		cin >> nr >> dh;

		arr[nr] += dh;
		daysSum[i] = daysSum[i-1] + i;

		if (dh != 0) {
			if (arr[nr] == maxHeight) {
				maxHeightIndex.pb({nr,i-1});
			}
			else if (arr[nr] > maxHeight) {
				
				for (auto [ind, day] : maxHeightIndex){
					res[ind] += daysSum[i-1] - daysSum[day];
					if (res[ind] > maxRes) {
						maxRes = res[ind];
						maxResInd = ind;
						
					}
					else if (res[ind] == maxRes){
						maxResInd = min(maxResInd, ind);
					}
				}

				maxHeight = arr[nr];
				maxHeightIndex = {{nr,i-1}};
			}
		}

		/* for (int j=1; j<=n; j++)
			cout << res[j] << ' ';
		cout <<'\n'; */
	}
	for (auto [ind, day] : maxHeightIndex){
		res[ind] += daysSum[m] - daysSum[day];
		if (res[ind] > maxRes) {
			maxRes = res[ind];
			maxResInd = ind;
			
		}
		else if (res[ind] == maxRes){
			maxResInd = min(maxResInd, ind);
		}
	}
	cout << maxResInd << '\n';

}
	
