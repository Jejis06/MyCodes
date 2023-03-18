#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a,n,sum=0;
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> a;
		sum += a;
		arr.push_back(a);

	}
	sort(arr.begin(),arr.end());

	for(int i=0; i<arr.size(); i++) {
		sum += arr.back() - arr[i];
		arr.pop_back();

	}

	cout << sum << '\n';
	

}
