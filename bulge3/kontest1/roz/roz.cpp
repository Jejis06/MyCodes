#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int ALF = 27;
constexpr int N = 1e6 + 1;

int letters[ALF];
unordered_map<int,int[ALF]> pref;
char s[N];
/* roz.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> s[i];

	for (int k=0; k<26; k++)
		pref[0][k] = 0;
	for (int i=1; i<=n; i++) {
		for (int k=0; k<26; k++)
			pref[i][k] = pref[i-1][k];
		pref[i][s[i] - 97]++;
	}

	int res = 0;
	for (int i=1; i<=n-1; i++) {
		for (int j=i+1; j<=n; j++) {

			for (int k=0; k<26; k++)
				letters[k] = pref[j][k] - pref[i - 1][k];

			int MaxVal=0, MinVal=INT_MAX;
			for (int k=0; k<26; k++) {
				MaxVal = max(MaxVal, letters[k]);
				if (letters[k] > 0)
					MinVal = min(MinVal, letters[k]);

			}

			res = max(res, MaxVal - MinVal);

		}
	}
	cout << res << '\n';
	

}
	
