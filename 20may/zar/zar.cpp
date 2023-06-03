#include <bits/stdc++.h>
using namespace std;

constexpr int L = 1e6 + 10;
bitset<L> arr;
int N;

void minMoves() {
	if (arr == 0) {
		cout << 0 << '\n';
		return;
	}
	int flipCoutner = 0;
	bool flip = false;

	for (int i=N; i>=1; i--)
		if (arr[i] ^ flip) {
			flipCoutner++;
			flip = flip ^ 1;
		}

	cout << flipCoutner << '\n';
}

/* zar.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m,flip;
	char in;

	cin >> N >> m;

	for (int i=0; i<N; i++){
		cin >> in;
		if (in == '1') arr[i+1] = 1;	
	}
	

	minMoves();
	for (int i=1; i<=m; i++) {
		cin >> flip;
		arr[flip].flip();
		minMoves();
	}


	
}
