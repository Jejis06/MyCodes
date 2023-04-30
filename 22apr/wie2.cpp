#include<iostream>
using namespace std;

constexpr int L = 500'000 + 10;
int arr[L];

int bs(int lo, int hi, const int &val) {
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (arr[mid] >= val) hi = mid - 1;
		else lo = mid + 1;
	}
	if (arr[lo] >= val) lo--;
	return lo;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	/* liczba schodkow,  liczba mieszkancow */
	int n,m;
	cin >> n >> m;


	/* ustawiamy tablice na coraz bardziej rosnace wartosci */
	for (int i=1; i<=n; i++) {
		cin >> arr[i];
		arr[i] = max(arr[i],arr[i-1]);
	}

	/* zapytania, koniec przedzialu szukania */
	int b, e=n+1;

	for (int j=1; j<=m; j++) {
		cin >> b;
		if (e) e = bs(0,e-1,b);
		printf("%i ",e);
	}


}
