#include<iostream>
using namespace std;

constexpr int L = 500'000 + 10;
constexpr int inf = 1e9 + 10;

int arr[L];


int bs(int l, int r, const int &val){
	int end = r;
	while (l < r) {
		int mid = (l+r+1)/2;

		if(arr[mid] == val) return mid-1;
		if(arr[mid] < val)
			l = mid;
		else if (arr[mid] > val)
			r = mid - 1;

	}
	if(l == r) l--;
	return l;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,a;
	cin >> n >> m;

	for (int i=1; i<=n; i++) {
		cin >> arr[i];
		arr[i] = max(arr[i], arr[i-1]);

	}

	int lastN=n;
	int newN=n;
	for (int i=0; i<m; i++) {
		cin >> a;

		newN= bs(1,newN,a);
		cout << newN << ' ' <<lastN << '\t'; 	
		

	}
}
