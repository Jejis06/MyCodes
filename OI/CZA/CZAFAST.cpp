#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
 
 
struct Char {
	int code = 0;
	bool vis=false;
};
 
unordered_map<ll , int[26]/*unordered_map<int,int>*/> inputMap;
unordered_map<ll , Char> sub;
  
constexpr int length = 1e6 + 1;
constexpr ll mod = 1e9 + 7 ;
constexpr ll inv = 129032259;
constexpr ll p = 31;

ll BASE[length];

ll nextHash(ll hash, ll prev, ll next, int len){
	ll res = (hash - prev) % mod;
	if (res < 0) res += mod;

	res = (res * inv) % mod;
	res = (res + next * BASE[len-1]) % mod;
	return res;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

 
	string S, pattern = "";
	int k;
	ll a,b, n;
 
	ll bestCurrent, bestSaved;

	int c;
	char in;

 
	cin >> n >> k >> a >> b >> S; 

	BASE[0] = 1;
	for (int i=1; i<n; i++) 
		BASE[i] = (p * BASE[i-1]) % mod;

	ll hash = 0;
	string substring="";

	substring.reserve(1e6+1);
	pattern.reserve(1e6+1);
 
	for (int i=0; i<k; i++)
		hash = ((S[i] - 96) * BASE[i] + hash) % mod;

	for (int i=1; i<n-k; i++) {

		c = S[i + k] - 97;
		bestCurrent = ++inputMap[hash][c];
		bestSaved = inputMap[hash][sub[hash].code];

 
		if ((bestSaved < bestCurrent) || (bestSaved == bestCurrent && sub[hash].code > c))
			sub[hash].code = c;

		hash = nextHash(hash, S[i-1] - 96, S[i+k] - 96, k);

	}
 
	substring = "";
	hash = 0;
	for (int i=n-k; i<n; i++)  {
		substring += S[i];
		hash = ((S[i] - 96) * BASE[i-n+k] + hash) % mod;

	}
 
	ll ind=0;
	char charToAdd;
	a -= (n + 1);
	b -= (n + 1);
	for (; ind <= b; ind++) {
 
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

		hash = nextHash(hash, substring[0] - 96, S.back() - 96, k);
	}

	if (a > b) return 0;
	ll found = hash;

	for (int i=0; i<k-1; i++)
		substring[i] = substring[i+1];
	substring[k-1] = char(sub[hash].code + 97);

	hash = 0;
	for (int i=0; i<k; i++)
		hash = (hash +  BASE[i]  * (substring[i] - 96)) % mod;
	pattern += substring[k-1];
	while (1) {
		charToAdd = char(sub[hash].code + 97);
		if (hash == found) break;
		pattern += charToAdd;


		for (int i=0; i<k-1; i++)
			substring[i] = substring[i+1];
		substring[k-1] = charToAdd;
		hash = nextHash(hash, substring[0] - 96, S.back() - 96, k);
	}

	ll base = ind - pattern.size();
	for (ll i=a-base; i<=b-base; i++){
		cout << pattern[i % pattern.size()];
	}
 
	cout << '\n';
}


