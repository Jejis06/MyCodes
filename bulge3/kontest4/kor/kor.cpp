#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> para; 

constexpr int N = 2e5 + 10;
constexpr int Mod1 = 1e9 + 7;
constexpr int Mod2 = 1e9 + 9;
constexpr int P = 363359; // > 2e5;

int kor[N],
    Hash[N][2],
    HashRev[N][2],
    PowP[N][2];
    
para genHash(int l, int r, int n) {
	int h1 = (Hash[r][0] - Hash[l-1][0] + Mod1) % Mod1;
	int h2 = (Hash[r][1] - Hash[l-1][1] + Mod2) % Mod2;

	return {
		(ll(h1) * PowP[n-l+1][0]) % Mod1,
		(ll(h2) * PowP[n-l+1][1]) % Mod2
	};
}
para genHashRev(int l, int r) {
	int h1 = (HashRev[l][0] - HashRev[r+1][0] + Mod1) % Mod1;
	int h2 = (HashRev[l][1] - HashRev[r+1][1] + Mod2) % Mod2;

	return {
		(ll(h1) * PowP[r][0]) % Mod1,
		(ll(h2) * PowP[r][1]) % Mod2
	};
}

int DiffSlicesFor(int k, int n) {
	set<para> hashes;
	for (int i=1; i <=n-k+1; i+=k) {
		para h = genHash(i, i+k-1, n);
		para hr = genHashRev(i, i+k-1);

		if (hashes.count(h) == 0 && hashes.count(hr) == 0) {
			hashes.insert(h);

		}
	}
	return hashes.size();
}

/* kor.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) 
		cin >> kor[i];

	PowP[0][0] = PowP[0][1] = 1;
	for (int i=1; i<=n; i++) {
		PowP[i][0] = (ll(PowP[i-1][0]) * ll(P)) % Mod1;
		PowP[i][1] = (ll(PowP[i-1][1]) * ll(P)) % Mod2;
	}

	for (int i=1; i<=n; i++) {
		Hash[i][0] = (ll(Hash[i-1][0]) + ll(kor[i]) * ll(PowP[i-1][0])) % Mod1;
		Hash[i][1] = (ll(Hash[i-1][1]) + ll(kor[i]) * ll(PowP[i-1][1])) % Mod2;
	}
	for (int i=n; i>=1; i--) {
		HashRev[i][0] = (ll(HashRev[i+1][0]) + ll(kor[i]) * ll(PowP[n-i][0])) % Mod1;
		HashRev[i][1] = (ll(HashRev[i+1][1]) + ll(kor[i]) * ll(PowP[n-i][1])) % Mod2;
	}

	vector<int> res;
	int maxAmm = 0;

	for (int k=1; k<=n; k++) {
		int amm = DiffSlicesFor(k, n);
		if (amm > maxAmm) {
			maxAmm = amm;
			res = {k};
		} else if (amm == maxAmm) {
			res.pb(k);
		}
	}
	cout << maxAmm << ' ' << res.size() << '\n';
	for (int& k : res) {
		cout << k << ' ';
	}
	cout << '\n';

}
	
