#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

long long arr[N][N];
int n,m;

void sum(int x, int y){
	if(x-1<=0 && y-1<=0) return;
	if(x-1<=0 && y-1 > 0){
		arr[y][x] += arr[y-1][x];
		return;
	}
	if(x-1>0 && y-1 <=0){
		arr[y][x] += arr[y][x-1];
		return;

	}
	arr[y][x] += max(arr[y-1][x],arr[y][x-1]);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin >> n >> m;

	for(int y=1;y<=n;y++){
		for(int x=1;x<=m;x++){
			cin >> arr[y][x];

		}
	}


	for(int y=1;y<=n;y++){
		for(int x=1;x<=m;x++){
			sum(x,y);
		}
	}
	cout << arr[n][m]<<'\n';

}
