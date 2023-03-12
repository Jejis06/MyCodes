#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

unsigned long long arr[N];

int n,c;


void init_d(int n){
	n--;

	unsigned long long last  = arr[n];
	unsigned long long sum=last;

	for(int i=n-1;i>=0;i--){
		last  = min(last,arr[i]);
		sum += last;
	}

	cout << sum << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);


	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	init_d(n);


}

