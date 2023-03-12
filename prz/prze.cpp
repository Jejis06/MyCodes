#include <bits/stdc++.h>
using namespace std;

const int S = 5e4 + 7;
pair<int,int> arr[S];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n;
	cin >> n;

	for(int i=0;i<n;i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr,arr+n);

	int s = arr[0].first;	
	int e = arr[0].second;

	cout << s << ' ';
	for(int i=1;i<n;i++){
		if(e >= arr[i].first)
			e = max(e,arr[i].second);
		else{
			cout << e << '\n';

			s = arr[i].first;
			e = arr[i].second;

			cout << s << ' ';

		}

	}
	cout << e << '\n';

}
