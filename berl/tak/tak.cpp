#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

const int N = 5e5 + 10;
long long tax[N];
long long n, m, d;
typedef long long ll;

int res(){
	if (tax[0] < m - d) return 0;
	int j=0;
	while (j+1 < n && tax[j+1] >= m - d) j++;
	ll last = tax[j];
	while (j + 1 < n) {
		tax[j] = tax[j + 1];
		j++;
	}
	n--;

	ll pos = 0;
	for (int i=0; i<n; i++) {
		// can we use our last taxi
		if (2 * (d - pos) + (m - d) <= last)
			return i + 1;
		if (d - pos > tax[i]) 
			return 0;

		pos += (tax[i] -(d - pos));

		if (pos >= m) return i + 1;
		if (pos > d) pos = d;
	}
	if (2 * (d - pos) + (m - d) <= last)
		return n+1;
	return 0;
	
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> d >> n;

	for (int i=0; i<n; i++) 
		cin >> tax[i];
	sort(tax, tax+n, greater<long long>());
	cout << res();

}
