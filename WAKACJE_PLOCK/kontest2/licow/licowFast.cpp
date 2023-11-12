#include <bits/stdc++.h>
#define pb push_back
using namespace std;


void bin(int i){
	if (i == 0){
		cout << 0 << '\n';
		return;
	}

	string out = "";
	while (i > 0){
		if (i%2==1) out += '1';
		else out += '0';

		i/= 2;
	}
	for (int i=out.size()-1; i>=0; i--){
		cout << out[i];
	}
	cout << '\n';
}


/* licow.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i=0; i<=n; i++){
		bin(i);
	}


}
	
