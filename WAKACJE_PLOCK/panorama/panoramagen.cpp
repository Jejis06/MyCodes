#include <bits/stdc++.h>
using namespace std;
mt19937 gen;

int rRange(int a, int b){
	return gen() % ( b -a + 1) + a;
}

int main(){
	int seed, maxN;
	cin >> seed >> maxN;

	gen.seed(seed);

	int n = rRange(1, maxN);
	int m = rRange(1, maxN);

	cout << n << ' ' << m << '\n';
	for (int i=0; i<n; i++)
		cout << rRange(1,n) << ' ';
	cout << '\n';
	for (int i=0; i<m; i++)
		cout << rRange(1,m) << ' ';
}


