#include "kon.cpp"

int arr[100000];
int main() {
	int n,k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	inicjuj(n,k,arr);

	int q;
	int a,b;
	while (1) {
		cin >> q >> a >> b;
		if (q < 0) break;
		if (q == 1) {
			cout << "dojrzale\n";
			cout << dojrzale(a, b) << '\n';
		}
		else if (q == 0) {
			cout << "PODLEJ\n";
			podlej(a,b);

		}

	}

}
