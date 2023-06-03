#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1e6 + 10;
bool arr[L];
int n;


void calc(){
	int flipped = 0;
	for (int i=n-1; i>1; i--)
		if (arr[i] - arr[i+1] == -1)
			flipped += 2;
	if (arr[1] == 1) flipped++;
	cout << flipped << '\n';
}


/* zar.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m,flip;
	char in;


	cin >> n >> m;

	for (int i=1; i<=n; i++){
		cin >> in;
		if (in == '1') arr[i] = 1;
	}
	
	calc();
	for (int i=1; i<=m; i++) {
		cin >> flip;
		arr[flip] = arr[flip] ^ 1;
		calc();

	}


	
}
 
