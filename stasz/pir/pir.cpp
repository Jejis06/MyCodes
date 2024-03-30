#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 2e5 + 10; 

int arr[N];

int median(int a, int b, int c) {
	return max(min(a, b), min(max(a, b), c));
}

/* pir.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=1; i<=2*n - 1; i++) cin >> arr[i];

	int level = n;
	while (level != 0) {
		for (int i=1; i <= 2*level-3; i++) {
			arr[i] = median(arr[i], arr[i+1], arr[i+2]);
		}
		level--;
	}
	cout << arr[1] << '\n';

}
	
