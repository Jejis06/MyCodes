#include <iostream>

using namespace std;

const int L = 300'000 + 10;
int krazki[L];
int n,m,t;


int bs(int lo, int hi, int x){
	while (lo < hi) {
		int mid = (lo + hi)/2 + 1;
		if(krazki[mid] < x) hi = mid - 1;
		else lo = mid;
	}
	return lo;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	/* segmenty ,krazki */
	cin >> n >> m;

	/* jak jest male wejscie a potem duze to mozemy zignorowac duze */
	cin >> krazki[1];
	for (int i=2; i<=n; i++) {
		cin >> krazki[i];
		krazki[i] = min(krazki[i],krazki[i-1]);
	}

	int bound  = n;
	for (int j=0; j<m; j++) {
		cin >> t;
		bound = bs(0,bound - 1,t);
		if (bound == 0) break;
	}
	cout << bound << '\n';

}
