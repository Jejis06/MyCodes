#include <bits/stdc++.h>
#define pb push_back
using namespace std;
constexpr int L = 1e6 + 10;

int dpL[L];
int dpR[L];

constexpr int l = 1e6 + 10;

int mias[L];

/* miasta.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,d ;
	cin >> n; 
	for (int i=1; i<n; i++){
		cin >> d;
		mias[i] = d;
	}
	// right
	for (int i=n-1; i>0; i--) {
		if (mias[i] == 2 || mias[i] == 0)
			dpR[i] += dpR[i+1] + 1;
	}
	// left
	for (int i=1; i<=n; i++){
		if (mias[i-1] == 2 || mias[i-1] == 1)
			dpL[i] += dpL[i-1] + 1;
	}

	for (int i=1; i<=n; i++)
		cout << dpR[i] + dpL[i] << ' ';
	cout << '\n';
}
