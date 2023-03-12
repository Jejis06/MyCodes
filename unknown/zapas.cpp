#include <bits/stdc++.h>

using namespace std;


unsigned long long n,w,h;

bool ok(unsigned long long m){
	return ((m/w) * (m/h) >= n);
}

unsigned long long bs(unsigned long long m){

	unsigned long long l=1,r=m,mid;

	while(r > l){
		mid = (l+r)/2;
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin  >> w >> h >> n;

	cout << bs(max(w,h)*n) << '\n';

}

