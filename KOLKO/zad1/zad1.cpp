#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1e9;
int pos[L];

/* zad1.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,s,k;
	cin >> n >> s;

	pos[0] = 1;

	for (int i=0; i<n; i++) {
		cin >> k;
		for (int i=0; i<=s; i++)
			if(i + k <= s) 
				pos[i+k]++;
	}

	cout << pos[s] << '\n';

}
	
