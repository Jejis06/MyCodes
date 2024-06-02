#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> Para;

vector<Para> best1;
vector<Para> best2;
vector<Para> best3;


/* cuk.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d, p, r;
	cin >> n;

	ll baseRes = 0;
	int u1, u2, u3;

	u1 = u2 = u3 = 0;
	for (int i=1; i<=n; i++) {
		cin >> d >> p >> r;

		if (d > 0) u1 = 1;
		if (p > 0) u2 = 1;
		if (r > 0) u3 = 1;

		int maxForRow = max({d, p, r});
		baseRes += (d + p + r) - maxForRow;

		best1.pb({maxForRow - d, i});
		best2.pb({maxForRow - p, i});
		best3.pb({maxForRow - r, i});
	}

	sort(best1.begin() , best1.end());
	sort(best2.begin() , best2.end());
	sort(best3.begin() , best3.end());


	ll res = LLONG_MAX;
	ll currRes = 0;
	for (int id=0; id<3; id++){
		for (int ip=0; ip<3; ip++){
			for (int ir=0; ir<3; ir++){

				d = best1[id].second;
				p = best2[ip].second;
				r = best3[ir].second;

				if (d != p && d != r && p != r) {
					currRes = baseRes + u1*best1[id].first + u2*best2[ip].first + u3*best3[ir].first;
					res = min(currRes, res);
				}
			}
		}
	}
	cout << res;
}
	
