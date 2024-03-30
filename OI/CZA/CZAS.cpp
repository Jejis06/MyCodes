#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
 
 
struct Char {
	int code = 0;
	bool vis=false;
};
 
unordered_map<string , unordered_map<int,int>> inputMap;
unordered_map<string, Char> sub;
  
constexpr int length = 1e6 + 1;
const long long mod = 1e16 + 61;
long long BASE[length];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	string S, pattern = "";
	int k;
	ll a,b, n;
 
	ll bestCurrent, bestSaved;

	int c;
	char in;
	string  substring;
	substring.reserve(1e6);
 
	cin >> n >> k >> a >> b; 

 
	for (int j=0; j<k; j++){
		cin >> in;
		substring += in;
	} 

	for (int i=0; i<n-k; i++) {
 
		cin >> in;
		c = in - 97;
 
		bestCurrent = ++inputMap[substring][c];
		bestSaved = inputMap[substring][sub[substring].code];
 
		if ((bestSaved < bestCurrent) || (bestSaved == bestCurrent && sub[substring].code > c))
			sub[substring].code = c;

		substring.erase(0,1);
		substring += in;
	}

 
 
	ll ind=0;
	char charToAdd;
	a -= (n + 1);
	b -= (n + 1);
	for (; ind <= b; ind++) {
 
		charToAdd = char(sub[substring].code + 97);
 
		if (sub[substring].vis) break;
		sub[substring].vis = 1;


		if (a <= ind){
			cout << charToAdd;
			a++;
		}

		for (int i=0; i<k-1; i++)
			substring[i] = substring[i+1];
		substring[k-1] = charToAdd;
	}

	if (a > b) return 0;
	string found = substring;

	for (int i=0; i<k-1; i++)
		substring[i] = substring[i+1];
	substring[k-1] = char(sub[found].code + 97);

	pattern += substring[k-1];
	while (1) {
		charToAdd = char(sub[substring].code + 97);
		if (substring == found) break;
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


