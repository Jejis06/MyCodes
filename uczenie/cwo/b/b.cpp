#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


/* b.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	int s = 1000000000 + 1;
	cin >> n;

	bool* guess = new bool[s];

	for (int i=0; i<n; i++) {
		cin >> p;
		if (p > n || guess[p] == true) {
			cout << "NIE";
			delete[] guess;
			return 0;
		}
		guess[p] = true;
	}
	cout << "TAK";
	delete[] guess;
}
	
