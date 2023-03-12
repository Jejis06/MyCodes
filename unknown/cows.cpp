#include <bits/stdc++.h>
using namespace std;
int n,c;
int stalls[100000];


bool ok(int s){
	int start{};
	int end{};
	int w=1;

	while(end <= n){
		if(w == c) return 1;
		if(stalls[end] - stalls[start] >= s){
			w++;
			start=end;
		}
		end++;
	}
	
	return 0;
}



int bs(int d){

	int mid;
	int l=1;
	int r=d;

	while(r-l>0){
		mid = (l+r)/2;
		if(ok(mid)){

			l = mid+1;
		}
		else
			r = mid;
	}
	return l-1;
}



int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int t;
	int mind,maxd;

	cin >> t;

	for(int i=0;i<t;i++){

		mind=INT_MAX;
		maxd=0;

		cin >> n >> c;

		for(int j=0;j<n;j++){
			cin >> stalls[j];
			maxd = max(stalls[j],maxd);
			mind = min(stalls[j],mind);
		}
		
		sort(stalls,stalls+n);


		cout << bs(maxd-mind) << '\n';
		
		
		
	}
}
