#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


/* kaw.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a,b,c,d;
	int sum = 0;
	for (int i=0; i<n-1; i++) {
		cin >> a >> b >> c >> d;
		sum += a + b + c + d;
	}
	if (n == 0) cout << "0\n";
	cout << sum / (4 * n - 4) << '\n';

}
	
