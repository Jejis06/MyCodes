#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 2e5 + 10;

struct Pos{
	int x,y;
};

vector<Pos> krzaki;
Pos owce[N];

bool cmp(const Pos& a, const Pos& b) {
	return a.y <= b.y;
}
void F0ans(const int n) {
	int ilosc;
	for (int owca = 0; owca < n; owca++) {
		ilosc = 0;
		for (int i=krzaki.size() - 1; i >= 0; i--) {
			if (krzaki[i].x < owce[owca].x) continue;
			if (krzaki[i].y < owce[owca].y) break;
			ilosc++;
		}
		cout << ilosc << '\n';

	}
}

/* osc.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int f, n, m;

	int w1, k1, w2, k2, x, y;
	cin >> f;
	for (int i=0; i<f; i++) {
		cin >> w1 >> k1 >> w2 >> k2;
	}
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> y >> x;
		krzaki.pb({x, y});
	}
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> y >> x;
		owce[i] = {x, y};
	}
	sort(krzaki.begin(), krzaki.end(), cmp);
	F0ans(n);
	
	
}
	
