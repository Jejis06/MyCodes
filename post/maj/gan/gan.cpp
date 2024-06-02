#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef pair<int, int> Para;
typedef long long ll;

constexpr int N = 1e5 + 10;
constexpr int M = 1e5 + 5e4 + 10;
constexpr int POW = 17;

struct Node{
	int dest;
	int label;
};

int biciak[N];
vector<Node> tree[N];

int jmp[N][POW],
    depth[N];




/* gan.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, z, a, b, c;
	cin >> n >> m >> z;

	for (int i=1; i<n; i++) {
		cin >> a >> b >> c;

		biciak[i] = c;

		tree[a].pb({b, i});
		tree[b].pb({a, i});

	}

	char mode;
	for (int i=0; i<z; i++) {
		cin >> mode >> a;

		if (mode == 'Z') {
			// zapytanie ile biciakow miedzy 1 - a

			continue;
		} 
		// aktualizacja biciaka na a-tej drodze na b
		cin >> b;
		biciak[a] = b;
	}

}
	
