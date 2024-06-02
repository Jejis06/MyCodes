#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e6 + 10;
int obserwowany[N];
set<int> nieodwiedzone;


/* skr.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, u, odwiedzone_obserwowane, odwiedzone;
	cin >> n >> m;

	for (int i=2; i<=n; i++)
		nieodwiedzone.insert(i);

	for (int i=1; i<=m; i++) {
		cin >> k;

		odwiedzone_obserwowane = 0;
		for (int j=1; j<=k; j++) {
			cin >> u;
			obserwowany[u] = i;
			if (nieodwiedzone.find(u) == nieodwiedzone.end()) {
				odwiedzone_obserwowane++;
			}
		}
		odwiedzone = n - nieodwiedzone.size();

		// Czy istnieje taki skrzat, ktory zostal odwiedzony i nie jest obserwowany 
		if (odwiedzone > odwiedzone_obserwowane) {
			for (auto skrzat = nieodwiedzone.begin(); skrzat != nieodwiedzone.end(); ) {
				if (obserwowany[*skrzat] != i) {
					if (*skrzat == n) {
						cout << i-1 << '\n';
						return 0;
					}
					nieodwiedzone.erase(skrzat++);
				} else ++skrzat;
			}

		}

	}
	cout << m << '\n';
}
	
