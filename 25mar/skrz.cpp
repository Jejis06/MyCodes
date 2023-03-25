#include <bits/stdc++.h>
using namespace std;

map<int,int> mapa;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n,m,p,t,a,b,res=0;
	int x,y;
	cin >> n >> m >> p >> t;

	while(p--){
		cin >> a >> b;
		x = a;
		y = -b + 1;

		mapa[x+y]++;
	}	

	while(t--){
		cin >> a >> b;
		x = -b + 1;
		y = a;
		if(!mapa[x+y]) res++;
	}	

	cout << res << '\n';
}
