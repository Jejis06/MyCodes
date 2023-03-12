#include <iostream>
using namespace std;

const int S = 1e6 + 10;
int arr[S];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	int save = 0;
	int mx = 0;
	cin >> n >> m;

	for(int i=0;i<m;i++){
		int in;
		cin >> in;

		if(in == n+1) save = mx;
		else{
			if(arr[in] >= save) arr[in]++;
			else arr[in] = save + 1;
			mx = max(arr[in],mx);
		}
	}
	for(int i=1; i<=n; i++) {
		if(arr[i] < save) cout << save << ' ';
		else cout<< arr[i] << ' ';
	}
}
