#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> Para;

constexpr int L = 1e3 + 10;
Para arr[L];
string save[L];

/* reg.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string input;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> input;
		arr[i] = {input.size(),i};
		save[i] = input;
	}

	sort(arr, arr + n);

	for (int i=0; i<n; i++) 
		cout << save[arr[i].second] << '\n';


}
	
