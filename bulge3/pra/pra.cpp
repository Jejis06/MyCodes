#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


constexpr int N = 1e6 + 10;
bool begins[N], Ends[N];

pair<int, int> arr[N];
priority_queue<pair<int,int>> begQ, endQ;

/* pra.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, a = 0, b = 0;
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a >> b;

		arr[i] = {a, b};

		begQ.push({-a, i});
		endQ.push({-b, i});
	}

	int il = 0, pn = 0, kn = 0, res = 0, res2 = 0;

	bool good;
	while (endQ.size()) {
		good = true;
		if (il < k && !begQ.empty()) {
			if (!Ends[begQ.top().second]) {
				a = -begQ.top().first;
				if (b < a) b = a;
				il++;
			}
			begins[begQ.top().second] = 1;
			begQ.pop();
		}
		else {
			b = -endQ.top().first;
			if (il == k) good = false;
			if (begins[endQ.top().second]) il--;

			Ends[endQ.top().second] = 1;
			endQ.pop();
		}
		if (good) continue;
		res2 = b - a;
		if (res2 > res) {
			res = res2;
			pn = a;
			kn = b;
		}

	}
	il = 0;
	cout << res << '\n';
	for (int i=1; i<=n; i++) {
		if (il == k) break;
		if (arr[i].first <= pn && kn <= arr[i].second) {
			cout << i << ' ';
			il++;
		}
	}

}
	
