#include <bits/stdc++.h>
using namespace std;

int wA[1000001];
int wB[1000001];


/* cwo.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m,n;
	cin >> m >> n;

	int sumA=0, sumB=0;

	for (int i=0; i<n; i++) {
		cin >> wA[i];
		sumA += wA[i];
	}

	for (int i=0; i<n; i++) {
		cin >> wB[i];
		sumB += wB[i];
	}

	if (sumA == sumB) {
		cout << "TAK\n";
		return 0;
	}

	for (int a=0; a<n; a++) {
		for (int b=0; b<n; b++) {
			// pozamienianie/ sprawdzanie mozliwosci
			sumA -= wA[a];
			sumB -= wB[b];

			sumA += wB[b];
			sumB += wA[a];

			if (sumA == sumB) {
				cout << "TAK";
				return 0;
			}

			sumA += wA[a];
			sumB += wB[b];

			sumA -= wB[b];
			sumB -= wA[a];
		}
	}
	cout << "NIE";
	return 0;
}
	
