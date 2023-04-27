#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

constexpr ll L = 2e5 + 5;
ll arr[L];

int bs(const ll &val, int start, int end){
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;

		if (arr[mid] == val) return mid;
		else if (arr[mid] < val)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return start;
}


int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	int n,q;
	ll p;

	cin >> n;

	for (int i=0; i<n; i++) 
		cin >> arr[i];

	sort(arr, arr + n, greater<ll>());

	for (int i=1; i<n; i++) 
		arr[i] += arr[i-1];

	cin >> q;

	while (q--) {
		cin >> p;
		cout << bs(p, 0, n) + 1 << '\n';
	}

}
