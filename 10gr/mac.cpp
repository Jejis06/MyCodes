#include <bits/stdc++.h>
using namespace std;

const int N= 2 * 1e5 + 10;
long long arr[N][3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n;
	long long w=0;

	cin >> n;

	for(int i=1;i<=n;i++){

		for(int j=0;j<3;j++){
			cin >> arr[i][j];
		}

		arr[i][0] += max(arr[i-1][1],arr[i-1][2]);
		arr[i][1] += max(arr[i-1][0],arr[i-1][2]);
		arr[i][2] += max(arr[i-1][1],arr[i-1][0]);
	}


	w = max(arr[n][0],max(arr[n][1],arr[n][2]));
	cout << w << '\n';



}


