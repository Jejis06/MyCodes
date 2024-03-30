#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
 
 
struct Char {
	int code = 0;
	bool vis=false;
};
 
unordered_map<ll , unordered_map<int,int>> inputMap;
unordered_map<ll , Char> sub;
  
constexpr int length = 1e6 + 1;
const long long mod = 1e16 + 61;
long long BASE[length];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	BASE[0] = 1;
	BASE[1] = 31;

	for(int i = 2; i < length; ++i){
		BASE[i] = (BASE[i-1] * BASE[1]) % mod;
	}
 
	string S, pattern = "";
	int k;
	ll a,b, n;
 
	ll bestCurrent, bestSaved;

	int c;
	char in;

 
	cin >> n >> k >> a >> b >> S; 

	ll hash;
	string substring;
 
	for (int i=0; i<n-k; i++) {
		hash = 0;
		for (int j=1; j<=k; j++) 
			hash += BASE[j]  * (S[i + j - 1] - 96) % mod;

		c = S[i + k] - 97;
		bestCurrent = ++inputMap[hash][c];
		bestSaved = inputMap[hash][sub[hash].code];

 
		if ((bestSaved < bestCurrent) || (bestSaved == bestCurrent && sub[hash].code > c))
			sub[hash].code = c;

	}
 
	substring = "";
	for (int i=n-k; i<n; i++) 
		substring += S[i];
 
	ll ind=0;
	char charToAdd;
	a -= (n + 1);
	b -= (n + 1);
	for (; ind <= b; ind++) {
		hash = 0;
		for (int i=1; i<=k; i++)
			hash += BASE[i]  * (substring[i-1] - 96) % mod;
 
		charToAdd = char(sub[hash].code + 97);
 
		if (sub[hash].vis) break;
		sub[hash].vis = 1;


		if (a <= ind){
			cout << charToAdd;
			a++;
		}

		for (int i=0; i<k-1; i++)
			substring[i] = substring[i+1];
		substring[k-1] = charToAdd;
	}

	if (a > b) return 0;
	ll found = hash;

	for (int i=0; i<k-1; i++)
		substring[i] = substring[i+1];
	substring[k-1] = char(sub[hash].code + 97);

	hash = 0;
	pattern += substring[k-1];
	while (1) {
		hash = 0;
		for (int i=1; i<=k; i++)
			hash += BASE[i]  * (substring[i-1] - 96) % mod;
		charToAdd = char(sub[hash].code + 97);
		if (hash == found) break;
		pattern += charToAdd;


		for (int i=0; i<k-1; i++)
			substring[i] = substring[i+1];
		substring[k-1] = charToAdd;
	}

	ll base = ind - pattern.size();
	for (ll i=a-base; i<=b-base; i++){
		cout << pattern[i % pattern.size()];
	}
 
	cout << '\n';
}
