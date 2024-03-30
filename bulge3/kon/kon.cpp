#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


/* kon.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string w;
	bool d=0;

	cin >> n >> w;
	for (int i=0; i<n-1; i++) {
		if (!d && w[i] > w[i+1]) d = 1;
		else cout << w[i];
	}
	if (d) cout << w[n-1];
}
	
