#include <bits/stdc++.h>
using namespace std;

const int S = 50'000 + 10;
int a[S];
int suma=0;


bool rek(int n,int sum=0,int i=0){
	sum = (sum%360);
	if(i == n){
		if(sum == 0 || sum%360 == 0) {
			cout << "TAK\n";
			exit(0);
			return 1;

		}
		return 0;
	}
	bool l1 = rek(n, sum + a[i], i+1);
	bool l2 = rek(n, sum - a[i], i+1);
	return (l1 || l2);
}
bool pre(int n, int sum=0,int i=0){
	return rek(n,sum + a[i],i+1);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n,maks=-1;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> a[i];
		maks = max(a[i],maks);
		suma += a[i];
	}
	if(suma%360 == 0){
		cout << "TAK\n";
		return 0;
	}
	
	if(suma % 2 != 0 || maks > suma/2 || n == 1){
		cout << "NIE\n";
		return 0;
	}	


	if(rek(n)){
		cout << "TAK\n";
	}
	else cout << "NIE\n";


}
