#include <bits/stdc++.h>
using namespace std;

const int N = 5050;

int dp[N][N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	string s1,s2,o="";
	int n,m,x,y;

	cin >> s1 >> s2;
	n = s1.size();
	m = s2.size();

	s1 = ';' + s1;
	s2 = ':' + s2;

	for(int i=1;i <=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(s1[i]  == s2[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
		}
	}
	x = n;
	y = m;

	while(x > 0 && y > 0){
		if(dp[x][y] == dp[x-1][y]) x--;
		else if(dp[x][y] == dp[x][y-1]) y--;
		else{
			o += s1[x];
			x--;y--;
		}
	}
	
	reverse(o.begin(),o.end());
	cout << dp[n][m] << '\n' << o;
}
