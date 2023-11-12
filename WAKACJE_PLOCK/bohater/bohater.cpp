#include <bits/stdc++.h>
#define pb push_back
using namespace std;

constexpr int L = 1e5 + 10;

struct mob{
	int id, dmg, hp;
	bool operator<(const mob& x) const {
		return dmg < x.dmg;
	}
	bool operator>(const mob& x) const {
		return hp >  x.hp;
	}
};


vector<mob> dod;
vector<mob> uj;

/* bohater.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	long long z;
	cin >> n >> z;

	int d,a;
	for (int i=0; i<n; i++){
		cin >> d >> a;

		if (a - d >= 0) dod.pb({i+1, d, a});
		else uj.pb({i+1, d, a});
	}

	vector<int> res;
	sort(dod.begin(), dod.end());
	for (auto [id, dmg, hp] : dod){
		z -= dmg;
		if (z <= 0){
			cout << "NIE\n";
			return 0;
		}
		res.pb(id);
		z += hp;
	}

	sort(uj.begin(), uj.end(), greater<mob>());
	for (auto [id, dmg, hp] : uj){
		z -= dmg;
		if (z <= 0){
			cout << "NIE\n";
			return 0;
		}
		res.pb(id);
		z += hp;
	}
	cout << "TAK\n";
	for (int id : res) cout << id << ' ';
}
	
