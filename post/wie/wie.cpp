#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 210;
int Miecze[N];
int Potwory[N][N];
int Czas[N][N];

vector<int> Graph[N];

struct defInt{
	int val = INT_MAX;
};
defInt TimeToPass[N][1 << 13];


/* wie.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, p, k;
	/* liczba miejscowosci, 
	 * liczba drog, 
	 * liczba gatunkow, 
	 * liczba kowali */
	cin >> n >> m >> p >> k;

	int w, q, r, t, u;
	for (int i=0; i<k; i++) {
		/* numer miejscowosci, 
		 * liczba rodzaji mieczy */
		cin >> w >> q;
		while (q--) {
			// dany typ miecza
			cin >> r;
			Miecze[w] |= (1 << (r-1));
		}

	}

	for (int i=0; i<m; i++) {
		/* polaczenie miedzy miastami (w, q), 
		 * czas przejscia, 
		 * ilosc roznych potworow na drodze */
		cin >> w >> q >> t >> r;

		Czas[w][q] = t;
		Czas[q][w] = t;

		Graph[w].pb(q);
		Graph[q].pb(w);

		while (r--) {
			// dany typ potwora
			cin >> u;
			Potwory[w][q] |= (1 << (u-1));
			Potwory[q][w] |= (1 << (u-1));
		}
	}
	int res = INT_MAX;
	priority_queue<pair<int,int>> pq;
	TimeToPass[1][Miecze[1]].val = 0;

	if (n == 1) {
		res = 0;
		goto skip;
	}

	pq.push({0, 1 + 500 * Miecze[1]});

	while (pq.size()) {
		pair<int, int> sm = pq.top();
		int v = sm.second % 500,
		    ekw = sm.second/ 500;
		pq.pop();
		for (int w : Graph[v]) {
			// czy zior potworow zawiera sie w zbiorze posiadanych mieczy
			if ((Potwory[v][w] | ekw) == ekw) {
				if (Czas[v][w] - sm.first < TimeToPass[w][ekw | Miecze[w]].val) {
					TimeToPass[w][ekw | Miecze[w]].val = Czas[v][w] - sm.first;
					pq.push({-TimeToPass[w][ekw | Miecze[w]].val, w + 500 * (ekw | Miecze[w])});
					if (w == n) {
						res = min(res,TimeToPass[w][ekw | Miecze[w]].val);
					}
				}
			}
		}
	}

	skip:;
	if (res == INT_MAX) cout << -1;
	else cout << res;

}
	
