#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 1e6 + 10;
int arr[L];

/* kra.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k,num=0,sum=0, den;
	cin >> n >> k;
	
	for (int i=0; i<n; i++){
		cin >> arr[num];

		if (arr[num] > 0){
			sum += arr[num];
			num++;
		}

	}
	sort(arr, arr + num);

	int ind = 0;
	den = num;

	if (den == 0) {
		cout << "NIE\n";
		return 0;
	}

	while (ind < n && den > 0 && int(sum / den) < k){
		sum -= arr[ind];
		den--;
		ind++;
	}
	if (den == 0) {
		cout << "NIE\n";
		return 0;
	}
	if(int(sum/den) >= k) cout << ind << '\n';
	else cout << "NIE\n";
	


}
	
