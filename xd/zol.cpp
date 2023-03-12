#include <iostream>
using namespace std;

const int eps =(int) 1e9;
const int LIM=5* 100000+10;
int sol[LIM];

int n;

bool ok(int x){
	int rows=1;
	int lr=1;
	for(int i=0;i<n;i++){
		if(sol[i] + lr -1 <= x){
			lr += sol[i];
		}	
		else{
			rows++;
			lr=sol[i]+1;
		}
	}
	return rows <= x;

}

int bs(int mx){
	int l=mx, r=eps, mid;
	while(l < r){
		mid = (l+r)/2;
		//cout << mid << ' ' << l << ' ' << r << '\n';
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int mx = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> sol[i];
		mx = max(sol[i],mx);

	}

	cout << bs(mx) << '\n';
}
