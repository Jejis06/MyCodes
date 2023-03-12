#include <bits/stdc++.h>
using namespace std;


long long fields[100000+10];
const long double check = 1e-7;


long long k;
int n;

bool ok(long double x){
	long long need=0;
	for(int i=0;i<n;i++){
		need +=ceil((long double)fields[i]/x);// (fields[i] + x - 1) / x;//zaokraglanie na intach w gore epic trick
		if(need > k) return 0;
	}		
	return 1;	
}

long double BS(){
	long double l{};
	long double r = 1e18;
	long double mid;
	while( r-l >= check ){

		mid = (r+l)/2;

		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid + check;

		}
	}
	return l;
} 


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);



	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> fields[i];
	}

	cout << fixed << setprecision(7) << BS() << '\n';
}
