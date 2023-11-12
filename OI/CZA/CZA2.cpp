#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
 
 
struct Char {
	int code = 0;
	bool vis=false;
	ll ind = -1;
};
 
map<string, int[26]> inputMap;
map<string, Char> sub;
 
int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
 
	string S, Added;
	int k;
	ll a,b, n;
 
	ll bestCurrent, bestSaved;
	string substring = "";

	int c;
	char in;

	substring.reserve(1e6);
	Added.reserve(1e6);
 
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
		sub[substring].ind = ind;

		if (a <= ind){
			cout << charToAdd;
			a++;
		}

		for (int i=0; i<k-1; i++)
			substring[i] = substring[i+1];
		substring[k-1] = charToAdd;
		Added += charToAdd;
	}

	ind -= 1;
	ll base = sub[substring].ind;

	for (ll i=a-base; i<=b-base; i++)
		cout << Added[base + i % (ind - base + 1)];
 
	cout << '\n';
}

