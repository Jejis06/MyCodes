#include <iostream>
#include <climits>

using namespace std;
typedef long long ll;


constexpr int L = 1e5 + 10;

struct miasto{
	int zap, dys;
} arr[L]; 


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int zap,dys;
	ll absDys=0;

	for (int i=0; i<n; i++) {
		cin >> zap >> dys;
		arr[i] = {zap,dys};

		absDys += dys;
	}

	ll bestSum = LLONG_MAX, currSum;
	ll l, r;

	for (int i=0; i<n; i++) {
		currSum = 0;
		l = absDys;
		r = 0;

		for (int j=i; j<n+i-1; j++) {
			r += arr[j%n].dys;
			l = absDys - r;

			currSum += arr[(j+1)%n].zap * min(l,r);
		}
		bestSum = min(currSum,bestSum);
	}

	cout << bestSum << '\n';

}

