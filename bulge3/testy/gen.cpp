#include <bits/stdc++.h>
#include <random>
using namespace std;

mt19937 ran;
// zwraca losową liczbę z przedziału [a, b] (czyli włącznie z a i b)
int randRange(int a, int b) {
	return a + ran() % (b - a + 1);
}

int main() {
	int s;
	cin >> s;
	ran.seed(s);

	int n = randRange(2, 1000);
	int q = randRange(4, 100);

	cout << n << '\n';
	for (int i=0; i<n; i++) 
		cout << randRange(0, 1000) << ' ';
	cout << q << '\n';
	for (int i=0; i<q; i++) {
		int firstChoice = randRange(1, n);
		int secondChoice = randRange(firstChoice, n);
		cout << firstChoice << ' ' << secondChoice << '\n';
	}

}
