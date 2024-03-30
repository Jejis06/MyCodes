#include <bits/stdc++.h>
#include "cliclib.h"
#define pb push_back
typedef long long ll;
using namespace std;


/* struct pairKey {
	template <typename T1, typename T2>
	size_t operator()(const pair<T1, T2>& p) const {
		auto h1 = hash<T1>{}(p.first);
		auto h2 = hash<T2>{}(p.second);

		if (h1 != h2)
			return h1 ^ h2;
		return h1;
	}
}; */

int n;
// unordered_map<pair<int,int>, bool, pairKey> states;
map<pair<int,int>, bool> states;

int check(int b, int s) {
	if (b + s >= n) return 0;
	return states[{b, s}];

}
void dfs(int b, int s) {
	if (b + s >= n || states.find({b, s}) != states.end()) return;

	dfs(2*b, s);
	dfs(3*b, s);
	dfs(1, b+s);


	if (check(2*b, s) + check(3*b, s) + check(1, s+b) == 0) states[{b, s}] = 0;
	else states[{b, s}] = 1;

}

// 3v-1, 3v, 3v+1
/* lic.cpp */
int main() {
	n = inicjuj();
	dfs(1, 0);

	int b=1, s=0;
	int ruchB;

	while (1) {
		if (b + s >= n) break;
		if (!states[{1, b+s}]) {
			alojzy(1);
			s += b;
			b = 1;
		}
		else if (!states[{2*b, s}]) {
			alojzy(2);
			b *= 2;
		}
		else if (!states[{3*b, s}]) {
			alojzy(3);
			b *= 3;
		}
		else return 0;

		int ruchB = bajtazar();

		if (ruchB == 1) {
			s += b;
			b = 1;
		}
		else if (ruchB == 2) {
			b *= 2;
		}
		else if (ruchB == 3) {
			b *= 3;
		}
	}
}
