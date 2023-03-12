#include <bits/stdc++.h>
using namespace std;

constexpr int base = 1 << 17;
constexpr long long X = 1e9 + 7;

long long tree[base * 2];


int get(int v){
	int ret=1;

	v += base;

	while(v){
		ret = (tree[v] * (long long)ret) % X;
		v /= 2;
	}

	return ret;
}

void update(int a, int b, int c){

	a += base - 1;
	b += base + 1;

	while(a/2 != b/2){
		if(!(a & 1)) tree[a+1] = (tree[a+1] * c) % X;
		if(b & 1) tree[b-1] = (tree[b-1] * c) % X;

		a /= 2;
		b /= 2;
	}
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for(int i=0; i<2*base; i++) tree[i] = 1;

	int q,a,b,c;
	bool t;
	
	cin >> q;
	while(q--){
		cin >> t >> a;
		if(!t){
			cin >> b >> c;
			update(a,b,c);
		}
		else cout << get(a) << '\n'; 

	}
}
