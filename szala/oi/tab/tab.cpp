#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int LIM = 1e3 + 1;
bool arr[LIM][LIM];

int add(int x, int y){
	if (x < 0 || y < 0) return 0;
	arr[y][x] ^= 1;
	return (arr[x][y]^1) ? -1 : 1;
}

/* tab.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,q;
	int x1,y1,x2,y2;

	int ways = 0;
	cin >> n >> m >> q;

	while (q--) {
		cin >> y1 >> x1 >> y2 >> x2;

		if (y1 > 1 && x1 > 1) {
			ways += ((arr[y1-1][x1-1] == 1) ? -1: 1);
			arr[y1-1][x1-1] ^= 1;
		}
		if (y1 > 1) {
			ways += ((arr[y1-1][x2] == 1) ? -1: 1);
			arr[y1-1][x2] ^= 1;

		}
		if (x1 > 1) {
			ways += ((arr[y2][x1-1] == 1) ? -1: 1);
			arr[y2][x1-1] ^= 1;
		}
		ways += ((arr[y2][x2] == 1) ? -1: 1);
		arr[y2][x2] ^= 1;

		cout << ways << '\n';

	}


}
	
