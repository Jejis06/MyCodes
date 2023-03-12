#include <bits/stdc++.h>
using namespace std;

constexpr int base = 1 << 17;
int tree[2*base];

void update(int v, int x){
	v += base;
	tree[v] = x;
	
	v /= 2;
	while(v){
		tree[v] = max(tree[2*v], tree[2*v + 1]);
		v /= 2;
	}
}

int get(int a, int b){
	int res=0;	

	a += base - 1;
	b += base + 1;

	while(a/2 != b/2){
		if(!(a & 1)) res = max(res, tree[a+1]);
		if(b & 1) res = max(res, tree[b-1]);

		a /= 2;
		b /= 2;
	}

	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q,a,b;
	bool t;
	cin >> q;

	while(q--){
		cin >> t >> a >> b;
		if(!t) update(a,b);
		else cout << get(a,b) << '\n';
	}
	
}
