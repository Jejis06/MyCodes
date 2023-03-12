#include <bits/stdc++.h>
using namespace std;

#define ft double 

ft *coords;
ft *speeds;
int n;


template<typename T>
bool ok(T &d){
	
	T l,r;
	T tl,tr;


	l = coords[0]- speeds[0] * d;
	r = coords[0] + speeds[0] * d;


	for(int i=1;i<n;i++){
		tl = coords[i] - speeds[i] * d;
		tr = coords[i] + speeds[i] * d;

		l = max(l,tl);
		r = min(r,tr);
		
		if(l > r) return 0;
	}
	return 1;

}

ft bs(ft limit){
	ft l{};
	ft r = limit;

	ft mid;
	ft temp;
	while(l < r - 1e-7){
		mid = (l+r)/2;

		//printf("%f\t%f\t%f\t%f\n",l,mid,r,r-l);

		if(ok(mid)){
			r = mid;
		}
		else
			l = mid;

	}

	return r;
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	ft far = 0;
	ft near = INT_MAX;
	ft min_v = INT_MAX;


	cin >> n;
	
	coords = new ft[n];
	speeds = new ft[n];

	for(int i=0;i<n;i++){
		cin >> coords[i];

		far = max(far,coords[i]);
		near = min(near,coords[i]);
	}
	for(int i=0;i<n;i++){
		cin >> speeds[i];
		min_v = min(min_v,speeds[i]);
	}

	printf("%f\n",bs(min_v * (far-near)));

	delete[] speeds;
	delete[] coords;

}
