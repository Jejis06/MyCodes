#include <bits/stdc++.h>
using namespace std;


constexpr int mod = 1e9 + 7;
bool C[55];
map<vector<int>,int> M;
vector<int> znaki;

int convert(char x) {
	if(x>='a') return (int)x-71;
	else return (int)x-65;
}

/* magic.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; string s; long long ans=0;
	cin >> n >> s;

	for (int i=0; i<n; i++) 
		C[convert(s[i])] = 1;

	for (int i=0; i<52; i++)
		if (C[i]) znaki.push_back(i);

	vector<int> curr(znaki.size());
	vector<int> pref(znaki.size());

	M[curr]++;
	for (int i=0; i<n; i++) {
		int Min=n;

		for (int j=0; j<znaki.size(); j++) {
			if (znaki[j] == convert(s[i])) curr[j]++;
			Min = min(Min, curr[j]);
		}

		for (int j=0; j<znaki.size(); j++)
			pref[j] = curr[j] - Min;

		ans += M[pref];
		if (ans >= mod) ans -= mod;
		M[pref]++;

	}
	cout << ans << '\n';
}
	
