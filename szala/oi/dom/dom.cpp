#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

ll fib[87];

void divider(ll m, int depth=0) {
	if (m == 1) {
		cout << ((depth == 0) ? 2 : depth) - 1 << '\n';
		exit(0);
	}
	for (int i = 86; i>=1; i--) {
		if (m % fib[i] == 0) {
			divider(m / fib[i], depth + i + 2);
		}
	}
}


/* dom.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	

	fib[0]= 1;
	fib[1] = 2;
	for (int i=2; i<87; i++)
		fib[i] = fib[i-1] + fib[i-2];

	ll m;
	cin >> m;
	divider(m);
	cout  << "NIE\n";


}
	
