#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int L = 5e5 + 10;

struct Seg{
	int s,e;
	int ind;

	bool operator<(const Seg& A) const {
		return e < A.e;
	}
} segs[L];

vector<int> glow;
unordered_map<int,int> zap;
vector<int> zapV;
vector<int> super;
unordered_map<int,int> placeIn;

bool comp(const Seg& a, const Seg& b){
	return a.s > b.s;
}

/* ZAP.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;

	for (int i=0; i<n; ++i){
		cin >> a >> b;
		segs[i] = {a, b, i};
	}
	sort(segs, segs+n, comp);
	sort(segs, segs+n);

	int koniec = -1;
	int poprzedniKoniec= -1;
	int koniecZastepcy = -1;
	// absolutne rozwiazanie
	int t2 = -1;


	for (int i=0; i<n; ++i) {

		if (segs[i].s >= t2) {
			super.pb(segs[i].ind);
			t2 = segs[i].e;
		}
		if (glow.size() == zapV.size()) {
			if (segs[i].s >= max(koniec, koniecZastepcy)) {
				poprzedniKoniec = koniec;
				koniec = segs[i].e;

				glow.pb(segs[i].ind);
				placeIn[segs[i].ind] = i;
			}
			else if (segs[i].s >= koniec){
				zapV.pb(segs[i].ind);
				placeIn[segs[i].ind] = i;
			}
		}
		else if (glow.size() < zapV.size() && segs[i].s >= max(koniec, koniecZastepcy)) {
			poprzedniKoniec = koniec;
			koniec = segs[i].e;

			glow.pb(segs[i].ind);
			zap[segs[i].ind] = zapV.back();
			placeIn[segs[i].ind] = i;
		}
		else if (glow.size() > zapV.size() ) {
			if (segs[i].s >= max(koniecZastepcy, koniec)) {
				poprzedniKoniec = koniec;
				koniec = segs[i].e;
				
				glow.pb(segs[i].ind);
				placeIn[segs[i].ind] = i;

			}
			else if(segs[i].s >= poprzedniKoniec && zap.find(glow.back()) == zap.end()) {
				koniecZastepcy = segs[i].e;

				zap[glow.back()] = segs[i].ind;
				zapV.pb(segs[i].ind);
				placeIn[segs[i].ind] = i;
			}

		}
	}

	if (glow.size() <= super.size() -1 || glow.size() > zap.size()){
		cout << super.size() - 1 << '\n';
		for (int i=0; i<super.size()-1; ++i){
			cout << super[i] + 1 << ' ' << super.back() + 1 << '\n';
		}
		return 0;
	}
	else {
		cout << glow.size() << '\n';
		for (int i=0; i<glow.size(); ++i){
			cout << glow[i] + 1 << ' ' << zap[glow[i]] + 1 << '\n';
		}
	}
}
