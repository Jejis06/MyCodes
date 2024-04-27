#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 2000 + 10;
int cols[N];

/* dzi.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, in, res = 0;
	cin >> n;

	stack<pair<int, int>> Stos;
	int lastDown;

	for (int y=0; y<n; y++) {
		for (int x=0; x<n; x++) {
			cin >> in;
			if (in == 1) { 
				cols[x] = 0;
			} else cols[x]++;

			lastDown = x;
			while (Stos.size() && Stos.top().second > cols[x]) {
				res = max(Stos.top().second * (x - Stos.top().first), res);
				lastDown = Stos.top().first;
				Stos.pop();
			}
			if (cols[x] == 0) continue;
			Stos.push({lastDown, cols[x]});
		}
		while (Stos.size()) {
			res = max(Stos.top().second * (n - Stos.top().first), res);
			lastDown = Stos.top().first;
			Stos.pop();
		}
	}

	cout << res << '\n';
}
	
