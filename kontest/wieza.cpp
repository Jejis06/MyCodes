#include <bits/stdc++.h>
using namespace std;

const int S = 5e5 + 10;
int schody[S];


int bins(int s, int e, int h){
	int mid;
	while(s < e){
		mid = (s+e+1)/2;
		if(schody[mid] < h){
			s = mid;
		}
		else
			e = mid-1;
	}
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,m;
	int a;
	int maks=0;
	cin >> n >> m;

	for(int i=1; i<=n; i++){
		cin >> a;
		maks = max(maks,a);
		schody[i] = maks;
	}

	for(int i=0; i<m; i++){
		cin >> a;
		if(a <= schody[1]) {
			cout << 0 << ' ';
			continue;
		}
		if(a > schody[n]){
			cout << n << ' ';
			continue;
		}
		cout <<  bins(1,n,a) << " ";
	}


}
