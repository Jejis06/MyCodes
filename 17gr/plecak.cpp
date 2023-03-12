#include <bits/stdc++.h>
using namespace std;

const int N = 120;
const int B = 1e4 + 20; 

int dp[N][B];

int wg[N];
int val[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n,b;

	cin >> n >> b;

	for(int i=1;i<=n;i++){
		cin >> wg[i];
	}
	for(int i=1;i<=n;i++){
		cin >> val[i];
	}

	for(int i=1 ; i <= n ; i++){
		for(int mass=1 ; mass <= b ; mass++){
			if(wg[i] > mass)
				dp[i][mass] = dp[i-1][mass]; //nie bierzemy
			else
				dp[i][mass] = max(dp[i-1][mass], val[i] + dp[i-1][mass - wg[i]]);
		}
	}	
	cout << dp[n][b] << '\n';
}
