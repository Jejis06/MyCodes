#include <iostream>
#include <climits>

using namespace std;
typedef long long ll;

constexpr int L = 1e5 + 10;

struct miasto{
	int need, dis;
} arr[L]; 

int n;
int l = 2,
    r = 1;

int distanceUpToLeft = 0,
    distanceUpToRight = 0;

ll wholeNeedUpToLeft = 0,
    wholeNeedUpToRight = 0;

ll localCost = 0,
    optimalCost;


void optimalizeBounds(){
	while (distanceUpToRight + arr[r].dis < distanceUpToLeft) {
		localCost = localCost + arr[l].need * (distanceUpToRight - distanceUpToLeft + arr[r].dis);

		wholeNeedUpToLeft -= arr[l].need;
		wholeNeedUpToRight += arr[l].need;

		distanceUpToLeft -= arr[l].dis;
		distanceUpToRight += arr[r].dis;

		r = r % n + 1;
		l = l % n + 1;
	}
}


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int need,dis;

	for (int i=1; i<=n; i++) {
		cin >> need >> dis;
		arr[i] = {need,dis};
	}


	for (int i=n; i>=2; i--) {
		distanceUpToLeft += arr[i].dis;
		wholeNeedUpToLeft += arr[i].need;

		localCost += distanceUpToLeft * arr[i].need;
	}
	

	optimalizeBounds();
	optimalCost = localCost;

	for (int i=2; i<=n; i++) {
		int distance = arr[i-1].dis;
		localCost += (wholeNeedUpToLeft - wholeNeedUpToRight + arr[i-1].need) * distance; 

		wholeNeedUpToRight -= arr[i].need;
		wholeNeedUpToLeft += arr[i-1].need;

		distanceUpToLeft += distance;
		distanceUpToRight -= distance;

		optimalizeBounds();

		optimalCost = min(optimalCost, localCost);
	}

	cout << optimalCost << '\n';
}

